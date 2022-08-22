
extern zend_class_entry *phalcon_auth_adapter_adapterwithremembertokeninterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_AdapterWithRememberTokenInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_adapterwithremembertokeninterface_retrievebytoken, 0, 0, 3)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, token)
	ZEND_ARG_INFO(0, user_agent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_adapterwithremembertokeninterface_createremembertoken, 0, 1, Phalcon\\Auth\\RememberTokenInterface, 0)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\RememberingInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_adapter_adapterwithremembertokeninterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Auth_Adapter_AdapterWithRememberTokenInterface, retrieveByToken, arginfo_phalcon_auth_adapter_adapterwithremembertokeninterface_retrievebytoken)
	PHP_ABSTRACT_ME(Phalcon_Auth_Adapter_AdapterWithRememberTokenInterface, createRememberToken, arginfo_phalcon_auth_adapter_adapterwithremembertokeninterface_createremembertoken)
	PHP_FE_END
};