namespace Phalcon\Auth\Adapter;

use Phalcon\Di\Di;
use Phalcon\Auth\AuthenticatableInterface;
use Phalcon\Auth\RememberingInterface;
use Phalcon\Auth\RememberTokenInterface;

class Model extends AbstractAdapter implements AdapterWithRememberTokenInterface
{
    protected function getProviderStorage() -> mixed
    {
        return this->config->model;
    }

    public function retrieveByCredentials(array credentials) -> <AuthenticatableInterface> | null
    {
        var builder = Di::getDefault()->get("modelsManager")
            ->createBuilder()
            ->from([$this->getProviderStorage()]);

        var key, value;

        for key, value in credentials {
            if key == "password" {
                continue;
            }

            builder->andWhere(sprintf("%s = :%s:", key, key), [key: value]);
        }

        return builder->getQuery()->execute()->getFirst();
    }

    public function retrieveById(identifier) -> <AuthenticatableInterface> | null
    {
        var model = this->getProviderStorage();
        return {model}::findFirst(identifier);
    }

    public function retrieveByToken(identifier, token, user_agent) -> <AuthenticatableInterface> | null
    {
        var model = this->getProviderStorage();
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