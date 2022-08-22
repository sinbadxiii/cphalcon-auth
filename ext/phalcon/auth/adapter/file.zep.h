
extern zend_class_entry *phalcon_auth_adapter_file_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_File);

PHP_METHOD(Phalcon_Auth_Adapter_File, __construct);
PHP_METHOD(Phalcon_Auth_Adapter_File, retrieveByCredentials);
PHP_METHOD(Phalcon_Auth_Adapter_File, retrieveById);
PHP_METHOD(Phalcon_Auth_Adapter_File, validateCredentials);
PHP_METHOD(Phalcon_Auth_Adapter_File, createRememberToken);
PHP_METHOD(Phalcon_Auth_Adapter_File, retrieveByToken);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_file___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, hasher)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_file_retrievebycredentials, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_file_retrievebyid, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_file_validatecredentials, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_file_createremembertoken, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_file_retrievebytoken, 0, 0, 3)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, token)
	ZEND_ARG_INFO(0, user_agent)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_adapter_file_method_entry) {
	PHP_ME(Phalcon_Auth_Adapter_File, __construct, arginfo_phalcon_auth_adapter_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Adapter_File, retrieveByCredentials, arginfo_phalcon_auth_adapter_file_retrievebycredentials, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_File, retrieveById, arginfo_phalcon_auth_adapter_file_retrievebyid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_File, validateCredentials, arginfo_phalcon_auth_adapter_file_validatecredentials, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_File, createRememberToken, arginfo_phalcon_auth_adapter_file_createremembertoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_File, retrieveByToken, arginfo_phalcon_auth_adapter_file_retrievebytoken, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
