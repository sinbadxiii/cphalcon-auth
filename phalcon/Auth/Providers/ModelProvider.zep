namespace Phalcon\Auth\Providers;

use Phalcon\Di\Di;
use Phalcon\Encryption\Security\Random;
use Phalcon\Auth\AuthenticatableInterface;
use Phalcon\Auth\RememberToken\RememberTokenModel;

class ModelProvider implements ProviderInterface
{
    protected model;
    protected hasher;
    protected di;

    public function __construct(hasher, config)
    {
        let this->hasher = hasher,
        this->model      = config->model;
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

        if (!retrievedModel) {
            return;
        }
        var rememberTokenModel = retrievedModel->getRememberToken(token);

        if (!rememberTokenModel) {
            return;
        }

        var rememberToken = rememberTokenModel->getToken();

        return rememberToken && hash_equals(rememberToken, token) && hash_equals(
            rememberTokenModel->getUserAgent(), user_agent
        ) ? retrievedModel : null;
    }

    public function createRememberToken(<AuthenticatableInterface> user)
    {
        var rememberToken;
        let rememberToken = new RememberTokenModel();
        let rememberToken->token = this->hasher->getRandom()->base64(60);
        let rememberToken->user_agent = Di::getDefault()->get("request")->getUserAgent();
        let rememberToken->ip = Di::getDefault()->get("request")->getClientAddress();

        user->setRememberToken(rememberToken);
        user->update();

        return rememberToken;
    }

    public function validateCredentials(<AuthenticatableInterface> user, array credentials)
    {
        return this->hasher->checkHash(
            credentials["password"], user->getAuthPassword()
        );
    }
}