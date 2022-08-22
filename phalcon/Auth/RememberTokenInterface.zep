namespace Phalcon\Auth;

interface RememberTokenInterface
{
    public function getToken() -> string;
    public function getUserAgent() -> string;
}