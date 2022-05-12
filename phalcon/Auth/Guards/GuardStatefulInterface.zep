namespace Phalcon\Auth\Guards;

use Phalcon\Auth\AuthenticatableInterface;

interface GuardStatefulInterface
{
    public function attempt(array credentials = [], bool remember = false);
    public function login(<AuthenticatableInterface> user, bool remember = false);
    public function loginById(id, bool remember = false);
    public function once(array credentials = []);
    public function viaRemember();
    public function logout();
}