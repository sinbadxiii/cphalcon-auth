namespace Phalcon\Auth\Guards;

use Phalcon\Auth\Events\EventInterface;
use Phalcon\Support\Helper\Str\StartsWith;
use Phalcon\Auth\AuthenticatableInterface;
use Phalcon\Di\Di;

class TokenGuard implements GuardInterface
{
    protected name;
    protected eventsManager;
    protected request;
    protected inputKey;
    protected storageKey;
    protected provider;
    protected user;

    public function __construct(name, provider, inputKey = "auth_token", storageKey = "auth_token")
    {
        let this->name           = name;
        let this->provider       = provider;
        let this->eventsManager  = Di::getDefault()->getShared("eventsManager");
        let this->request        = Di::getDefault()->getShared("request");
        let this->inputKey       = inputKey;
        let this->storageKey     = storageKey;
    }

    public function user()
    {
        if this->user !== null {
            return this->user;
        }
        var user = null;

        var token = this->getTokenForRequest();

        if  !empty(token) {
            let user = this->provider->retrieveByCredentials([
                this->storageKey: token
            ]);
        }

        let this->user = user;

        return user;
    }

    public function validate(array credentials = [])
    {
        if empty credentials[this->inputKey] {
            return false;
        }

        let credentials = [this->storageKey: credentials[this->inputKey]];

        if this->provider->retrieveByCredentials(credentials) {
            return true;
        }

        return false;
    }

    public function event(<EventInterface> event)
    {
        return this->eventsManager->fire("auth:" . event->getType(), this);
    }

    public function getTokenForRequest()
    {
        var token = this->request->get(this->inputKey);

        if empty token {
            let token = this->bearerToken();
        }

        return token;
    }

    private function bearerToken()
    {
        var header = this->request->getHeader("Authorization");

        var helper;
        let helper = new StartsWith();
        if {helper}(header, "Bearer ") {
            return mb_substr(header, 7, null, "UTF-8");
        }
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

    public function check()
    {
        return this->user() !== null;
    }

    public function hasUser()
    {
        return this->user !== null;
    }

    public function guest()
    {
        return ! this->check();
    }

    public function authenticate()
    {
        var user;
        let user = this->user();

        if user !== null {
            return user;
        }
    }
}