namespace Phalcon\Auth\Guard;

use Phalcon\Auth\AuthenticatableInterface;

interface GuardInterface
{
    public function check() -> bool;
    public function user();
    public function setUser(<AuthenticatableInterface> user);
    public function id();
    public function guest() -> bool;
    public function validate(array credentials = []) -> bool;
}
