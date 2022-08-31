namespace Phalcon\Auth;

use InvalidArgumentException;
use Phalcon\Auth\Access\AccessInterface;
use Phalcon\Auth\Guard\GuardInterface;

class Manager implements ManagerInterface
{
    protected guards = [];
    protected activeAccess = null;
    protected accessList = [];
    protected defaultGuard;

    public function guard(var name = null) -> <GuardInterface>
    {
        if name === null {
            return this->defaultGuard;
        }

        if !isset(this->guards[name]) {
            throw new InvalidArgumentException("Auth guard [" . name . "] is not defined.");
        }

        return this->guards[name];
    }

    public function getDefaultGuard() -> <GuardInterface>
    {
        return this->defaultGuard;
    }

    public function setDefaultGuard(<GuardInterface> guard) -> <ManagerInterface>
    {
        let this->defaultGuard = $guard;

        return this;
    }

    public function addGuard(string nameGuard, <GuardInterface> guard, bool isDefault = false) -> <ManagerInterface>
    {
        let this->guards[nameGuard] = guard;

        if isDefault === true {
            let this->defaultGuard = guard;
        }

        return this;
    }

    public function getAccess() -> <AccessInterface> | null
    {
        return this->activeAccess;
    }

    public function setAccess(<AccessInterface> access) -> <ManagerInterface>
    {
        let this->activeAccess = access;

        return this;
    }

    public function setAccessList(array accessList) -> <ManagerInterface>
    {
        let this->accessList = accessList;

        return this;
    }

    public function addAccessList(array accessList) -> <ManagerInterface>
    {
        let this->accessList += accessList;

        return this;
    }

    public function access(string accessName) -> <ManagerInterface> | null
    {
        if !isset(this->accessList[accessName]) || !class_exists(this->accessList[accessName]) {
            throw new InvalidArgumentException(
                sprintf("Access with '%s' name is not included in the access list", accessName)
            );
        }

        var access = this->accessList[accessName];

        let this->activeAccess = new {access};

        return this;
    }

    public function except() -> <ManagerInterface>
    {
        this->activeAccess->setExceptActions(func_get_args());

        return this;
    }


    public function only() -> <ManagerInterface>
    {
        this->activeAccess->setOnlyActions(func_get_args());

        return this;
    }

    public function __call(method, params)
    {
        return call_user_func_array(
            [this->guard(), method],
            params
        );
    }
}