
namespace Phalcon\Auth;

use Closure;
use InvalidArgumentException;
use Phalcon\Di\Di;
use Phalcon\Config\ConfigInterface;
use Phalcon\Auth\Guards\SessionGuard;
use Phalcon\Auth\Guards\TokenGuard;
use Phalcon\Auth\Providers\ModelProvider;
use Phalcon\Auth\Exceptions\ConfigFileNotExistException;

class Manager
{
    protected config;
    protected security;
    protected customGuards = [];
    protected guards = [];

    public function __construct(<ConfigInterface> config = null, security = null)
    {
        if config === null {
            let this->config = Di::getDefault()->getShared("config")->auth;

            if this->config === null {
                throw new ConfigFileNotExistException();
            }
        }

        if security === null {
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

        if this->guards[name] === null {
            let this->guards[name] = this->resolve(name);
        }

        return this->guards[name];
    }

    protected function resolve(string name)
    {
        var configGuard;

        let configGuard = this->getConfigGuard(name);

        if configGuard === null {
            throw new InvalidArgumentException(sprintf("Auth guard [%s] is not defined.", name));
        }

        if isset(this->customGuards[configGuard["driver"]]) {
            return this->callCustomGuard(name, configGuard);
        }

        var provider;
        let provider = this->createProvider(configGuard);

        var guard;

        var guardName = sprintf(
            "\\Phalcon\\Auth\\Guards\\%sGuard",
            ucfirst(configGuard->driver)
        );

        if (!class_exists(guardName)) {
            throw new InvalidArgumentException(
                sprintf(
                    "Auth driver %s for guard %s is not defined.",
                    configGuard->driver, name
                )
            );
        }

        let guard = new {guardName}(name, provider);

        return guard;
    }

    public function createProvider(configGuard = null)
    {
        var provider = configGuard->provider;

         var driver = sprintf("\\Phalcon\\Auth\\Providers\\%sProvider",
            ucfirst(this->config->providers->{provider}->driver)
        );

         if (!class_exists(driver)) {
            throw new InvalidArgumentException(
                sprintf(
                    "Provider %s is not defined.",
                    provider
                )
            );
        }

        return new {driver}(this->security, this->config->providers->{provider});
    }

    public function getDefaultDriver()
    {
        return this->config->defaults->guard;
    }

    public function extend(driver, var callback)
    {
        let this->customGuards[driver] = callback;

        return this;
    }

    protected function callCustomGuard(string name, <ConfigInterface> config)
    {
        var customGuard = this->customGuards[config["driver"]];

        return {customGuard}(name, config);
    }

    public function __call(method, params)
    {
        return call_user_func_array(
            [this->guard(), method],
            params
        );
    }
}