namespace Phalcon\Auth\Adapter;

use Phalcon\Di\Di;
use Phalcon\Config\ConfigInterface;
use Phalcon\Encryption\Security;
use Phalcon\Auth\AuthenticatableInterface;
use Phalcon\Auth\RememberingInterface;
use Phalcon\Auth\RememberTokenInterface;

class Model implements AdapterInterface, AdapterWithRememberTokenInterface
{
    protected model;
    protected hasher;
    protected di;

    public function __construct(<Security> hasher, <ConfigInterface> config)
    {
        let this->hasher = hasher, this->model = config->model;
    }

    public function retrieveByCredentials(array credentials)
    {
        var builder = Di::getDefault()->get("modelsManager")
            ->createBuilder()
            ->from([this->model]);

        var key, value;

        for key, value in credentials {
            if key == "password" {
                continue;
            }

            builder->andWhere(sprintf("%s = :%s:", key, key), [key: value]);
        }

        return builder->getQuery()->execute()->getFirst();
    }

    public function retrieveById(identifier)
    {
        var model = this->model;
        return {model}::findFirst(identifier);
    }

    public function retrieveByToken(identifier, token, user_agent)
    {
        var model = this->model;
        var retrievedModel = {model}::findFirst(identifier);

        if !retrievedModel {
            return;
        }
        var rememberTokenModel = retrievedModel->getRememberToken(token);

        if !rememberTokenModel {
            return;
        }

        var rememberToken = rememberTokenModel->getToken();

        return rememberToken && hash_equals(rememberToken, token) && hash_equals(
            rememberTokenModel->getUserAgent(), user_agent
        ) ? retrievedModel : null;
    }

    public function createRememberToken(<RememberingInterface> user) -> <RememberTokenInterface>
    {
        return user->createRememberToken();
    }

    public function validateCredentials(<AuthenticatableInterface> user, array credentials) -> bool
    {
        return this->hasher->checkHash(
            credentials["password"], user->getAuthPassword()
        );
    }
}