
extern zend_class_entry *phalcon_auth_access_abstractaccess_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Access_AbstractAccess);

PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, allowedIf);
PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, except);
PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, getExceptActions);
PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, only);
PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, getOnlyActions);
PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, redirectTo);
PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, isAllowed);
zend_object *zephir_init_properties_Phalcon_Auth_Access_AbstractAccess(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_abstractaccess_allowedif, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_abstractaccess_except, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_abstractaccess_getexceptactions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_abstractaccess_only, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_abstractaccess_getonlyactions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_access_abstractaccess_redirectto, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_abstractaccess_isallowed, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_access_abstractaccess_zephir_init_properties_phalcon_auth_access_abstractaccess, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_access_abstractaccess_method_entry) {
	PHP_ME(Phalcon_Auth_Access_AbstractAccess, allowedIf, arginfo_phalcon_auth_access_abstractaccess_allowedif, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Access_AbstractAccess, except, arginfo_phalcon_auth_access_abstractaccess_except, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Access_AbstractAccess, getExceptActions, arginfo_phalcon_auth_access_abstractaccess_getexceptactions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Access_AbstractAccess, only, arginfo_phalcon_auth_access_abstractaccess_only, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Access_AbstractAccess, getOnlyActions, arginfo_phalcon_auth_access_abstractaccess_getonlyactions, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Access_AbstractAccess, redirectTo, arginfo_phalcon_auth_access_abstractaccess_redirectto, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Access_AbstractAccess, redirectTo, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Auth_Access_AbstractAccess, isAllowed, arginfo_phalcon_auth_access_abstractaccess_isallowed, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
