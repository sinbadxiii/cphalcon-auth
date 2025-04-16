
extern zend_class_entry *phalcon_auth_guard_guardstatefulinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_GuardStatefulInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_guardstatefulinterface_attempt, 0, 0, _IS_BOOL, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO(0, remember, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_guardstatefulinterface_login, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
	ZEND_ARG_TYPE_INFO(0, remember, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guard_guardstatefulinterface_loginbyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_TYPE_INFO(0, remember, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guard_guardstatefulinterface_once, 0, 0, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_guardstatefulinterface_viaremember, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guard_guardstatefulinterface_logout, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_guard_guardstatefulinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Auth_Guard_GuardStatefulInterface, attempt, arginfo_phalcon_auth_guard_guardstatefulinterface_attempt)
	PHP_ABSTRACT_ME(Phalcon_Auth_Guard_GuardStatefulInterface, login, arginfo_phalcon_auth_guard_guardstatefulinterface_login)
	PHP_ABSTRACT_ME(Phalcon_Auth_Guard_GuardStatefulInterface, loginById, arginfo_phalcon_auth_guard_guardstatefulinterface_loginbyid)
	PHP_ABSTRACT_ME(Phalcon_Auth_Guard_GuardStatefulInterface, once, arginfo_phalcon_auth_guard_guardstatefulinterface_once)
	PHP_ABSTRACT_ME(Phalcon_Auth_Guard_GuardStatefulInterface, viaRemember, arginfo_phalcon_auth_guard_guardstatefulinterface_viaremember)
	PHP_ABSTRACT_ME(Phalcon_Auth_Guard_GuardStatefulInterface, logout, arginfo_phalcon_auth_guard_guardstatefulinterface_logout)
	PHP_FE_END
};
