
extern zend_class_entry *phalcon_auth_guards_token_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Guards_Token);

PHP_METHOD(Phalcon_Auth_Guards_Token, __construct);
PHP_METHOD(Phalcon_Auth_Guards_Token, user);
PHP_METHOD(Phalcon_Auth_Guards_Token, validate);
PHP_METHOD(Phalcon_Auth_Guards_Token, getTokenForRequest);
PHP_METHOD(Phalcon_Auth_Guards_Token, bearerToken);
PHP_METHOD(Phalcon_Auth_Guards_Token, id);
PHP_METHOD(Phalcon_Auth_Guards_Token, setUser);
PHP_METHOD(Phalcon_Auth_Guards_Token, check);
PHP_METHOD(Phalcon_Auth_Guards_Token, hasUser);
PHP_METHOD(Phalcon_Auth_Guards_Token, guest);
PHP_METHOD(Phalcon_Auth_Guards_Token, authenticate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_token___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, provider)
	ZEND_ARG_INFO(0, inputKey)
	ZEND_ARG_INFO(0, storageKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_token_user, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_token_validate, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_token_gettokenforrequest, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_token_bearertoken, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_token_id, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_token_setuser, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_token_check, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_token_hasuser, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_token_guest, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_token_authenticate, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_guards_token_method_entry) {
	PHP_ME(Phalcon_Auth_Guards_Token, __construct, arginfo_phalcon_auth_guards_token___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_Token, user, arginfo_phalcon_auth_guards_token_user, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_Token, user, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Auth_Guards_Token, validate, arginfo_phalcon_auth_guards_token_validate, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_Token, getTokenForRequest, arginfo_phalcon_auth_guards_token_gettokenforrequest, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_Token, getTokenForRequest, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_Token, bearerToken, arginfo_phalcon_auth_guards_token_bearertoken, ZEND_ACC_PRIVATE)
#else
	PHP_ME(Phalcon_Auth_Guards_Token, bearerToken, NULL, ZEND_ACC_PRIVATE)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_Token, id, arginfo_phalcon_auth_guards_token_id, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_Token, id, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Auth_Guards_Token, setUser, arginfo_phalcon_auth_guards_token_setuser, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_Token, check, arginfo_phalcon_auth_guards_token_check, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_Token, hasUser, arginfo_phalcon_auth_guards_token_hasuser, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_Token, guest, arginfo_phalcon_auth_guards_token_guest, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_Token, authenticate, arginfo_phalcon_auth_guards_token_authenticate, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_Token, authenticate, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
