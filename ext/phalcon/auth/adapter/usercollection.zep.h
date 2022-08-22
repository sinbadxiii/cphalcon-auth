
extern zend_class_entry *phalcon_auth_adapter_usercollection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_UserCollection);

PHP_METHOD(Phalcon_Auth_Adapter_UserCollection, __construct);
PHP_METHOD(Phalcon_Auth_Adapter_UserCollection, find);
PHP_METHOD(Phalcon_Auth_Adapter_UserCollection, first);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_usercollection___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, data, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, data, 0)
#endif
	ZEND_ARG_TYPE_INFO(0, insensitive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_usercollection_find, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_usercollection_first, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_adapter_usercollection_method_entry) {
	PHP_ME(Phalcon_Auth_Adapter_UserCollection, __construct, arginfo_phalcon_auth_adapter_usercollection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Adapter_UserCollection, find, arginfo_phalcon_auth_adapter_usercollection_find, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_UserCollection, first, arginfo_phalcon_auth_adapter_usercollection_first, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
