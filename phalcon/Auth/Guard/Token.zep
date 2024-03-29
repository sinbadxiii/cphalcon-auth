namespace Phalcon\Auth\Guard;

use Phalcon\Http\Request;
use Phalcon\Support\Helper\Str\StartsWith;
use Phalcon\Auth\Adapter\AdapterInterface;
use Phalcon\Auth\AuthenticatableInterface;
use Phalcon\Di\Di;

class Token implements GuardInterface
{
    protected request;
    protected inputKey;
    protected storageKey;
    protected adapter;
    protected user;

    public function __construct(<AdapterInterface> adapter, array config, <Request> request)
    {
        let this->adapter        = adapter;
        let this->request        = request;
        let this->inputKey       = config["inputKey"];
        let this->storageKey     = config["storageKey"];
    }

    public function user()
    {
        if this->user !== null {
            return this->user;
        }
        var user = null;

        var token = this->getTokenForRequest();

        if  !empty(token) {
            let user = this->adapter->retrieveByCredentials([
                this->storageKey: token
            ]);
        }

        let this->user = user;

        return user;
    }

    public function validate(array credentials = []) -> bool
    {
        if empty credentials[this->inputKey] {
            return false;
        }

        let credentials = [this->storageKey: credentials[this->inputKey]];

        if this->adapter->retrieveByCredentials(credentials) {
            return true;
        }

        return false;
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

    public function setRequest(<Request> request)
    {
        let this->request = request;

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
        var user;
        let user = this->user();

        if user !== null {
            return user;
        }
    }
}