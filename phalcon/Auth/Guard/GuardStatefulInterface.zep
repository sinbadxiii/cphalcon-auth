namespace Phalcon\Auth\Guard;

use Phalcon\Auth\AuthenticatableInterface;

interface GuardStatefulInterface
{
    public function attempt(array credentials = [], bool remember = false) -> bool;
    public function login(<AuthenticatableInterface> user, bool remember = false) -> void;
    public function loginById(id, bool remember = false);
    public function once(array credentials = []);
    public function viaRemember() -> bool;
    public function logout();
}