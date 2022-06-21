
extern zend_class_entry *phalcon_auth_providers_fileprovider_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Providers_FileProvider);

PHP_METHOD(Phalcon_Auth_Providers_FileProvider, __construct);
PHP_METHOD(Phalcon_Auth_Providers_FileProvider, retrieveByCredentials);
PHP_METHOD(Phalcon_Auth_Providers_FileProvider, retrieveById);
PHP_METHOD(Phalcon_Auth_Providers_FileProvider, validateCredentials);
PHP_METHOD(Phalcon_Auth_Providers_FileProvider, createRememberToken);
PHP_METHOD(Phalcon_Auth_Providers_FileProvider, retrieveByToken);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_providers_fileprovider___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, hasher)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_providers_fileprovider_retrievebycredentials, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_providers_fileprovider_retrievebyid, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_providers_fileprovider_validatecredentials, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_providers_fileprovider_createremembertoken, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_providers_fileprovider_retrievebytoken, 0, 0, 3)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, token)
	ZEND_ARG_INFO(0, user_agent)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_providers_fileprovider_method_entry) {
	PHP_ME(Phalcon_Auth_Providers_FileProvider, __construct, arginfo_phalcon_auth_providers_fileprovider___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Providers_FileProvider, retrieveByCredentials, arginfo_phalcon_auth_providers_fileprovider_retrievebycredentials, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Providers_FileProvider, retrieveById, arginfo_phalcon_auth_providers_fileprovider_retrievebyid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Providers_FileProvider, validateCredentials, arginfo_phalcon_auth_providers_fileprovider_validatecredentials, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Providers_FileProvider, createRememberToken, arginfo_phalcon_auth_providers_fileprovider_createremembertoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Providers_FileProvider, retrieveByToken, arginfo_phalcon_auth_providers_fileprovider_retrievebytoken, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
