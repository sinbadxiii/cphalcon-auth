namespace Phalcon\Auth\Guards;

use Phalcon\Http\Request;
use Phalcon\Auth\Events\AfterLogin;
use Phalcon\Auth\Events\BeforeLogin;
use Phalcon\Auth\Events\EventInterface;
use Phalcon\Auth\Events\Logout;
use Phalcon\Auth\AuthenticatableInterface;
use Phalcon\Helper\Str;
use Phalcon\Http\Request;
use Phalcon\Auth\Exceptions\UnauthorizedHttpException;
use Phalcon\Di\Di;

use is_null;

class SessionGuard implements GuardStatefulInterface, BasicAuthInterface
{
    protected name;
    protected session;
    protected cookies;
    protected eventsManager;
    protected request;
    protected lastUserAttempted;

    protected viaRemember = false;
    protected provider;

    protected di;
    protected user;

    public function __construct(var name, var provider)
    {
        let  this->name     = name;
        let  this->provider = provider;

        let  this->session        = Di::getDefault()->getShared("session");
        let  this->cookies        = Di::getDefault()->getShared("cookies");
        let  this->eventsManager  = Di::getDefault()->getShared("eventsManager");
        let  this->request        = this->getRequest();
    }

    public function attempt(array credentials = [], bool remember = false)
    {
        let this->lastUserAttempted = this->provider->retrieveByCredentials(credentials);

        if (this->hasValidCredentials(this->lastUserAttempted, credentials)) {
            this->login(this->lastUserAttempted, remember);

            return true;
        }

        return false;
    }

    public function user()
    {
        if (!is_null(this->user)) {
            return this->user;
        }

        var id;
        let id = this->session->get(this->getName());

        if (!is_null(id)) {
            let this->user = this->provider->retrieveById(id);
        }

        var recaller;
        let recaller = this->recaller();
        if (is_null(this->user) && !is_null(recaller)) {
            let this->user = this->userFromRecaller(recaller);

            if (this->user) {
                this->updateSession(this->user->getAuthIdentifier());
            }
        }

        return this->user;
    }

    protected function hasValidCredentials(var user, array credentials)
    {
        return !is_null(user) && this->provider->validateCredentials(user, credentials);
    }

    public function validate(array credentials = [])
    {
        let this->lastUserAttempted = this->provider->retrieveByCredentials(credentials);

        return this->hasValidCredentials(this->lastUserAttempted, credentials);
    }

    protected function userFromRecaller(recaller)
    {
        var user;
        let user = this->provider->retrieveByToken(
            recaller->id(), recaller->token(), recaller->userAgent()
        );

        let $this->viaRemember = ! is_null(user);

        return $user;
    }

    protected function recaller()
    {
        var recaller;
        let recaller = this->getRememberData();

        if (recaller) {
            return new UserRemember(recaller);
        }
    }

    protected function getRememberData()
    {
        if (this->cookies->has(this->getRememberName())) {
            return this->cookies->get(this->getRememberName())->getValue();
        }
    }

    public function getName() -> string
    {
        return sprintf("auth_%s_%s", this->name, sha1(get_class(this)));
    }

    public function getRememberName() -> string
    {
        return sprintf("auth_%s_%s", this->name, sha1(get_class(this)));
    }

    public function login(<AuthenticatableInterface> user, bool remember = false)
    {
        this->event(new BeforeLogin());

        this->updateSession(user->getAuthIdentifier());

        if (remember) {
            this->rememberUser(user);
        }

        this->setUser(user);

        this->event(new AfterLogin());
    }

    public function loginById(var id, bool remember = false)
    {
        var user;
        let user = this->provider->retrieveById(id);
        if ( ! is_null(user)) {
            this->login(user, remember);

            return user;
        }

        return false;
    }

    public function once(array credentials = [])
    {
        this->event(new BeforeLogin());

        if (this->validate(credentials)) {
            this->setUser(this->lastUserAttempted);

            this->event(new AfterLogin());

            return true;
        }

        return false;
    }

    protected function rememberUser(<AuthenticatableInterface> user)
    {
        var rememberToken = this->createRememberToken(user);

        if (!is_null(rememberToken)) {
            this->cookies->set(this->getRememberName(),
                json_encode([
                      "id"         : user->getAuthIdentifier(),
                      "token"      : rememberToken->token,
                      "user_agent" : this->request->getUserAgent()
                  ], JSON_THROW_ON_ERROR),
                date("U") + 360 * 24 * 60 * 60
            );
        }
    }

    protected function createRememberToken(<AuthenticatableInterface> user)
    {
        return this->provider->createRememberToken(user);
    }

    protected function updateSession(int id)
    {
        this->session->set(this->getName(), id);
    }

    public function logout()
    {
        var user = this->user();
        var recaller = this->recaller();
        if (!is_null(recaller)) {
            var token = recaller->token();
            var tokenRemember = user->getRememberToken(token);

            if tokenRemember {
                tokenRemember->delete();
            }
        }

        this->session->remove(this->getName());

        if (! is_null(this->recaller())) {
            this->cookies->get(this->getRememberName())->delete();
        }

        this->event(new Logout(user));

        let this->user = null;
    }

    public function getLastUserAttempted()
    {
        return this->lastUserAttempted;
    }

    public function event(<EventInterface> event)
    {
        return this->eventsManager->fire("auth:" . event->getType(), this);
    }

    public function viaRemember()
    {
        return this->viaRemember;
    }

    public function getUser()
    {
        return this->user;
    }

    public function getRequest() -> <Request>
    {
        return this->request ? this->request : Di::getDefault()->getShared("request");
    }

    public function setRequest(<Request> request)
    {
        let this->request = request;

        return this;
    }

    public function basic(string field = "email", array extraConditions = [])
    {
        if (this->check()) {
            return true;
        }

        if (this->attemptBasic(this->getRequest(), field, extraConditions)) {
            return true;
        }

        this->failedBasicResponse();
    }

    protected function attemptBasic(<Request> request, string field, array extraConditions = [])
    {
        if (! request->getBasicAuth()) {
            return false;
        }

        return this->attempt(array_merge(
            this->basicCredentials(request, field), extraConditions
        ));
    }

    protected function failedBasicResponse() -> <UnauthorizedHttpException>
    {
       throw new UnauthorizedHttpException("Basic: Invalid credentials.");
    }

    protected function basicCredentials(<Request> request, string field)
    {
        return [
            field: this->userFromBasic(request),
            "password":  this->passwordFromBasic(request)
        ];
    }

    public function onceBasic(string field = "email", array extraConditions = [])
    {
        var credentials;
        let credentials = this->basicCredentials(this->getRequest(), field);

        if (this->once(array_merge(credentials, extraConditions))) {
            return this->getUser();
        }

        this->failedBasicResponse();
    }

    private function userFromBasic(<Request> request)
    {
        return request->getBasicAuth()["username"];
    }

    private function passwordFromBasic(request)
    {
        return request->getBasicAuth()["password"];
    }

    public function id()
    {
        if (this->user()) {
            return this->user()->getAuthIdentifier();
        }
    }

    public function setUser(<AuthenticatableInterface> user)
    {
        let this->user = user;

        return this;
    }

    public function check()
    {
        return !is_null(this->user());
    }

    public function hasUser()
    {
        return !is_null(this->user);
    }

    public function guest()
    {
        return ! this->check();
    }

    public function authenticate()
    {
        var user;
        let user = this->user();

        if (!is_null(user)) {
            return user;
        }
    }
}