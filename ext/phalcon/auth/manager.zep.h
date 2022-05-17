
extern zend_class_entry *phalcon_auth_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Manager);

PHP_METHOD(Phalcon_Auth_Manager, __construct);
PHP_METHOD(Phalcon_Auth_Manager, getConfigGuard);
PHP_METHOD(Phalcon_Auth_Manager, guard);
PHP_METHOD(Phalcon_Auth_Manager, resolve);
PHP_METHOD(Phalcon_Auth_Manager, createProvider);
PHP_METHOD(Phalcon_Auth_Manager, getDefaultDriver);
PHP_METHOD(Phalcon_Auth_Manager, extend);
PHP_METHOD(Phalcon_Auth_Manager, callCustomGuard);
PHP_METHOD(Phalcon_Auth_Manager, __call);
zend_object *zephir_init_properties_Phalcon_Auth_Manager(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_manager___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Config\\ConfigInterface, 1)
	ZEND_ARG_INFO(0, security)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_manager_getconfigguard, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_manager_guard, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_manager_resolve, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_manager_createprovider, 0, 0, 0)
	ZEND_ARG_INFO(0, configGuard)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_manager_getdefaultdriver, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_manager_extend, 0, 0, 2)
	ZEND_ARG_INFO(0, driver)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_manager_callcustomguard, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Config\\ConfigInterface, 0)
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
	PHP_ME(Phalcon_Auth_Manager, createProvider, arginfo_phalcon_auth_manager_createprovider, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Manager, getDefaultDriver, arginfo_phalcon_auth_manager_getdefaultdriver, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Manager, getDefaultDriver, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Auth_Manager, extend, arginfo_phalcon_auth_manager_extend, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, callCustomGuard, arginfo_phalcon_auth_manager_callcustomguard, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Manager, __call, arginfo_phalcon_auth_manager___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
