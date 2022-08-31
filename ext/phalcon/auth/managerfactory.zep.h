
extern zend_class_entry *phalcon_auth_managerfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_ManagerFactory);

PHP_METHOD(Phalcon_Auth_ManagerFactory, __construct);
PHP_METHOD(Phalcon_Auth_ManagerFactory, getConfigGuard);
PHP_METHOD(Phalcon_Auth_ManagerFactory, guard);
PHP_METHOD(Phalcon_Auth_ManagerFactory, resolve);
PHP_METHOD(Phalcon_Auth_ManagerFactory, getAdapterProvider);
PHP_METHOD(Phalcon_Auth_ManagerFactory, getDefaultGuardName);
PHP_METHOD(Phalcon_Auth_ManagerFactory, extendGuard);
PHP_METHOD(Phalcon_Auth_ManagerFactory, extendProviderAdapter);
PHP_METHOD(Phalcon_Auth_ManagerFactory, getEventsManager);
PHP_METHOD(Phalcon_Auth_ManagerFactory, setEventsManager);
zend_object *zephir_init_properties_Phalcon_Auth_ManagerFactory(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_managerfactory___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, config, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, config, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, security, Phalcon\\Encryption\\Security, 1)
	ZEND_ARG_OBJ_INFO(0, session, Phalcon\\Session\\ManagerInterface, 1)
	ZEND_ARG_OBJ_INFO(0, cookies, Phalcon\\Http\\Response\\Cookies, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\Request, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_managerfactory_getconfigguard, 0, 1, IS_ARRAY, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_managerfactory_guard, 0, 0, Phalcon\\Auth\\Guard\\GuardInterface, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_managerfactory_resolve, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, nameGuard, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_managerfactory_getadapterprovider, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, provider, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_managerfactory_getdefaultguardname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_managerfactory_extendguard, 0, 2, Phalcon\\Auth\\ManagerInterface, 0)
	ZEND_ARG_INFO(0, driver)
	ZEND_ARG_OBJ_INFO(0, callback, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_managerfactory_extendprovideradapter, 0, 2, Phalcon\\Auth\\ManagerInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, callback, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_managerfactory_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_managerfactory_seteventsmanager, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_managerfactory_zephir_init_properties_phalcon_auth_managerfactory, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_managerfactory_method_entry) {
	PHP_ME(Phalcon_Auth_ManagerFactory, __construct, arginfo_phalcon_auth_managerfactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_ManagerFactory, getConfigGuard, arginfo_phalcon_auth_managerfactory_getconfigguard, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_ManagerFactory, guard, arginfo_phalcon_auth_managerfactory_guard, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_ManagerFactory, resolve, arginfo_phalcon_auth_managerfactory_resolve, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_ManagerFactory, getAdapterProvider, arginfo_phalcon_auth_managerfactory_getadapterprovider, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_ManagerFactory, getDefaultGuardName, arginfo_phalcon_auth_managerfactory_getdefaultguardname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_ManagerFactory, extendGuard, arginfo_phalcon_auth_managerfactory_extendguard, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_ManagerFactory, extendProviderAdapter, arginfo_phalcon_auth_managerfactory_extendprovideradapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_ManagerFactory, getEventsManager, arginfo_phalcon_auth_managerfactory_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_ManagerFactory, setEventsManager, arginfo_phalcon_auth_managerfactory_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
