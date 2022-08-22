namespace Phalcon\Auth\Adapter;

use Phalcon\Auth\AuthenticatableInterface;

interface AdapterInterface
{
    public function retrieveByCredentials(array credentials);
    public function retrieveById(id);
    public function validateCredentials(<AuthenticatableInterface> user, array credentials) -> bool;
}