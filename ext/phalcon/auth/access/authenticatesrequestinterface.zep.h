
extern zend_class_entry *phalcon_auth_access_authenticatesrequestinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Access_AuthenticatesRequestInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_authenticatesrequestinterface_beforeexecuteroute, 0, 3, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, dispatcher, Phalcon\\Mvc\\Dispatcher, 0)
	ZEND_ARG_INFO(0, exception)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_access_authenticatesrequestinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Auth_Access_AuthenticatesRequestInterface, beforeExecuteRoute, arginfo_phalcon_auth_access_authenticatesrequestinterface_beforeexecuteroute)
	PHP_FE_END
};
