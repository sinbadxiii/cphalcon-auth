namespace Phalcon\Auth\Events;

use ReflectionClass;

abstract class EventAbstract implements EventInterface
{
    public function getType() -> string
    {
        var reflect;
        let reflect = new ReflectionClass(this);
        return lcfirst(reflect->getShortName());
    }
}
