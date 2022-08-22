namespace Phalcon\Auth\Access;

use Phalcon\Di\Injectable;
use Phalcon\Di\Di;

abstract class AccessAbstract extends Injectable implements AccessInterface
{
    protected exceptActions = [];
    protected onlyActions   = [];

    abstract public function allowedIf() -> bool;

    public function except() -> void
    {
        let this->exceptActions = func_get_args();
    }

    public function getExceptActions() -> array
    {
        return this->exceptActions;
    }

    public function only() -> void
    {
        let this->onlyActions = func_get_args();
    }

    public function getOnlyActions() -> array
    {
        return this->onlyActions;
    }

    public function redirectTo() -> var
    {
    }

    public function isAllowed(string actionName) -> bool
    {
        var isAllowed;

        let isAllowed = this->allowedIf();

        if !empty(this->exceptActions) {
            if isAllowed || in_array(actionName, this->exceptActions) {
                return true;
            }
        }

        if !empty(this->onlyActions) {
            if isAllowed && in_array(actionName, this->onlyActions) {
                return true;
            }
        }

        if empty(this->onlyActions) && empty(this->exceptActions) {
            if isAllowed {
                return true;
            }
        }

        return false;
    }
}