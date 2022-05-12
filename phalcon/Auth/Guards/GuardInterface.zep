namespace Phalcon\Auth\Guards;

use Phalcon\Auth\AuthenticatableInterface;

interface GuardInterface
{
    public function check();
    public function user();
    public function setUser(<AuthenticatableInterface> user);
    public function id();
    public function guest();
    public function validate(array credentials = []);
}
