namespace Phalcon\Auth\Access;

use Phalcon\Di\Di;
use Phalcon\Di\Injectable;
use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Micro\MiddlewareInterface;
use InvalidArgumentException;
use Phalcon\Events\Event;
use Phalcon\Auth\ManagerInterface;
use Exception;

class Authenticate extends Injectable implements AuthenticatesRequestInterface, MiddlewareInterface
{
    protected accessList = [];
    protected authManager;
    protected actionName;

    public function __construct()
    {
        if !empty(this->accessList) {

            var container, authManager;

            let container = Di::getDefault();

            if unlikely typeof container != "object" {
                throw new \Exception(
                    "A dependency injection container is required to access the services related to the Auth"
                );
            }

            let authManager = <ManagerInterface> container->getShared("auth");
            let this->authManager = authManager;

            if unlikely typeof authManager != "object" {
                throw new Exception(
                    "The injected service 'auth' is not valid"
                );
            }

            authManager->addAccessList(this->accessList);
        }
    }

    public function beforeExecuteRoute(<Event> event, var app, var exception) -> void
    {
        if app instanceof Dispatcher {
            let this->actionName = app->getActionName();
        }

        if app instanceof Micro {
            var handler = app->getActiveHandler();

            if (typeof handler !== "object" && typeof handler !== "array" && !isset handler[1] ) {
                throw new InvalidArgumentException("Handler is not defined.");
            }

            let this->actionName = handler[1];
        }

        this->authenticate();
    }

    public function call(<Micro> app)
    {
        return true;
    }

    protected function authenticate()
    {
        var access;
        let access = this->authManager->getAccess();

        if access !== null {
            if (access->isAllowed(this->actionName)) {
                return true;
            }

            return access->redirectTo();
        }
    }
}