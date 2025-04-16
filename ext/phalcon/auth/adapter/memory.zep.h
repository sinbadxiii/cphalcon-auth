
extern zend_class_entry *phalcon_auth_adapter_memory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Memory);

PHP_METHOD(Phalcon_Auth_Adapter_Memory, retrieveByCredentials);
PHP_METHOD(Phalcon_Auth_Adapter_Memory, retrieveById);
PHP_METHOD(Phalcon_Auth_Adapter_Memory, validateCredentials);
PHP_METHOD(Phalcon_Auth_Adapter_Memory, first);
PHP_METHOD(Phalcon_Auth_Adapter_Memory, getProviderStorage);
PHP_METHOD(Phalcon_Auth_Adapter_Memory, getData);
PHP_METHOD(Phalcon_Auth_Adapter_Memory, setData);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_memory_retrievebycredentials, 0, 1, Phalcon\\Auth\\AuthenticatableInterface, 1)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_memory_retrievebyid, 0, 1, Phalcon\\Auth\\AuthenticatableInterface, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_memory_validatecredentials, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_memory_first, 0, 2, Phalcon\\Auth\\AuthenticatableInterface, 1)
	ZEND_ARG_ARRAY_INFO(0, providerStorage, 0)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_memory_getproviderstorage, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_memory_getdata, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_memory_setdata, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_adapter_memory_method_entry) {
	PHP_ME(Phalcon_Auth_Adapter_Memory, retrieveByCredentials, arginfo_phalcon_auth_adapter_memory_retrievebycredentials, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_Memory, retrieveById, arginfo_phalcon_auth_adapter_memory_retrievebyid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_Memory, validateCredentials, arginfo_phalcon_auth_adapter_memory_validatecredentials, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_Memory, first, arginfo_phalcon_auth_adapter_memory_first, ZEND_ACC_PUBLIC)
PHP_ME(Phalcon_Auth_Adapter_Memory, getProviderStorage, arginfo_phalcon_auth_adapter_memory_getproviderstorage, ZEND_ACC_PROTECTED)
PHP_ME(Phalcon_Auth_Adapter_Memory, getData, arginfo_phalcon_auth_adapter_memory_getdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_Memory, setData, arginfo_phalcon_auth_adapter_memory_setdata, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
