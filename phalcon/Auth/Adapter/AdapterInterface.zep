namespace Phalcon\Auth\Adapter;

use Phalcon\Auth\AuthenticatableInterface;

interface AdapterInterface
{
    public function retrieveByCredentials(array credentials) -> <AuthenticatableInterface> | null;
    public function retrieveById(id) -> <AuthenticatableInterface> | null;
    public function validateCredentials(<AuthenticatableInterface> user, array credentials) -> bool;
}