namespace Phalcon\Auth\RememberToken;

interface RememberTokenInterface
{
    public function getToken() -> string;
    public function getUserAgent() -> string;
}