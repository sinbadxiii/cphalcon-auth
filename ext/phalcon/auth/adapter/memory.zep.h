
extern zend_class_entry *phalcon_auth_adapter_memory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Memory);

PHP_METHOD(Phalcon_Auth_Adapter_Memory, getData);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_memory_getdata, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_adapter_memory_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Adapter_Memory, getData, arginfo_phalcon_auth_adapter_memory_getdata, ZEND_ACC_PROTECTED)
#else
	PHP_ME(Phalcon_Auth_Adapter_Memory, getData, NULL, ZEND_ACC_PROTECTED)
#endif
	PHP_FE_END
};
