namespace Phalcon\Auth;

use Closure;
use InvalidArgumentException;
use Phalcon\Encryption\Security;
use Phalcon\Di\Di;
use Phalcon\Events\ManagerInterface as EventsManagerInterface;
use Phalcon\Http\Request;
use Phalcon\Http\Response\Cookies;
use Phalcon\Session\ManagerInterface as SessionManagerInterface;
use Phalcon\Auth\Adapter\AdapterInterface;
use Phalcon\Auth\Guard\GuardInterface;
use Phalcon\Auth\Guard\Session;
use Phalcon\Auth\Guard\Token;
use Phalcon\Events\EventsAwareInterface;

class ManagerFactory extends Manager implements EventsAwareInterface
{
    protected config;
    protected security;
    protected customGuards = [];
    protected customAdapters = [];

    protected session;
    protected cookies;
    protected request;
    protected eventsManager;

    public function __construct(
        array config = [],
        <Security> security = null,
        <SessionManagerInterface> session = null,
        <Cookies> cookies = null,
        <Request> request = null,
        <EventsManagerInterface> eventsManager = null
    )
    {
        let this->config = config;

        if empty(this->config) {
            var authConfig;

            let authConfig = Di::getDefault()->getShared("config")->get("auth");

            if empty(authConfig) {
                throw new InvalidArgumentException(
                    "Configuration file auth.php (or key config->auth into your config) does not exist"
                );
            }

            let this->config = authConfig->toArray();
        }

        var service, nameService;
        array services;

        let services = [
            "security": security,
            "session": session,
            "cookies": cookies,
            "request": request,
            "eventsManager": eventsManager
        ];

        for nameService, service in services {
            let this->{nameService} = service;

            if this->{nameService} === null {
                let this->{nameService} = Di::getDefault()->getShared(nameService);
            }
        }
    }

    protected function getConfigGuard(string name) -> array | null
    {
        return this->config["guards"][name];
    }

    public function guard(var name = null) -> <GuardInterface>
    {
        let name = name ? name : this->getDefaultGuardName();

        if !isset(this->guards[name]) {
            let this->guards[name] = this->resolve(name);
        }

        return this->guards[name];
    }

    protected function resolve(string nameGuard)
    {
        var configGuard;

        let configGuard = this->getConfigGuard(nameGuard);

        if configGuard === null {
            throw new InvalidArgumentException("Auth guard [" . nameGuard . "] is not defined.");
        }

        var providerAdapter = this->getAdapterProvider(configGuard["provider"]);

        if (isset(this->customGuards[configGuard["driver"]])) {
            return call_user_func(
                this->customGuards[configGuard["driver"]],
                providerAdapter,
                configGuard
            );
        }

        if configGuard["driver"] === "token" {
            if !isset(configGuard["inputKey"]) {
                let configGuard["inputKey"] = "auth_token";
            }

            if !isset(configGuard["storageKey"]) {
                let configGuard["storageKey"] = "auth_token";
            }

            return new Token(
                providerAdapter,
                configGuard,
                this->request
            );
        }

        if configGuard["driver"] === "session" {
             return new Session(
                providerAdapter,
                this->session,
                this->cookies,
                this->request,
                this->eventsManager
            );
        }


        throw new InvalidArgumentException(
            "Auth driver [" . configGuard["driver"] ."] for guard [".nameGuard."] is not defined."
        );
    }

    public function getAdapterProvider(string provider = null)
    {
        var configProvider;
        let configProvider = this->config["providers"][provider];

        if configProvider === null {
             throw new InvalidArgumentException(
                "Config adapter '" . provider . "' not defined"
             );
        }

        var adapterName = configProvider["adapter"];

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

        return adapter;
    }

    public function getDefaultGuardName() -> string
    {
        return this->config["defaults"]["guard"];
    }

    public function extendGuard(driver, <Closure> callback) -> <ManagerInterface>
    {
        let this->customGuards[driver] = callback;

        return this;
    }

    public function extendProviderAdapter(string name, <Closure> callback) -> <ManagerInterface>
    {
        let this->customAdapters[name] = callback;

        return this;
    }

    public function getEventsManager() -> <EventsManagerInterface> | null
    {
        return this->eventsManager;
    }

    public function setEventsManager(<EventsManagerInterface> eventsManager) -> void
    {
        let this->eventsManager = eventsManager;
    }
}