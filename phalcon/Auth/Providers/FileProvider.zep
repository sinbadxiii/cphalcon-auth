namespace Phalcon\Auth\Providers;

use Phalcon\Auth\Providers\FileProvider\Parser;
use Phalcon\Auth\AuthenticatableInterface;
use Phalcon\Auth\Collection\User;

class FileProvider implements ProviderInterface
{
    protected collection;
    protected hasher;
    protected config;

    public function __construct(hasher, config)
    {
        let this->hasher = hasher,
        this->config     = config,
        this->collection = Parser::file(config->filepath);
    }

    public function retrieveByCredentials(array credentials)
    {
        return this->collection->first(credentials);
    }

    public function retrieveById(identifier)
    {
        var data = this->collection[identifier];
        return data ? new User(data) : null;
    }

    public function validateCredentials(<AuthenticatableInterface> user, array credentials)
    {
        return (this->config->passsword_crypted) ? this->hasher->checkHash(
            credentials["password"], user->getAuthPassword()
        ) : credentials["password"] === user->getAuthPassword();
    }

    public function createRememberToken(<AuthenticatableInterface> user)
    {
        return true;
    }

    public function retrieveByToken(identifier, token, user_agent)
    {
        return [];
    }
}