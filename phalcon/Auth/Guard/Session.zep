namespace Phalcon\Auth\Guard;

use Phalcon\Events\AbstractEventsAware;
use Phalcon\Http\Response\Cookies;
use Phalcon\Http\Request;
use Phalcon\Auth\AuthenticatableInterface;
use Phalcon\Auth\Adapter\AdapterInterface;
use Phalcon\Auth\Adapter\AdapterWithRememberTokenInterface;
use InvalidArgumentException;
use Phalcon\Di\Di;
use Phalcon\Auth\RememberTokenInterface;
use Phalcon\Session\ManagerInterface as SessionManagerInterface;
use Phalcon\Events\ManagerInterface as EventsManagerInterface;

class Session extends AbstractEventsAware implements
        GuardInterface, GuardStatefulInterface, BasicAuthInterface
{
    protected session;
    protected cookies;
    protected request;
    protected eventsManager;
    protected lastUserAttempted;

    protected viaRemember = false;
    protected adapter;

    protected user;

    public function __construct(
        <AdapterInterface> adapter, <SessionManagerInterface> session,
        <Cookies> cookies, <Request> request, <EventsManagerInterface> eventsManager
    )
    {
        let  this->adapter        = adapter;
        let  this->session        = session;
        let  this->cookies        = cookies;
        let  this->request        = request;
        let  this->eventsManager  = eventsManager;
    }

    public function attempt(array credentials = [], bool remember = false) -> bool
    {
        let this->lastUserAttempted = this->adapter->retrieveByCredentials(credentials);

        if this->hasValidCredentials(this->lastUserAttempted, credentials) {
            this->login(this->lastUserAttempted, remember);

            return true;
        }

        return false;
    }

    public function user()
    {
        if this->user !== null {
            return this->user;
        }

        var id, recaller;

        let id = this->session->get(this->getName());
        if id !== null {
            let this->user = this->adapter->retrieveById(id);
        }

        let recaller = this->recaller();
        if this->user !== null && recaller !== null {
            let this->user = this->userFromRecaller(recaller);

            if this->user {
                this->updateSession(this->user->getAuthIdentifier());
            }
        }

        return this->user;
    }

    protected function hasValidCredentials(var user, array credentials) -> bool
    {
        return user !== null && this->adapter->validateCredentials(user, credentials);
    }

    public function validate(array credentials = []) -> bool
    {
        let this->lastUserAttempted = this->adapter->retrieveByCredentials(credentials);

        return this->hasValidCredentials(this->lastUserAttempted, credentials);
    }

    protected function userFromRecaller(recaller) -> <AuthenticatableInterface> | null
    {
        var user;
        let user = this->adapter->retrieveByToken(
            recaller->id(), recaller->token(), recaller->userAgent()
        );

        let this->viaRemember = user !== null;

        return user;
    }

    protected function recaller()
    {
        var recaller;
        let recaller = this->getRememberData();

        if recaller {
            return new UserRemember(recaller);
        }
    }

    protected function getRememberData()
    {
        if this->cookies->has(this->getRememberName()) {
            return this->cookies->get(this->getRememberName())->getValue();
        }
    }

    public function getName() -> string
    {
        return sprintf("auth_%s", sha1(get_class(this) . get_class(this->adapter)));
    }

    public function getRememberName() -> string
    {
        return sprintf("remember_%s", sha1(get_class(this) . get_class(this->adapter)));
    }

    public function login(<AuthenticatableInterface> user, bool remember = false) -> void
    {
        this->eventsManager->fire("auth:beforeLogin", this);

        this->updateSession(user->getAuthIdentifier());

        if remember {
            if !(this->adapter instanceof AdapterWithRememberTokenInterface) {
                throw new InvalidArgumentException(
                    "Adapter " . get_class(this->adapter) . " not instanceof AdapterWithRememberTokenInterface"
                );
             }

            this->rememberUser(user);
        }

        this->setUser(user);

        this->eventsManager->fire("auth:afterLogin", this);
    }

    public function loginById(var id, bool remember = false)
    {
        var user;
        let user = this->adapter->retrieveById(id);
        if user !== null {
            this->login(user, remember);

            return user;
        }

        return false;
    }

    public function once(array credentials = []) -> bool
    {
        this->eventsManager->fire("auth:beforeLogin", this);

        if this->validate(credentials) {
            this->setUser(this->lastUserAttempted);

            this->eventsManager->fire("auth:afterLogin", this);

            return true;
        }

        return false;
    }

    protected function rememberUser(<AuthenticatableInterface> user)
    {
        var rememberToken = this->createRememberToken(user);

        if rememberToken !== null {
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

    protected function createRememberToken(<AuthenticatableInterface> user) -> <RememberTokenInterface>
    {
        return this->adapter->createRememberToken(user);
    }

    protected function updateSession(var id) -> void
    {
        this->session->set(this->getName(), id);
    }

    public function logout()
    {
        var user = this->user();

        this->eventsManager->fire("auth:beforeLogout", this, [
           "user": user
        ]);

        var recaller = this->recaller();
        if recaller !== null {
            var token = recaller->token();
            var tokenRemember = user->getRememberToken(token);

            if tokenRemember {
                tokenRemember->delete();
            }

            this->cookies->get(this->getRememberName())->delete();
        }

        this->session->remove(this->getName());

        this->eventsManager->fire("auth:afterLogout", this, [
            "user": user
        ]);

        let this->user = null;
    }

    public function getLastUserAttempted()
    {
        return this->lastUserAttempted;
    }

    public function viaRemember() -> bool
    {
        return this->viaRemember;
    }

    public function getUser()
    {
        return this->user;
    }

    public function setRequest(<Request> request)
    {
        let this->request = request;

        return this;
    }

    public function setSession(<SessionManagerInterface> session)
    {
        let this->session = session;

        return this;
    }

    public function setCookies(<Cookies> cookies)
    {
        let this->cookies = cookies;

        return this;
    }

    public function getAdapter() -> <AdapterInterface>
    {
        return this->adapter;
    }

    public function setAdapter(<AdapterInterface> adapter)
    {
        let this->adapter = adapter;

        return this;
    }

    public function basic(string field = "email", array extraConditions = []) -> bool
    {
        if this->check() {
            return true;
        }

        if this->attemptBasic(this->request, field, extraConditions) {
            return true;
        }

        return false;
    }

    protected function attemptBasic(<Request> request, string field, array extraConditions = []) -> bool
    {
        if ! request->getBasicAuth() {
            return false;
        }

        return this->attempt(array_merge(
            this->basicCredentials(request, field), extraConditions
        ));
    }

    protected function basicCredentials(<Request> request, string field) -> array
    {
        return [
            field: this->userFromBasic(request),
            "password":  this->passwordFromBasic(request)
        ];
    }

    public function onceBasic(string field = "email", array extraConditions = [])
    {
        var credentials;
        let credentials = this->basicCredentials(this->request, field);

        if this->once(array_merge(credentials, extraConditions)) {
            return this->getUser();
        }

        return false;
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
        if this->user() {
            return this->user()->getAuthIdentifier();
        }
    }

    public function setUser(<AuthenticatableInterface> user)
    {
        let this->user = user;

        return this;
    }

    public function check() -> bool
    {
        return this->user() !== null;
    }

    public function hasUser() -> bool
    {
        return this->user !== null;
    }

    public function guest() -> bool
    {
        return ! this->check();
    }

    public function authenticate()
    {
        var user = this->user();

        if user !== null {
            return user;
        }
    }
}