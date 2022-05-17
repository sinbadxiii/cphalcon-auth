
extern zend_class_entry *phalcon_auth_middlewares_authenticate_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Middlewares_Authenticate);

PHP_METHOD(Phalcon_Auth_Middlewares_Authenticate, beforeDispatch);
PHP_METHOD(Phalcon_Auth_Middlewares_Authenticate, call);
PHP_METHOD(Phalcon_Auth_Middlewares_Authenticate, authenticate);
PHP_METHOD(Phalcon_Auth_Middlewares_Authenticate, unauthenticated);
PHP_METHOD(Phalcon_Auth_Middlewares_Authenticate, redirectTo);
PHP_METHOD(Phalcon_Auth_Middlewares_Authenticate, setGuest);
PHP_METHOD(Phalcon_Auth_Middlewares_Authenticate, isGuest);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_middlewares_authenticate_beforedispatch, 0, 0, 3)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, dispatcher)
	ZEND_ARG_INFO(0, exception)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_middlewares_authenticate_call, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, application, Phalcon\\Mvc\\Micro, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_middlewares_authenticate_authenticate, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_middlewares_authenticate_unauthenticated, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_middlewares_authenticate_redirectto, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_middlewares_authenticate_setguest, 0, 0, 1)
	ZEND_ARG_INFO(0, guest)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_middlewares_authenticate_isguest, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_middlewares_authenticate_method_entry) {
	PHP_ME(Phalcon_Auth_Middlewares_Authenticate, beforeDispatch, arginfo_phalcon_auth_middlewares_authenticate_beforedispatch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Middlewares_Authenticate, call, arginfo_phalcon_auth_middlewares_authenticate_call, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Middlewares_Authenticate, authenticate, arginfo_phalcon_auth_middlewares_authenticate_authenticate, ZEND_ACC_PROTECTED)
#else
	PHP_ME(Phalcon_Auth_Middlewares_Authenticate, authenticate, NULL, ZEND_ACC_PROTECTED)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Middlewares_Authenticate, unauthenticated, arginfo_phalcon_auth_middlewares_authenticate_unauthenticated, ZEND_ACC_PROTECTED)
#else
	PHP_ME(Phalcon_Auth_Middlewares_Authenticate, unauthenticated, NULL, ZEND_ACC_PROTECTED)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Middlewares_Authenticate, redirectTo, arginfo_phalcon_auth_middlewares_authenticate_redirectto, ZEND_ACC_PROTECTED)
#else
	PHP_ME(Phalcon_Auth_Middlewares_Authenticate, redirectTo, NULL, ZEND_ACC_PROTECTED)
#endif
	PHP_ME(Phalcon_Auth_Middlewares_Authenticate, setGuest, arginfo_phalcon_auth_middlewares_authenticate_setguest, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Middlewares_Authenticate, isGuest, arginfo_phalcon_auth_middlewares_authenticate_isguest, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
