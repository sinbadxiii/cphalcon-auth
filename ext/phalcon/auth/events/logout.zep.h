
extern zend_class_entry *phalcon_auth_events_logout_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Events_Logout);

PHP_METHOD(Phalcon_Auth_Events_Logout, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_events_logout___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, user)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_events_logout_method_entry) {
	PHP_ME(Phalcon_Auth_Events_Logout, __construct, arginfo_phalcon_auth_events_logout___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
