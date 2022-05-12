namespace Phalcon\Auth\RememberToken;

interface RememberingInterface
{
    public function getRememberToken() -> null|<RememberTokenInterface>;
    public function setRememberToken(<RememberTokenInterface> value);
}