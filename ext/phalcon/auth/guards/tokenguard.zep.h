
extern zend_class_entry *phalcon_auth_guards_tokenguard_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Guards_TokenGuard);

PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, __construct);
PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, user);
PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, validate);
PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, getTokenForRequest);
PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, bearerToken);
PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, id);
PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, setUser);
PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, check);
PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, hasUser);
PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, guest);
PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, authenticate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_tokenguard___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, provider)
	ZEND_ARG_INFO(0, inputKey)
	ZEND_ARG_INFO(0, storageKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_tokenguard_user, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_tokenguard_validate, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_tokenguard_gettokenforrequest, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_tokenguard_bearertoken, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_tokenguard_id, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_tokenguard_setuser, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_tokenguard_check, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_tokenguard_hasuser, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_tokenguard_guest, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_tokenguard_authenticate, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_guards_tokenguard_method_entry) {
	PHP_ME(Phalcon_Auth_Guards_TokenGuard, __construct, arginfo_phalcon_auth_guards_tokenguard___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_TokenGuard, user, arginfo_phalcon_auth_guards_tokenguard_user, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_TokenGuard, user, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Auth_Guards_TokenGuard, validate, arginfo_phalcon_auth_guards_tokenguard_validate, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_TokenGuard, getTokenForRequest, arginfo_phalcon_auth_guards_tokenguard_gettokenforrequest, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_TokenGuard, getTokenForRequest, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_TokenGuard, bearerToken, arginfo_phalcon_auth_guards_tokenguard_bearertoken, ZEND_ACC_PRIVATE)
#else
	PHP_ME(Phalcon_Auth_Guards_TokenGuard, bearerToken, NULL, ZEND_ACC_PRIVATE)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_TokenGuard, id, arginfo_phalcon_auth_guards_tokenguard_id, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_TokenGuard, id, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Auth_Guards_TokenGuard, setUser, arginfo_phalcon_auth_guards_tokenguard_setuser, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_TokenGuard, check, arginfo_phalcon_auth_guards_tokenguard_check, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_TokenGuard, hasUser, arginfo_phalcon_auth_guards_tokenguard_hasuser, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_TokenGuard, guest, arginfo_phalcon_auth_guards_tokenguard_guest, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_TokenGuard, authenticate, arginfo_phalcon_auth_guards_tokenguard_authenticate, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_TokenGuard, authenticate, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
