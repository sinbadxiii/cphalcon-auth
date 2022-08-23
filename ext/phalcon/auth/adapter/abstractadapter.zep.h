
extern zend_class_entry *phalcon_auth_adapter_abstractadapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_AbstractAdapter);

PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, __construct);
PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, getProviderStorage);
PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, retrieveByCredentials);
PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, retrieveById);
PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, validateCredentials);
PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, find);
PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, first);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_abstractadapter___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, hasher, Phalcon\\Encryption\\Security, 0)
	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Config\\ConfigInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_abstractadapter_getproviderstorage, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_abstractadapter_retrievebycredentials, 0, 1, Phalcon\\Auth\\AuthenticatableInterface, 1)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_abstractadapter_retrievebyid, 0, 1, Phalcon\\Auth\\AuthenticatableInterface, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_abstractadapter_validatecredentials, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_abstractadapter_find, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, providerStorage, 0)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_abstractadapter_first, 0, 2, Phalcon\\Auth\\AuthenticatableInterface, 1)
	ZEND_ARG_ARRAY_INFO(0, providerStorage, 0)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_adapter_abstractadapter_method_entry) {
	PHP_ME(Phalcon_Auth_Adapter_AbstractAdapter, __construct, arginfo_phalcon_auth_adapter_abstractadapter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Adapter_AbstractAdapter, getProviderStorage, arginfo_phalcon_auth_adapter_abstractadapter_getproviderstorage, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
#else
	PHP_ME(Phalcon_Auth_Adapter_AbstractAdapter, getProviderStorage, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
#endif
	PHP_ME(Phalcon_Auth_Adapter_AbstractAdapter, retrieveByCredentials, arginfo_phalcon_auth_adapter_abstractadapter_retrievebycredentials, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_AbstractAdapter, retrieveById, arginfo_phalcon_auth_adapter_abstractadapter_retrievebyid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_AbstractAdapter, validateCredentials, arginfo_phalcon_auth_adapter_abstractadapter_validatecredentials, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_AbstractAdapter, find, arginfo_phalcon_auth_adapter_abstractadapter_find, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_AbstractAdapter, first, arginfo_phalcon_auth_adapter_abstractadapter_first, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
