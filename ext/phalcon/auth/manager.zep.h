
extern zend_class_entry *phalcon_auth_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Manager);

PHP_METHOD(Phalcon_Auth_Manager, __construct);
PHP_METHOD(Phalcon_Auth_Manager, getConfigGuard);
PHP_METHOD(Phalcon_Auth_Manager, guard);
PHP_METHOD(Phalcon_Auth_Manager, resolve);
PHP_METHOD(Phalcon_Auth_Manager, getAdapterProvider);
PHP_METHOD(Phalcon_Auth_Manager, getDefaultDriver);
PHP_METHOD(Phalcon_Auth_Manager, addGuard);
PHP_METHOD(Phalcon_Auth_Manager, addProviderAdapter);
PHP_METHOD(Phalcon_Auth_Manager, getAccess);
PHP_METHOD(Phalcon_Auth_Manager, setAccess);
PHP_METHOD(Phalcon_Auth_Manager, setAccessList);
PHP_METHOD(Phalcon_Auth_Manager, addAccessList);
PHP_METHOD(Phalcon_Auth_Manager, access);
PHP_METHOD(Phalcon_Auth_Manager, __call);
zend_object *zephir_init_properties_Phalcon_Auth_Manager(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_manager___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Config\\ConfigInterface, 1)
	ZEND_ARG_OBJ_INFO(0, security, Phalcon\\Encryption\\Security, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_getconfigguard, 0, 1, Phalcon\\Config\\ConfigInterface, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_guard, 0, 0, Phalcon\\Auth\\Guard\\GuardInterface, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_manager_resolve, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_manager_getadapterprovider, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, provider, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_manager_getdefaultdriver, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_addguard, 0, 2, Phalcon\\Auth\\ManagerInterface, 0)
	ZEND_ARG_INFO(0, driver)
	ZEND_ARG_OBJ_INFO(0, callback, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_addprovideradapter, 0, 2, Phalcon\\Auth\\ManagerInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, callback, Closure, 0)
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

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_access, 0, 1, Phalcon\\Auth\\Access\\AccessInterface, 1)
	ZEND_ARG_TYPE_INFO(0, accessName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_manager___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_manager_zephir_init_properties_phalcon_auth_manager, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_manager_method_entry) {
	PHP_ME(Phalcon_Auth_Manager, __construct, arginfo_phalcon_auth_manager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Manager, getConfigGuard, arginfo_phalcon_auth_manager_getconfigguard, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Manager, guard, arginfo_phalcon_auth_manager_guard, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, resolve, arginfo_phalcon_auth_manager_resolve, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Manager, getAdapterProvider, arginfo_phalcon_auth_manager_getadapterprovider, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, getDefaultDriver, arginfo_phalcon_auth_manager_getdefaultdriver, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, addGuard, arginfo_phalcon_auth_manager_addguard, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, addProviderAdapter, arginfo_phalcon_auth_manager_addprovideradapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, getAccess, arginfo_phalcon_auth_manager_getaccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, setAccess, arginfo_phalcon_auth_manager_setaccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, setAccessList, arginfo_phalcon_auth_manager_setaccesslist, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, addAccessList, arginfo_phalcon_auth_manager_addaccesslist, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, access, arginfo_phalcon_auth_manager_access, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, __call, arginfo_phalcon_auth_manager___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
