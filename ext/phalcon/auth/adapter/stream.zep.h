
extern zend_class_entry *phalcon_auth_adapter_stream_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Stream);

PHP_METHOD(Phalcon_Auth_Adapter_Stream, getData);
PHP_METHOD(Phalcon_Auth_Adapter_Stream, read);
PHP_METHOD(Phalcon_Auth_Adapter_Stream, validate);
PHP_METHOD(Phalcon_Auth_Adapter_Stream, getFileSource);
PHP_METHOD(Phalcon_Auth_Adapter_Stream, setFileSource);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_stream_getdata, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_stream_read, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, src, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_stream_validate, 0, 0, 2)
	ZEND_ARG_INFO(0, fileData)
	ZEND_ARG_TYPE_INFO(0, src, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_stream_getfilesource, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_stream_setfilesource, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, src, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_adapter_stream_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Adapter_Stream, getData, arginfo_phalcon_auth_adapter_stream_getdata, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Adapter_Stream, getData, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Auth_Adapter_Stream, read, arginfo_phalcon_auth_adapter_stream_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_Stream, validate, arginfo_phalcon_auth_adapter_stream_validate, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Auth_Adapter_Stream, getFileSource, arginfo_phalcon_auth_adapter_stream_getfilesource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_Stream, setFileSource, arginfo_phalcon_auth_adapter_stream_setfilesource, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
