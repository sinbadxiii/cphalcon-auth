namespace Phalcon\Auth\Adapter;

use InvalidArgumentException;

class Memory extends CollectionAdapterAbstract implements AdapterInterface
{
    protected function getData()
    {
        if !this->config->has("data") {
            throw new InvalidArgumentException("Сonfig key 'datа' with user data array empty or does not exist");
        }

        return this->config->data->toArray();
    }
}