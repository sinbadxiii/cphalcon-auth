
extern zend_class_entry *phalcon_auth_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Manager);

PHP_METHOD(Phalcon_Auth_Manager, guard);
PHP_METHOD(Phalcon_Auth_Manager, getDefaultGuard);
PHP_METHOD(Phalcon_Auth_Manager, setDefaultGuard);
PHP_METHOD(Phalcon_Auth_Manager, addGuard);
PHP_METHOD(Phalcon_Auth_Manager, getAccess);
PHP_METHOD(Phalcon_Auth_Manager, setAccess);
PHP_METHOD(Phalcon_Auth_Manager, setAccessList);
PHP_METHOD(Phalcon_Auth_Manager, addAccessList);
PHP_METHOD(Phalcon_Auth_Manager, access);
PHP_METHOD(Phalcon_Auth_Manager, except);
PHP_METHOD(Phalcon_Auth_Manager, only);
PHP_METHOD(Phalcon_Auth_Manager, __call);
zend_object *zephir_init_properties_Phalcon_Auth_Manager(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_guard, 0, 0, Phalcon\\Auth\\Guard\\GuardInterface, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_getdefaultguard, 0, 0, Phalcon\\Auth\\Guard\\GuardInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_setdefaultguard, 0, 1, Phalcon\\Auth\\ManagerInterface, 0)
	ZEND_ARG_OBJ_INFO(0, guard, Phalcon\\Auth\\Guard\\GuardInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_addguard, 0, 2, Phalcon\\Auth\\ManagerInterface, 0)
	ZEND_ARG_TYPE_INFO(0, nameGuard, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, guard, Phalcon\\Auth\\Guard\\GuardInterface, 0)
	ZEND_ARG_TYPE_INFO(0, isDefault, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_getaccess, 0, 0, Phalcon\\Auth\\Access\\AccessInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_setaccess, 0, 1, Phalcon\\Auth\\ManagerInterface, 0)
	ZEND_ARG_OBJ_INFO(0, access, Phalcon\\Auth\\Access\\AccessInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_setaccesslist, 0, 1, Phalcon\\Auth\\ManagerInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, accessList, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_addaccesslist, 0, 1, Phalcon\\Auth\\ManagerInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, accessList, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_access, 0, 1, Phalcon\\Auth\\ManagerInterface, 1)
	ZEND_ARG_TYPE_INFO(0, accessName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_except, 0, 0, Phalcon\\Auth\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_only, 0, 0, Phalcon\\Auth\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_manager___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_manager_zephir_init_properties_phalcon_auth_manager, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_manager_method_entry) {
	PHP_ME(Phalcon_Auth_Manager, guard, arginfo_phalcon_auth_manager_guard, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, getDefaultGuard, arginfo_phalcon_auth_manager_getdefaultguard, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, setDefaultGuard, arginfo_phalcon_auth_manager_setdefaultguard, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, addGuard, arginfo_phalcon_auth_manager_addguard, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, getAccess, arginfo_phalcon_auth_manager_getaccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, setAccess, arginfo_phalcon_auth_manager_setaccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, setAccessList, arginfo_phalcon_auth_manager_setaccesslist, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, addAccessList, arginfo_phalcon_auth_manager_addaccesslist, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, access, arginfo_phalcon_auth_manager_access, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, except, arginfo_phalcon_auth_manager_except, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, only, arginfo_phalcon_auth_manager_only, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, __call, arginfo_phalcon_auth_manager___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
