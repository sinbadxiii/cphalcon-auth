
extern zend_class_entry *phalcon_auth_guards_guardinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Guards_GuardInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_guardinterface_check, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_guardinterface_user, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_guardinterface_setuser, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_guardinterface_id, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_guardinterface_guest, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_guardinterface_validate, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_guards_guardinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Auth_Guards_GuardInterface, check, arginfo_phalcon_auth_guards_guardinterface_check)
	PHP_ABSTRACT_ME(Phalcon_Auth_Guards_GuardInterface, user, arginfo_phalcon_auth_guards_guardinterface_user)
	PHP_ABSTRACT_ME(Phalcon_Auth_Guards_GuardInterface, setUser, arginfo_phalcon_auth_guards_guardinterface_setuser)
	PHP_ABSTRACT_ME(Phalcon_Auth_Guards_GuardInterface, id, arginfo_phalcon_auth_guards_guardinterface_id)
	PHP_ABSTRACT_ME(Phalcon_Auth_Guards_GuardInterface, guest, arginfo_phalcon_auth_guards_guardinterface_guest)
	PHP_ABSTRACT_ME(Phalcon_Auth_Guards_GuardInterface, validate, arginfo_phalcon_auth_guards_guardinterface_validate)
	PHP_FE_END
};
