namespace Phalcon\Auth\Providers;

use Phalcon\Auth\AuthenticatableInterface;

interface ProviderInterface
{
    public function retrieveByCredentials(array credentials);
    public function retrieveById(id);
    public function validateCredentials(<AuthenticatableInterface> user, array credentials);
}