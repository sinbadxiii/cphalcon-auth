
extern zend_class_entry *phalcon_auth_adapter_abstractadapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_AbstractAdapter);

PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, __construct);
PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, getModel);
PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, setModel);
PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, getConfig);
PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, setConfig);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_abstractadapter___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, hasher, Phalcon\\Encryption\\Security, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, config, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, config, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_abstractadapter_getmodel, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_abstractadapter_setmodel, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, model, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_abstractadapter_getconfig, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_abstractadapter_setconfig, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_adapter_abstractadapter_method_entry) {
	PHP_ME(Phalcon_Auth_Adapter_AbstractAdapter, __construct, arginfo_phalcon_auth_adapter_abstractadapter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Adapter_AbstractAdapter, getModel, arginfo_phalcon_auth_adapter_abstractadapter_getmodel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_AbstractAdapter, setModel, arginfo_phalcon_auth_adapter_abstractadapter_setmodel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_AbstractAdapter, getConfig, arginfo_phalcon_auth_adapter_abstractadapter_getconfig, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_AbstractAdapter, setConfig, arginfo_phalcon_auth_adapter_abstractadapter_setconfig, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
