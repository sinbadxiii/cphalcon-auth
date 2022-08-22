
extern zend_class_entry *phalcon_auth_adapter_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_adapterinterface_retrievebycredentials, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_adapterinterface_retrievebyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_adapterinterface_validatecredentials, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_adapter_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Auth_Adapter_AdapterInterface, retrieveByCredentials, arginfo_phalcon_auth_adapter_adapterinterface_retrievebycredentials)
	PHP_ABSTRACT_ME(Phalcon_Auth_Adapter_AdapterInterface, retrieveById, arginfo_phalcon_auth_adapter_adapterinterface_retrievebyid)
	PHP_ABSTRACT_ME(Phalcon_Auth_Adapter_AdapterInterface, validateCredentials, arginfo_phalcon_auth_adapter_adapterinterface_validatecredentials)
	PHP_FE_END
};
