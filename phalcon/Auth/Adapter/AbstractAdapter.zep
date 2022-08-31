namespace Phalcon\Auth\Adapter;

use InvalidArgumentException;
use Phalcon\Config\ConfigInterface;
use Phalcon\Encryption\Security;
use Phalcon\Auth\AuthenticatableInterface;

abstract class AbstractAdapter implements AdapterInterface
{
    protected hasher;
    protected config;
    protected model;

    public function __construct(<Security> hasher, array config = [])
    {
        let this->hasher = hasher, this->config = config;

        if !empty(this->config["model"]) {
            let this->model = $this->config["model"];
        }
    }

    public function getModel() -> string
    {
        return this->model;
    }

    public function setModel(string model) -> var
    {
        let this->model = model;

        return this;
    }

    public function getConfig() -> array
    {
        return this->config;
    }

    public function setConfig(array config) -> var
    {
        let this->config = config;

        return this;
    }
}