namespace Phalcon\Auth\Access;

use Phalcon\Di\Injectable;

abstract class AbstractAccess extends Injectable implements AccessInterface
{
    protected exceptActions = [];
    protected onlyActions   = [];

    public function setExceptActions(array exceptActions = []) -> void
    {
        let this->exceptActions = exceptActions;
    }

    public function getExceptActions() -> array
    {
        return this->exceptActions;
    }

    public function setOnlyActions() -> void
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