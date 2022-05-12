namespace Phalcon\Auth;

interface AuthenticatableInterface
{
    public function getAuthIdentifier();
    public function getAuthPassword();
}