
extern zend_class_entry *phalcon_auth_guard_userremember_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_UserRemember);

PHP_METHOD(Phalcon_Auth_Guard_UserRemember, __construct);
PHP_METHOD(Phalcon_Auth_Guard_UserRemember, id);
PHP_METHOD(Phalcon_Auth_Guard_UserRemember, token);
PHP_METHOD(Phalcon_Auth_Guard_UserRemember, userAgent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guard_userremember___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guard_userremember_id, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guard_userremember_token, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guard_userremember_useragent, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_guard_userremember_method_entry) {
	PHP_ME(Phalcon_Auth_Guard_UserRemember, __construct, arginfo_phalcon_auth_guard_userremember___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
PHP_ME(Phalcon_Auth_Guard_UserRemember, id, arginfo_phalcon_auth_guard_userremember_id, ZEND_ACC_PUBLIC)
PHP_ME(Phalcon_Auth_Guard_UserRemember, token, arginfo_phalcon_auth_guard_userremember_token, ZEND_ACC_PUBLIC)
PHP_ME(Phalcon_Auth_Guard_UserRemember, userAgent, arginfo_phalcon_auth_guard_userremember_useragent, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
