namespace Phalcon\Auth\Adapter;

use Phalcon\Auth\AuthenticatableInterface;
use Phalcon\Auth\RememberingInterface;
use Phalcon\Auth\RememberTokenInterface;

interface AdapterWithRememberTokenInterface
{
    public function retrieveByToken(var identifier, var token, var user_agent) -> <AuthenticatableInterface> | null;
    public function createRememberToken(<RememberingInterface> user) -> <RememberTokenInterface>;
}