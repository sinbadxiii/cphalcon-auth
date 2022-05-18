namespace Phalcon\Auth\Middlewares;

use Phalcon\Di\Di;
use Phalcon\Di\Injectable;
use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Micro\MiddlewareInterface;
use InvalidArgumentException;

class Authenticate extends Injectable implements AuthenticatesRequestInterface, MiddlewareInterface
{
    const PROPERTY_AUTH_ACCESS   = "authAccess";
    const METHOD_AUTH_ACCESS     = "authAccess";
    const AUTH_ACCESS_BY_DEFAULT = true;

    protected dispatcher;
    protected app;
    protected controllerClass;

    public function beforeDispatch(var event, var dispatcher, var exception)
    {
        let this->dispatcher = <Dispatcher> dispatcher;
        let this->controllerClass = this->dispatcher->getControllerClass();

        this->authenticate();
    }

    public function call(<Micro> application)
    {
        let this->app = <Micro> application;

        if this->app instanceof Micro {
            var handler = this->app->getActiveHandler();

            if (typeof handler !== "array" && !isset handler[0] ) {
                throw new InvalidArgumentException("Handler is not defined.");
            }

            switch typeof handler[0] {
                case "string":
                    let this->controllerClass = handler[0];
                    break;
                case "object":
                    let this->controllerClass = handler[0]->getDefinition();
                    break;
                default:
                    throw new InvalidArgumentException("Unknow typeof Handler.");
            }
        }

        this->authenticate();
    }

    protected function authenticate()
    {
        if Di::getDefault()->getShared("auth")->authenticate() || this->isGuest() {
            return true;
        }

        this->unauthenticated();
    }

    protected function unauthenticated()
    {
        this->redirectTo();
    }

    protected function redirectTo()
    {
        //custom url
    }

    protected function setGuest(guest)
    {
        let this->guest = guest;
    }

    protected function isGuest() -> bool
    {
        var authAccess, controller, controllerClass, authAccessProperty, methodAccessProperty;

        let authAccessProperty   = self::PROPERTY_AUTH_ACCESS;
        let methodAccessProperty = self::METHOD_AUTH_ACCESS;
        let controllerClass      = this->controllerClass;
        let controller           = new {controllerClass};

        let authAccess = property_exists(controller, authAccessProperty) ?
            controller->{authAccessProperty} : self::AUTH_ACCESS_BY_DEFAULT;

        return (method_exists(controller, methodAccessProperty) &&
            !controller->{methodAccessProperty}()) || authAccess === false;
    }
}