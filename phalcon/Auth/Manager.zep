
namespace Phalcon\Auth;

use Closure;
use InvalidArgumentException;
use Phalcon\Config;
use Phalcon\Di\Di;
use Phalcon\Config\ConfigInterface;
use Phalcon\Auth\Guards\SessionGuard;
use Phalcon\Auth\Guards\TokenGuard;
use Phalcon\Auth\Providers\ModelProvider;
use Phalcon\Auth\Exceptions\ConfigFileNotExistException;

use is_null;

class Manager
{
    protected config;
    protected security;

//    protected customGuards = [];
    protected guards = [];

    public function __construct(<ConfigInterface> config = null, security = null)
    {
        if is_null(config) {
            let this->config = Di::getDefault()->getShared("config")->auth;

            if (is_null(this->config)) {
                throw new ConfigFileNotExistException();
            }
        }

        if is_null(security) {
            let this->security = Di::getDefault()->getShared("security");
        }
    }

    protected function getConfigGuard(string name)
    {
        return this->config->guards->{name};
    }

    public function guard(string name = null)
    {
        let name = name ?: this->getDefaultDriver();

        if is_null(this->guards[name]) {
            let this->guards[name] = this->resolve(name);
        }

        return this->guards[name];
    }

    protected function resolve(string name)
    {
        var configGuard;

        let configGuard = this->getConfigGuard(name);

        if (is_null(configGuard)) {
            throw new InvalidArgumentException(sprintf("Auth guard [%s] is not defined.", name));
        }

//        if (isset(this->customGuards[configGuard["driver"]])) {
//            return this->callCustomGuard(name, configGuard);
//        }

        var provider;
        let provider = this->createProvider(configGuard);

        var guard;

        if (configGuard->driver == "session") {
            let guard = new SessionGuard(name, provider);
        }

        if (configGuard->driver == "token") {
            let guard = new TokenGuard(name, provider);
        }

        if (configGuard->driver !== "session" && configGuard->driver !== "token") {
             throw new InvalidArgumentException(
                        sprintf(
                            "Auth driver %s for guard %s is not defined.",
                            configGuard->driver, name
                        )
              );
        }

        return guard;
    }

    public function createProvider(configGuard = null)
    {
        var driver;
        var provider = configGuard->provider;

        if this->config->providers->{provider}->driver == "model" {
            let driver = new ModelProvider(this->security, this->config->providers->{provider});
        }

        return driver;
    }

    public function getDefaultDriver()
    {
        return this->config->defaults->guard;
    }

//    public function extend(driver, <Closure> callback)
//    {
//        let this->customGuards[driver] = callback;
//
//        return this;
//    }

//    protected function callCustomGuard(string name, <Config> config)
//    {
//        var customGuard;
//        let customGuard = this->customGuards[config["driver"]];
//        return customGuard(name, config);
//    }

    public function __call(method, params)
    {
        return call_user_func_array(
            [this->guard(), method],
            params
        );
    }
}