namespace Phalcon\Auth;

interface RememberingInterface
{
    public function getRememberToken() -> null | <RememberTokenInterface>;
    public function createRememberToken() -> <RememberTokenInterface>;
}