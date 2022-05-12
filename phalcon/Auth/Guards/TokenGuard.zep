namespace Phalcon\Auth\Guards;

use Phalcon\Http\Request;
use Phalcon\Auth\Contracts\BasicAuth;
use Phalcon\Auth\Guards\GuardStatefulInterface;
use Phalcon\Auth\Events\AfterLogin;
use Phalcon\Auth\Events\BeforeLogin;
use Phalcon\Auth\Events\EventInterface;
use Phalcon\Auth\Events\Logout;
use Phalcon\Auth\AuthenticatableInterface;

use is_null;

//class SessionGuard implements GuardStateful, BasicAuth
class TokenGuard
{
//    use GuardHelper;
//    use BasicHelper;
//
    protected name;
    protected session;
    protected cookies;
    protected eventsManager;
    protected request;
    protected lastUserAttempted;

    protected viaRemember = false;
    protected provider;

    protected di;

    public function __construct(var name, var provider)
    {
        let this->name     = $name;
        let  this->provider = $provider;
//
//        var di;
//        let  di = class_exists("\\Phalcon\\Di") ? new \Phalcon\Di : new \Phalcon\Di\Di;
//
//        let  this->di = $di;
//        let  this->session        = this->di::getDefault()->getShared("session");
//        let  this->cookies        = this->di::getDefault()->getShared("cookies");
//        let  this->eventsManager  = this->di::getDefault()->getShared("eventsManager");
//        let  this->request        = this->getRequest();
    }

    public function print()-> string
    {
        return "222";
    }

//
//    public function attempt(array $credentials = [], $remember = false)
//    {
//        $this->lastUserAttempted = $this->provider->retrieveByCredentials($credentials);
//
//        if ($this->hasValidCredentials($this->lastUserAttempted, $credentials)) {
//            $this->login($this->lastUserAttempted, $remember);
//
//            return true;
//        }
//
//        return false;
//    }
//
//    public function user()
//    {
//        if (!is_null($this->user)) {
//            return $this->user;
//        }
//
//        $id = $this->session->get($this->getName());
//
//        if (!is_null($id)) {
//            $this->user = $this->provider->retrieveById($id);
//        }
//
//        if (is_null($this->user) && !is_null($recaller = $this->recaller())) {
//            $this->user = $this->userFromRecaller($recaller);
//
//            if ($this->user) {
//                $this->updateSession($this->user->getAuthIdentifier());
//            }
//        }
//
//        return $this->user;
//    }
//
//    protected function hasValidCredentials($user, $credentials)
//    {
//        return !is_null($user) && $this->provider->validateCredentials($user, $credentials);
//    }
//
//    public function validate(array $credentials = [])
//    {
//        $this->lastUserAttempted = $this->provider->retrieveByCredentials($credentials);
//
//        return $this->hasValidCredentials($this->lastUserAttempted, $credentials);
//    }
//
//    protected function userFromRecaller($recaller)
//    {
//        $this->viaRemember = ! is_null($user = $this->provider->retrieveByToken(
//            $recaller->id(), $recaller->token(), $recaller->userAgent()
//        ));
//
//        return $user;
//    }
//
//    protected function recaller()
//    {
//        if ($recaller = $this->getRememberData()) {
//            return new UserRemember($recaller);
//        }
//    }
//
//    protected function getRememberData()
//    {
//        if ($this->cookies->has($this->getRememberName())) {
//            return $this->cookies->get($this->getRememberName())->getValue();
//        }
//    }
//
//    public function getName()
//    {
//        return "auth_{$this->name}_" . sha1(static::class);
//    }
//
//    public function getRememberName()
//    {
//        return "remember_{$this->name}_" . sha1(static::class);
//    }
//
//    public function login(AuthenticatableInterface $user, $remember = false)
//    {
//        $this->event(new BeforeLogin());
//
//        $this->updateSession($user->getAuthIdentifier());
//
//        if ($remember) {
//            $this->rememberUser($user);
//        }
//
//        $this->setUser($user);
//
//        $this->event(new AfterLogin());
//    }
//
//    public function loginById($id, $remember = false)
//    {
//        if ( ! is_null($user = $this->provider->retrieveById($id))) {
//            $this->login($user, $remember);
//
//            return $user;
//        }
//
//        return false;
//    }
//
//    public function once(array $credentials = [])
//    {
//        $this->event(new BeforeLogin());
//
//        if ($this->validate($credentials)) {
//            $this->setUser($this->lastUserAttempted);
//
//            $this->event(new AfterLogin());
//
//            return true;
//        }
//
//        return false;
//    }
//
//    protected function rememberUser(AuthenticatableInterface $user)
//    {
//        $rememberToken = $this->createRememberToken($user);
//
//        if (!is_null($rememberToken)) {
//            $this->cookies->set($this->getRememberName(),
//                json_encode([
//                    'id'         => $user->getAuthIdentifier(),
//                    'token'      => $rememberToken->token,
//                    'user_agent' => $this->request->getUserAgent()
//                ], JSON_THROW_ON_ERROR),
//                date("U") + 360 * 24 * 60 * 60
//            );
//        }
//    }
//
//    protected function createRememberToken(AuthenticatableInterface $user)
//    {
//        return $this->provider->createRememberToken($user);
//    }
//
//    protected function updateSession($id)
//    {
//        $this->session->set($this->getName(), $id);
//    }
//
//    public function logout()
//    {
//        $user = $this->user();
//
//        if ($this->user && ($tokenRemember = $this->user->getRememberToken())) {
//            $tokenRemember->delete();
//        }
//
//        $this->session->remove($this->getName());
//
//        if (! is_null($this->recaller())) {
//            $this->cookies->get($this->getRememberName())->delete();
//        }
//
//        $this->event(new Logout($user));
//
//        $this->user = null;
//    }
//
//    public function getLastUserAttempted()
//    {
//        return $this->lastUserAttempted;
//    }
//
//    public function event(EventInterface $event)
//    {
//        return $this->eventsManager->fire("auth:" . $event->getType(), $this);
//    }
//
//    public function viaRemember()
//    {
//        return $this->viaRemember;
//    }
//
//    public function getUser()
//    {
//        return $this->user;
//    }
//
//    public function getRequest(): Request
//    {
//        return $this->request ?: $this->di::getDefault()->getShared("request");
//    }
//
//    public function setRequest(Request $request)
//    {
//        $this->request = $request;
//
//        return $this;
//    }
}