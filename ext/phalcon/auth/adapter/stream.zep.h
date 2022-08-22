
extern zend_class_entry *phalcon_auth_adapter_stream_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Stream);

PHP_METHOD(Phalcon_Auth_Adapter_Stream, getData);
PHP_METHOD(Phalcon_Auth_Adapter_Stream, read);
PHP_METHOD(Phalcon_Auth_Adapter_Stream, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_stream_getdata, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_stream_read, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_stream_validate, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, fileData, IS_STRING, 0)
	ZEND_ARG_INFO(0, filepath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_adapter_stream_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Adapter_Stream, getData, arginfo_phalcon_auth_adapter_stream_getdata, ZEND_ACC_PROTECTED)
#else
	PHP_ME(Phalcon_Auth_Adapter_Stream, getData, NULL, ZEND_ACC_PROTECTED)
#endif
	PHP_ME(Phalcon_Auth_Adapter_Stream, read, arginfo_phalcon_auth_adapter_stream_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_Stream, validate, arginfo_phalcon_auth_adapter_stream_validate, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
