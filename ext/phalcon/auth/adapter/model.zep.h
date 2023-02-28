
extern zend_class_entry *phalcon_auth_adapter_model_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Model);

PHP_METHOD(Phalcon_Auth_Adapter_Model, getProviderStorage);
PHP_METHOD(Phalcon_Auth_Adapter_Model, retrieveByCredentials);
PHP_METHOD(Phalcon_Auth_Adapter_Model, retrieveById);
PHP_METHOD(Phalcon_Auth_Adapter_Model, retrieveByToken);
PHP_METHOD(Phalcon_Auth_Adapter_Model, createRememberToken);
PHP_METHOD(Phalcon_Auth_Adapter_Model, validateCredentials);

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_model_getproviderstorage, 0, 0, IS_MIXED, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_model_getproviderstorage, 0, 0, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_model_retrievebycredentials, 0, 1, Phalcon\\Auth\\AuthenticatableInterface, 1)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_model_retrievebyid, 0, 1, Phalcon\\Auth\\AuthenticatableInterface, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_model_retrievebytoken, 0, 3, Phalcon\\Auth\\AuthenticatableInterface, 1)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, token)
	ZEND_ARG_INFO(0, user_agent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_model_createremembertoken, 0, 1, Phalcon\\Auth\\RememberTokenInterface, 0)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\RememberingInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_model_validatecredentials, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_adapter_model_method_entry) {
	PHP_ME(Phalcon_Auth_Adapter_Model, getProviderStorage, arginfo_phalcon_auth_adapter_model_getproviderstorage, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Adapter_Model, retrieveByCredentials, arginfo_phalcon_auth_adapter_model_retrievebycredentials, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_Model, retrieveById, arginfo_phalcon_auth_adapter_model_retrievebyid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_Model, retrieveByToken, arginfo_phalcon_auth_adapter_model_retrievebytoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_Model, createRememberToken, arginfo_phalcon_auth_adapter_model_createremembertoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_Model, validateCredentials, arginfo_phalcon_auth_adapter_model_validatecredentials, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
