
extern zend_class_entry *phalcon_auth_providers_modelprovider_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Providers_ModelProvider);

PHP_METHOD(Phalcon_Auth_Providers_ModelProvider, __construct);
PHP_METHOD(Phalcon_Auth_Providers_ModelProvider, retrieveByCredentials);
PHP_METHOD(Phalcon_Auth_Providers_ModelProvider, retrieveById);
PHP_METHOD(Phalcon_Auth_Providers_ModelProvider, retrieveByToken);
PHP_METHOD(Phalcon_Auth_Providers_ModelProvider, createRememberToken);
PHP_METHOD(Phalcon_Auth_Providers_ModelProvider, validateCredentials);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_providers_modelprovider___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, hasher)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_providers_modelprovider_retrievebycredentials, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_providers_modelprovider_retrievebyid, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_providers_modelprovider_retrievebytoken, 0, 0, 3)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, token)
	ZEND_ARG_INFO(0, user_agent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_providers_modelprovider_createremembertoken, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_providers_modelprovider_validatecredentials, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_providers_modelprovider_method_entry) {
	PHP_ME(Phalcon_Auth_Providers_ModelProvider, __construct, arginfo_phalcon_auth_providers_modelprovider___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Providers_ModelProvider, retrieveByCredentials, arginfo_phalcon_auth_providers_modelprovider_retrievebycredentials, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Providers_ModelProvider, retrieveById, arginfo_phalcon_auth_providers_modelprovider_retrievebyid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Providers_ModelProvider, retrieveByToken, arginfo_phalcon_auth_providers_modelprovider_retrievebytoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Providers_ModelProvider, createRememberToken, arginfo_phalcon_auth_providers_modelprovider_createremembertoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Providers_ModelProvider, validateCredentials, arginfo_phalcon_auth_providers_modelprovider_validatecredentials, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
