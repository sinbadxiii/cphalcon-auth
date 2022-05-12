
extern zend_class_entry *phalcon_auth_guards_guardstatefulinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Guards_GuardStatefulInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_guardstatefulinterface_attempt, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
#endif
	ZEND_ARG_TYPE_INFO(0, remember, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_guardstatefulinterface_login, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
	ZEND_ARG_TYPE_INFO(0, remember, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_guardstatefulinterface_loginbyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_TYPE_INFO(0, remember, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_guardstatefulinterface_once, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_guardstatefulinterface_viaremember, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_guardstatefulinterface_logout, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_guards_guardstatefulinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Auth_Guards_GuardStatefulInterface, attempt, arginfo_phalcon_auth_guards_guardstatefulinterface_attempt)
	PHP_ABSTRACT_ME(Phalcon_Auth_Guards_GuardStatefulInterface, login, arginfo_phalcon_auth_guards_guardstatefulinterface_login)
	PHP_ABSTRACT_ME(Phalcon_Auth_Guards_GuardStatefulInterface, loginById, arginfo_phalcon_auth_guards_guardstatefulinterface_loginbyid)
	PHP_ABSTRACT_ME(Phalcon_Auth_Guards_GuardStatefulInterface, once, arginfo_phalcon_auth_guards_guardstatefulinterface_once)
	PHP_ABSTRACT_ME(Phalcon_Auth_Guards_GuardStatefulInterface, viaRemember, arginfo_phalcon_auth_guards_guardstatefulinterface_viaremember)
	PHP_ABSTRACT_ME(Phalcon_Auth_Guards_GuardStatefulInterface, logout, arginfo_phalcon_auth_guards_guardstatefulinterface_logout)
	PHP_FE_END
};
