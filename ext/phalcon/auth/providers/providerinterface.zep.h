
extern zend_class_entry *phalcon_auth_providers_providerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Providers_ProviderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_providers_providerinterface_retrievebycredentials, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_providers_providerinterface_retrievebyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_providers_providerinterface_validatecredentials, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_providers_providerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Auth_Providers_ProviderInterface, retrieveByCredentials, arginfo_phalcon_auth_providers_providerinterface_retrievebycredentials)
	PHP_ABSTRACT_ME(Phalcon_Auth_Providers_ProviderInterface, retrieveById, arginfo_phalcon_auth_providers_providerinterface_retrievebyid)
	PHP_ABSTRACT_ME(Phalcon_Auth_Providers_ProviderInterface, validateCredentials, arginfo_phalcon_auth_providers_providerinterface_validatecredentials)
	PHP_FE_END
};
