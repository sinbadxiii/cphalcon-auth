
extern zend_class_entry *phalcon_auth_events_eventabstract_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Events_EventAbstract);

PHP_METHOD(Phalcon_Auth_Events_EventAbstract, getType);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_events_eventabstract_gettype, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_events_eventabstract_method_entry) {
	PHP_ME(Phalcon_Auth_Events_EventAbstract, getType, arginfo_phalcon_auth_events_eventabstract_gettype, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
