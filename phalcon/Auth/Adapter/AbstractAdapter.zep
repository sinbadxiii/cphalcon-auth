namespace Phalcon\Auth\Adapter;

use InvalidArgumentException;
use Phalcon\Config\ConfigInterface;
use Phalcon\Encryption\Security;
use Phalcon\Auth\AuthenticatableInterface;

abstract class AbstractAdapter implements AdapterInterface
{
    protected hasher;
    protected config;

    public function __construct(<Security> hasher, <ConfigInterface> config)
    {
        let this->hasher = hasher, this->config = config;
    }

    abstract protected function getProviderStorage() -> var;

    public function retrieveByCredentials(array credentials) -> <AuthenticatableInterface> | null
    {
        var providerStorage;
        let providerStorage = this->getProviderStorage();

        return this->first(providerStorage, credentials);
    }

    public function retrieveById(var identifier) -> <AuthenticatableInterface> | null
    {
        var providerStorage, userData, userModel;

        let providerStorage = this->getProviderStorage();
        let userData = providerStorage[identifier];

        if empty(this->config->model) {
            throw new InvalidArgumentException("Сonfig with key 'model' is empty");
        }
        let userModel = this->config->model;

        return userData ? new {userModel}(userData) : null;
    }

    public function validateCredentials(<AuthenticatableInterface> user, array credentials) -> bool
    {
        return (this->config->passsword_crypted) ? this->hasher->checkHash(
            credentials["password"], user->getAuthPassword()
        ) : credentials["password"] === user->getAuthPassword();
    }

    public function find(array providerStorage, array credentials) -> array
    {
        var field;

        if (array_key_first(credentials) === null) {
            let field = "email";
        }

        var term = credentials[field],
        keys = array_keys(array_column(providerStorage, field), term),
        userModel, result = [];

        if empty(this->config->model) {
            throw new InvalidArgumentException("Сonfig with key 'model' is empty");
        }
        let userModel = this->config->model;

        if keys !== null {
            var key;
            for key in keys {
                var data = providerStorage[key];
                let data["id"] = key;
                let result[] = new {userModel}(data);
            }
        }

        return result;
    }

    public function first(array providerStorage, array credentials) -> <AuthenticatableInterface> | null
    {
        var field = array_key_first(credentials), userModel;

        if (field === null) {
            let field = "email";
        }

        var term = credentials[field];
        var key = array_search(term, array_column(providerStorage, field), true);

        if empty(this->config->model) {
            throw new InvalidArgumentException("Сonfig with key 'model' is empty");
        }
        let userModel = this->config->model;

        if key !== false {
            var data = providerStorage[key];
            let data["id"] = key;
            return new {userModel}(data);
        }

        return null;
    }
}