namespace Phalcon\Auth\Events;

interface EventInterface
{
    public function getType() -> string;
}