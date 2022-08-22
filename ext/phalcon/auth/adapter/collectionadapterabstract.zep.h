
extern zend_class_entry *phalcon_auth_adapter_collectionadapterabstract_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_CollectionAdapterAbstract);

PHP_METHOD(Phalcon_Auth_Adapter_CollectionAdapterAbstract, __construct);
PHP_METHOD(Phalcon_Auth_Adapter_CollectionAdapterAbstract, getData);
PHP_METHOD(Phalcon_Auth_Adapter_CollectionAdapterAbstract, retrieveByCredentials);
PHP_METHOD(Phalcon_Auth_Adapter_CollectionAdapterAbstract, retrieveById);
PHP_METHOD(Phalcon_Auth_Adapter_CollectionAdapterAbstract, validateCredentials);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_collectionadapterabstract___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, hasher, Phalcon\\Encryption\\Security, 0)
	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Config\\ConfigInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_collectionadapterabstract_getdata, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_collectionadapterabstract_retrievebycredentials, 0, 1, Phalcon\\Auth\\Adapter\\User, 1)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_collectionadapterabstract_retrievebyid, 0, 1, Phalcon\\Auth\\Adapter\\User, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_collectionadapterabstract_validatecredentials, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_adapter_collectionadapterabstract_method_entry) {
	PHP_ME(Phalcon_Auth_Adapter_CollectionAdapterAbstract, __construct, arginfo_phalcon_auth_adapter_collectionadapterabstract___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Adapter_CollectionAdapterAbstract, getData, arginfo_phalcon_auth_adapter_collectionadapterabstract_getdata, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
#else
	PHP_ME(Phalcon_Auth_Adapter_CollectionAdapterAbstract, getData, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
#endif
	PHP_ME(Phalcon_Auth_Adapter_CollectionAdapterAbstract, retrieveByCredentials, arginfo_phalcon_auth_adapter_collectionadapterabstract_retrievebycredentials, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_CollectionAdapterAbstract, retrieveById, arginfo_phalcon_auth_adapter_collectionadapterabstract_retrievebyid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_CollectionAdapterAbstract, validateCredentials, arginfo_phalcon_auth_adapter_collectionadapterabstract_validatecredentials, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
