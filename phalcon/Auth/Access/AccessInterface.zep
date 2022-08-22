namespace Phalcon\Auth\Access;

interface AccessInterface
{
    public function except() -> void;
    public function only() -> void;
    public function isAllowed(string actionName) -> bool;
    public function redirectTo() -> var;
    public function allowedIf() -> bool;
}