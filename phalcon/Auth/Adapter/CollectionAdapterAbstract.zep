namespace Phalcon\Auth\Adapter;

use Phalcon\Encryption\Security;
use Phalcon\Auth\AuthenticatableInterface;
use Phalcon\Config\ConfigInterface;

abstract class CollectionAdapterAbstract implements AdapterInterface
{
    protected config;
    protected hasher;

    public function __construct(<Security> hasher, <ConfigInterface> config)
    {
        let this->hasher = hasher, this->config = config;
    }

    abstract protected function getData();

    public function retrieveByCredentials(array credentials) -> <User> | null
    {
        var collection;
        let collection = new UserCollection(this->getData());

        return collection->first(credentials);
    }

    public function retrieveById(var identifier) -> <User> | null
    {
        var collection, userData;

        let collection = new UserCollection(this->getData());
        let userData = collection[identifier];

        return userData ? new User(userData) : null;
    }

    public function validateCredentials(<AuthenticatableInterface> user, array credentials) -> bool
    {
        return (this->config->passsword_crypted) ? this->hasher->checkHash(
            credentials["password"], user->getAuthPassword()
        ) : credentials["password"] === user->getAuthPassword();
    }
}