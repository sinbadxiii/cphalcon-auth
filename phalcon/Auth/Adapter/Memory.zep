namespace Phalcon\Auth\Adapter;

use InvalidArgumentException;

class Memory extends AbstractAdapter
{
    protected function getProviderStorage() -> var
    {
        if !this->config->has("data") {
            throw new InvalidArgumentException("Сonfig key 'datа' with user data array empty or does not exist");
        }

        return this->config->data->toArray();
    }
}