
extern zend_class_entry *phalcon_auth_access_accessabstract_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Access_AccessAbstract);

PHP_METHOD(Phalcon_Auth_Access_AccessAbstract, allowedIf);
PHP_METHOD(Phalcon_Auth_Access_AccessAbstract, except);
PHP_METHOD(Phalcon_Auth_Access_AccessAbstract, getExceptActions);
PHP_METHOD(Phalcon_Auth_Access_AccessAbstract, only);
PHP_METHOD(Phalcon_Auth_Access_AccessAbstract, getOnlyActions);
PHP_METHOD(Phalcon_Auth_Access_AccessAbstract, redirectTo);
PHP_METHOD(Phalcon_Auth_Access_AccessAbstract, isAllowed);
zend_object *zephir_init_properties_Phalcon_Auth_Access_AccessAbstract(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_accessabstract_allowedif, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_accessabstract_except, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_accessabstract_getexceptactions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_accessabstract_only, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_accessabstract_getonlyactions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_access_accessabstract_redirectto, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_accessabstract_isallowed, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_access_accessabstract_zephir_init_properties_phalcon_auth_access_accessabstract, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_access_accessabstract_method_entry) {
	PHP_ME(Phalcon_Auth_Access_AccessAbstract, allowedIf, arginfo_phalcon_auth_access_accessabstract_allowedif, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Access_AccessAbstract, except, arginfo_phalcon_auth_access_accessabstract_except, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Access_AccessAbstract, getExceptActions, arginfo_phalcon_auth_access_accessabstract_getexceptactions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Access_AccessAbstract, only, arginfo_phalcon_auth_access_accessabstract_only, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Access_AccessAbstract, getOnlyActions, arginfo_phalcon_auth_access_accessabstract_getonlyactions, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Access_AccessAbstract, redirectTo, arginfo_phalcon_auth_access_accessabstract_redirectto, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Access_AccessAbstract, redirectTo, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Auth_Access_AccessAbstract, isAllowed, arginfo_phalcon_auth_access_accessabstract_isallowed, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
