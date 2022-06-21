namespace Phalcon\Auth\Collection;

use Phalcon\Auth\AuthenticatableInterface;

class User implements AuthenticatableInterface
{
    private id;
    private key;
    private password;

    public function __construct(data)
    {
        var field, value;

        for field, value in data {
            let this->{field} = value;
        }
    }

    public function setKey(key)
    {
        let this->key = key;
    }

    public function getAuthIdentifier()
    {
        var ident = this->getKey();
        return this->{ident};
    }

    public function getAuthPassword()
    {
        return this->password;
    }

    private function getKey()
    {
        return "id";
    }

    public function getId()
    {
        return this->id;
    }
}