namespace Phalcon\Auth;

use Phalcon\Auth\Guard\GuardInterface;
use Phalcon\Auth\Access\AccessInterface;

interface ManagerInterface
{
    public function guard(var name = null) -> <GuardInterface>;
    public function access(string accessName) -> <ManagerInterface> | null;
}