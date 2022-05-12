namespace Phalcon\Auth\Events;

class Logout extends EventAbstract
{
    protected user;

    public function __construct(user) {
        let this->user = user;
    }
}