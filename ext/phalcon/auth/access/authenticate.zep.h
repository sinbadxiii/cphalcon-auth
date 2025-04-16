
extern zend_class_entry *phalcon_auth_access_authenticate_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Access_Authenticate);

PHP_METHOD(Phalcon_Auth_Access_Authenticate, beforeDispatchLoop);
PHP_METHOD(Phalcon_Auth_Access_Authenticate, beforeExecuteRoute);
PHP_METHOD(Phalcon_Auth_Access_Authenticate, call);
PHP_METHOD(Phalcon_Auth_Access_Authenticate, authenticate);
zend_object *zephir_init_properties_Phalcon_Auth_Access_Authenticate(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_access_authenticate_beforedispatchloop, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_authenticate_beforeexecuteroute, 0, 3, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_INFO(0, app)
	ZEND_ARG_INFO(0, exception)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_access_authenticate_call, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, Phalcon\\Mvc\\Micro, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_access_authenticate_authenticate, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_access_authenticate_zephir_init_properties_phalcon_auth_access_authenticate, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_access_authenticate_method_entry) {
PHP_ME(Phalcon_Auth_Access_Authenticate, beforeDispatchLoop, arginfo_phalcon_auth_access_authenticate_beforedispatchloop, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Access_Authenticate, beforeExecuteRoute, arginfo_phalcon_auth_access_authenticate_beforeexecuteroute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Access_Authenticate, call, arginfo_phalcon_auth_access_authenticate_call, ZEND_ACC_PUBLIC)
PHP_ME(Phalcon_Auth_Access_Authenticate, authenticate, arginfo_phalcon_auth_access_authenticate_authenticate, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
