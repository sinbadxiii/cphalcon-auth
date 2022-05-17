namespace Phalcon\Auth\Middlewares;

use Phalcon\Di\Injectable;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Di\Di;
use Phalcon\Mvc\Micro\MiddlewareInterface;
use Phalcon\Mvc\Micro;

class Authenticate extends Injectable implements AuthenticatesRequestInterface, MiddlewareInterface
{
    const PROPERTY_AUTH_ACCESS   = "authAccess";
    const AUTH_ACCESS_BY_DEFAULT = true;

    protected dispatcher;
    protected app;

    public function beforeDispatch(var event, var dispatcher, var exception)
    {
        let this->dispatcher = <Dispatcher> dispatcher;

        this->authenticate();
    }

    public function call(<Micro> application)
    {
        let this->app = <Micro> application;

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

    protected function isGuest()
    {
        var controller;

        if this->app instanceof Micro {
            let controller = this->app->getActiveHandler()[0]->getDefinition();
        } else {
            let controller =  this->dispatcher->getControllerClass();
        }

        var authAccess;
        let authAccess = property_exists(controller, self::PROPERTY_AUTH_ACCESS) ?
            (new {controller})->authAccess : self::AUTH_ACCESS_BY_DEFAULT;

        return (method_exists(controller, "authAccess") &&
            !(new {controller})->authAccess()) || authAccess === false;
    }
}