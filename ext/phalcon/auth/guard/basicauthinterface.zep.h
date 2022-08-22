
extern zend_class_entry *phalcon_auth_guard_basicauthinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_BasicAuthInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guard_basicauthinterface_basic, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, extraConditions, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, extraConditions, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guard_basicauthinterface_oncebasic, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, extraConditions, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, extraConditions, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_guard_basicauthinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Auth_Guard_BasicAuthInterface, basic, arginfo_phalcon_auth_guard_basicauthinterface_basic)
	PHP_ABSTRACT_ME(Phalcon_Auth_Guard_BasicAuthInterface, onceBasic, arginfo_phalcon_auth_guard_basicauthinterface_oncebasic)
	PHP_FE_END
};
