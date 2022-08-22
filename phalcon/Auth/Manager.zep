namespace Phalcon\Auth;

use Closure;
use InvalidArgumentException;
use Phalcon\Encryption\Security;
use Phalcon\Di\Di;
use Phalcon\Config\ConfigInterface;
use Phalcon\Auth\Guards\SessionGuard;
use Phalcon\Auth\Guards\TokenGuard;
use Phalcon\Auth\Providers\ModelProvider;
use Phalcon\Auth\Access\AccessInterface;
use Phalcon\Auth\Adapter\AdapterInterface;
use Phalcon\Auth\Guard\GuardInterface;

class Manager implements ManagerInterface
{
    protected config;
    protected security;
    protected customGuards = [];
    protected customAdapters = [];
    protected guards = [];
    protected access = null;
    protected accessList = [];

    public function __construct(<ConfigInterface> config = null, <Security> security = null)
    {
        let this->config = config;

        if config === null {
            let this->config = Di::getDefault()->getShared("config")->get("auth");
        }

        if this->config === null {
            throw new InvalidArgumentException(
                "Configuration file auth.php (or key config->auth into your config) does not exist"
            );
        }

        let this->security = security;

        if this->security === null {
            let this->security = Di::getDefault()->getShared("security");
        }
    }

    protected function getConfigGuard(string name) -> <ConfigInterface> | null
    {
        return this->config->guards->{name};
    }

    public function guard(var name = null) -> <GuardInterface>
    {
        let name = name ? name : this->getDefaultDriver();

        if !isset(this->guards[name]) {
            let this->guards[name] = this->resolve(name);
        }

        return this->guards[name];
    }

    protected function resolve(string name)
    {
        var configGuard;

        let configGuard = this->getConfigGuard(name);

        if configGuard === null {
            throw new InvalidArgumentException("Auth guard [" . name . "] is not defined.");
        }

        var providerAdapter = this->getAdapterProvider(configGuard->provider);

        if (isset(this->customGuards[configGuard->driver])) {
            return call_user_func(
                this->customGuards[configGuard->driver],
                providerAdapter,
                configGuard,
                name
            );
        }

        var guardName = sprintf(
            "\\Phalcon\\Auth\\Guard\\%s", ucfirst(configGuard->driver)
        );

        if (!class_exists(guardName)) {
            throw new InvalidArgumentException(
                "Auth driver " . configGuard->driver ." for guard " . name . " is not defined."
            );
        }

        return new {guardName}(providerAdapter, configGuard, name);
    }

    public function getAdapterProvider(string provider = null)
    {
        var configProvider;
        let configProvider = this->config->providers->{provider};

        if configProvider === null {
            return;
        }

        var adapterName = configProvider->adapter;

        if adapterName === null {
            throw new InvalidArgumentException(
                "Adapter not assigned in config->auth->providers->" . provider . "->adapter = ?"
            );
        }

        if (isset(this->customAdapters[adapterName])) {
            return call_user_func(
                this->customAdapters[adapterName],
                this->security,
                configProvider
            );
        }

        var adapterClass = sprintf("\\Phalcon\\Auth\\Adapter\\%s",
            ucfirst(adapterName)
        );

         if (!class_exists(adapterClass)) {
            throw new InvalidArgumentException(
                sprintf("%s not found.", adapterClass)
            );
        }

        var adapter;
        let adapter = new {adapterClass}(this->security, configProvider);

        if !(adapter instanceof AdapterInterface) {
            throw new InvalidArgumentException(adapterClass . " not implementing AdapterInterface");
        }

        if !(adapter instanceof AdapterInterface) {
            throw new InvalidArgumentException(adapterClass . " not implementing AdapterInterface");
        }

        return adapter;
    }

    public function getDefaultDriver() -> string
    {
        return this->config->defaults->guard;
    }

    public function addGuard(driver, <Closure> callback) -> <ManagerInterface>
    {
        let this->customGuards[driver] = callback;

        return this;
    }

    public function addProviderAdapter(string name, <Closure> callback) -> <ManagerInterface>
    {
        let this->customAdapters[name] = callback;

        return this;
    }

    public function getAccess() -> <AccessInterface> | null
    {
        return this->access;
    }

    public function setAccess(<AccessInterface> access) -> <ManagerInterface>
    {
        let this->access = access;

        return this;
    }

    public function setAccessList(array accessList) -> <ManagerInterface>
    {
        let this->accessList = accessList;

        return this;
    }

    public function addAccessList(array accessList) -> <ManagerInterface>
    {
        let this->accessList += accessList;

        return this;
    }

    public function access(string accessName) -> <AccessInterface> | null
    {
        if !isset(this->accessList[accessName]) || !class_exists(this->accessList[accessName]) {
            throw new InvalidArgumentException(
                sprintf("Access with '%s' name is not included in the access list", accessName)
            );
        }

        var access = this->accessList[accessName];

        let this->access = new {access};

        return this->access;
    }

    public function __call(method, params)
    {
        return call_user_func_array(
            [this->guard(), method],
            params
        );
    }
}