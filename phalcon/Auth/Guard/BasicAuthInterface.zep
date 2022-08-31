namespace Phalcon\Auth\Guard;

interface BasicAuthInterface
{
    public function basic(string field = "email", array extraConditions = []) -> bool;
    public function onceBasic(string field = "email", array extraConditions = []);
}