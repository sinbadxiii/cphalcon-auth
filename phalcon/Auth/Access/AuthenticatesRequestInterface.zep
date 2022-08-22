namespace Phalcon\Auth\Access;

use Phalcon\Events\Event;
use Phalcon\Mvc\Dispatcher;

interface AuthenticatesRequestInterface
{
    public function beforeExecuteRoute(<Event> event, <Dispatcher> dispatcher, var exception) -> void;
    //protected function authenticate();
}

