namespace Phalcon\Auth\Middlewares;

use Phalcon\Di\Injectable;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Di\Di;

class Authenticate extends Injectable implements AuthenticatesRequestInterface
{
    const PROPERTY_AUTH_ACCESS = "authAccess";

    protected dispatcher;

    public function beforeDispatch(var event, var dispatcher, var exception)
    {
        let this->dispatcher = <Dispatcher> dispatcher;

        this->authenticate();
    }

    protected function authenticate()
    {
        if (Di::getDefault()->getShared("auth")->authenticate() || this->isGuest()) {
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
        var controller = this->dispatcher->getControllerClass();

        return !(new {controller})->authAccess() ||
            (property_exists(controller, self::PROPERTY_AUTH_ACCESS) &&
                (new {controller})->authAccess === false);
    }
}