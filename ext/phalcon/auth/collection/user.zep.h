
extern zend_class_entry *phalcon_auth_collection_user_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Collection_User);

PHP_METHOD(Phalcon_Auth_Collection_User, __construct);
PHP_METHOD(Phalcon_Auth_Collection_User, setKey);
PHP_METHOD(Phalcon_Auth_Collection_User, getAuthIdentifier);
PHP_METHOD(Phalcon_Auth_Collection_User, getAuthPassword);
PHP_METHOD(Phalcon_Auth_Collection_User, getKey);
PHP_METHOD(Phalcon_Auth_Collection_User, getId);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_collection_user___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_collection_user_setkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_collection_user_getauthidentifier, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_collection_user_getauthpassword, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_collection_user_getkey, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_collection_user_getid, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_collection_user_method_entry) {
	PHP_ME(Phalcon_Auth_Collection_User, __construct, arginfo_phalcon_auth_collection_user___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Collection_User, setKey, arginfo_phalcon_auth_collection_user_setkey, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Collection_User, getAuthIdentifier, arginfo_phalcon_auth_collection_user_getauthidentifier, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Collection_User, getAuthIdentifier, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Collection_User, getAuthPassword, arginfo_phalcon_auth_collection_user_getauthpassword, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Collection_User, getAuthPassword, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Collection_User, getKey, arginfo_phalcon_auth_collection_user_getkey, ZEND_ACC_PRIVATE)
#else
	PHP_ME(Phalcon_Auth_Collection_User, getKey, NULL, ZEND_ACC_PRIVATE)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Collection_User, getId, arginfo_phalcon_auth_collection_user_getid, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Collection_User, getId, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
