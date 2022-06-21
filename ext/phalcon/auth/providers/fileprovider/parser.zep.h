
extern zend_class_entry *phalcon_auth_providers_fileprovider_parser_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Providers_FileProvider_Parser);

PHP_METHOD(Phalcon_Auth_Providers_FileProvider_Parser, file);
PHP_METHOD(Phalcon_Auth_Providers_FileProvider_Parser, jsonValidate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_providers_fileprovider_parser_file, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_providers_fileprovider_parser_jsonvalidate, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_providers_fileprovider_parser_method_entry) {
	PHP_ME(Phalcon_Auth_Providers_FileProvider_Parser, file, arginfo_phalcon_auth_providers_fileprovider_parser_file, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Auth_Providers_FileProvider_Parser, jsonValidate, arginfo_phalcon_auth_providers_fileprovider_parser_jsonvalidate, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};
