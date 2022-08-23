
extern zend_class_entry *phalcon_auth_adapter_memory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Memory);

PHP_METHOD(Phalcon_Auth_Adapter_Memory, getProviderStorage);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_memory_getproviderstorage, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_adapter_memory_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Adapter_Memory, getProviderStorage, arginfo_phalcon_auth_adapter_memory_getproviderstorage, ZEND_ACC_PROTECTED)
#else
	PHP_ME(Phalcon_Auth_Adapter_Memory, getProviderStorage, NULL, ZEND_ACC_PROTECTED)
#endif
	PHP_FE_END
};
