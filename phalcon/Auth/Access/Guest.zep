namespace Phalcon\Auth\Access;

use Phalcon\Di\Di;

class Guest extends AbstractAccess
{
    public function allowedIf() -> bool
    {
        if (Di::getDefault()->getShared("auth")->guest()) {
            return true;
        }

        return false;
    }
}