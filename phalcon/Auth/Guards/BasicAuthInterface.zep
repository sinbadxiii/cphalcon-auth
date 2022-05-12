namespace Phalcon\Auth\Guards;

interface BasicAuthInterface
{
    public function basic(string field = "email", array extraConditions = []);
    public function onceBasic(string field = "email", array extraConditions = []);
}