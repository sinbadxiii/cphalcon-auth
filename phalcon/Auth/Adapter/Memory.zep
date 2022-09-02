namespace Phalcon\Auth\Adapter;

use InvalidArgumentException;
use Phalcon\Auth\AuthenticatableInterface;

class Memory extends AbstractAdapter
{
    protected data;

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

        if empty(this->model) {
            throw new InvalidArgumentException("Сonfig with key 'model' is empty");
        }
        let userModel = this->model;

        return userData ? new {userModel}(userData) : null;
    }

    public function validateCredentials(<AuthenticatableInterface> user, array credentials) -> bool
    {
        return (this->config["passsword_crypted"]) ? this->hasher->checkHash(
            credentials["password"], user->getAuthPassword()
        ) : credentials["password"] === user->getAuthPassword();
    }

    public function first(array providerStorage, array credentials) -> <AuthenticatableInterface> | null
    {
        var field = array_key_first(credentials), userModel;

        if (field === null) {
            let field = "email";
        }

        var term = credentials[field];
        var key = array_search(term, array_column(providerStorage, field), true);

        if empty(this->model) {
            throw new InvalidArgumentException("Сonfig with key 'model' is empty");
        }
        let userModel = this->model;

        if key !== false {
            var data = providerStorage[key];
            let data["id"] = key;
            return new {userModel}(data);
        }

        return null;
    }

    protected function getProviderStorage() -> var
    {
        return this->getData();
    }

    public function getData()
    {
        if (this->config && !isset(this->config["data"])) {
            throw new InvalidArgumentException(
                "Сonfig key 'datа' with user data array empty or does not exist"
            );
        }

        if !empty(this->config["data"]) {
            let this->data = this->config["data"];
        }

        if empty(this->data) {
            throw new InvalidArgumentException(
                "Data is empty"
            );
        }

        return this->data;
    }

    public function setData(array data) -> void
    {
        let this->data = data;
    }
}