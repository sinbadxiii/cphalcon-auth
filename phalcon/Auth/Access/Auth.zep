namespace Phalcon\Auth\Access;

use Phalcon\Di\Di;

class Auth extends AccessAbstract
{
    public function allowedIf() -> bool
    {
        if (Di::getDefault()->getShared("auth")->check()) {
            return true;
        }

        return false;
    }
}