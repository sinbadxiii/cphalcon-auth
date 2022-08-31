namespace Phalcon\Auth\Access;

interface AccessInterface
{
    public function setExceptActions() -> void;
    public function setOnlyActions() -> void;
    public function isAllowed(string actionName) -> bool;
    public function redirectTo() -> var;
    public function allowedIf() -> bool;
}