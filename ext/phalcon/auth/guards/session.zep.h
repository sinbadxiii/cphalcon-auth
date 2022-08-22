
extern zend_class_entry *phalcon_auth_guards_session_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Guards_Session);

PHP_METHOD(Phalcon_Auth_Guards_Session, __construct);
PHP_METHOD(Phalcon_Auth_Guards_Session, attempt);
PHP_METHOD(Phalcon_Auth_Guards_Session, user);
PHP_METHOD(Phalcon_Auth_Guards_Session, hasValidCredentials);
PHP_METHOD(Phalcon_Auth_Guards_Session, validate);
PHP_METHOD(Phalcon_Auth_Guards_Session, userFromRecaller);
PHP_METHOD(Phalcon_Auth_Guards_Session, recaller);
PHP_METHOD(Phalcon_Auth_Guards_Session, getRememberData);
PHP_METHOD(Phalcon_Auth_Guards_Session, getName);
PHP_METHOD(Phalcon_Auth_Guards_Session, getRememberName);
PHP_METHOD(Phalcon_Auth_Guards_Session, login);
PHP_METHOD(Phalcon_Auth_Guards_Session, loginById);
PHP_METHOD(Phalcon_Auth_Guards_Session, once);
PHP_METHOD(Phalcon_Auth_Guards_Session, rememberUser);
PHP_METHOD(Phalcon_Auth_Guards_Session, createRememberToken);
PHP_METHOD(Phalcon_Auth_Guards_Session, updateSession);
PHP_METHOD(Phalcon_Auth_Guards_Session, logout);
PHP_METHOD(Phalcon_Auth_Guards_Session, getLastUserAttempted);
PHP_METHOD(Phalcon_Auth_Guards_Session, viaRemember);
PHP_METHOD(Phalcon_Auth_Guards_Session, getUser);
PHP_METHOD(Phalcon_Auth_Guards_Session, getRequest);
PHP_METHOD(Phalcon_Auth_Guards_Session, setRequest);
PHP_METHOD(Phalcon_Auth_Guards_Session, basic);
PHP_METHOD(Phalcon_Auth_Guards_Session, attemptBasic);
PHP_METHOD(Phalcon_Auth_Guards_Session, basicCredentials);
PHP_METHOD(Phalcon_Auth_Guards_Session, onceBasic);
PHP_METHOD(Phalcon_Auth_Guards_Session, userFromBasic);
PHP_METHOD(Phalcon_Auth_Guards_Session, passwordFromBasic);
PHP_METHOD(Phalcon_Auth_Guards_Session, id);
PHP_METHOD(Phalcon_Auth_Guards_Session, setUser);
PHP_METHOD(Phalcon_Auth_Guards_Session, check);
PHP_METHOD(Phalcon_Auth_Guards_Session, hasUser);
PHP_METHOD(Phalcon_Auth_Guards_Session, guest);
PHP_METHOD(Phalcon_Auth_Guards_Session, authenticate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_session___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, provider)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_session_attempt, 0, 0, _IS_BOOL, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
#endif
	ZEND_ARG_TYPE_INFO(0, remember, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_session_user, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_session_hasvalidcredentials, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_session_validate, 0, 0, _IS_BOOL, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_session_userfromrecaller, 0, 0, 1)
	ZEND_ARG_INFO(0, recaller)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_session_recaller, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_session_getrememberdata, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_session_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_session_getremembername, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_session_login, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
	ZEND_ARG_TYPE_INFO(0, remember, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_session_loginbyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_TYPE_INFO(0, remember, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_session_once, 0, 0, _IS_BOOL, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_session_rememberuser, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_guards_session_createremembertoken, 0, 1, Phalcon\\Auth\\RememberTokenInterface, 0)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_session_updatesession, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_session_logout, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_session_getlastuserattempted, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_session_viaremember, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_session_getuser, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_guards_session_getrequest, 0, 0, Phalcon\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_session_setrequest, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_session_basic, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, extraConditions, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, extraConditions, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_session_attemptbasic, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\Request, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, extraConditions, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, extraConditions, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_session_basiccredentials, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\Request, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_session_oncebasic, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, extraConditions, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, extraConditions, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_session_userfrombasic, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_session_passwordfrombasic, 0, 0, 1)
	ZEND_ARG_INFO(0, request)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_session_id, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_session_setuser, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_session_check, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_session_hasuser, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_session_guest, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_session_authenticate, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_guards_session_method_entry) {
	PHP_ME(Phalcon_Auth_Guards_Session, __construct, arginfo_phalcon_auth_guards_session___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Guards_Session, attempt, arginfo_phalcon_auth_guards_session_attempt, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_Session, user, arginfo_phalcon_auth_guards_session_user, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_Session, user, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Auth_Guards_Session, hasValidCredentials, arginfo_phalcon_auth_guards_session_hasvalidcredentials, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Guards_Session, validate, arginfo_phalcon_auth_guards_session_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_Session, userFromRecaller, arginfo_phalcon_auth_guards_session_userfromrecaller, ZEND_ACC_PROTECTED)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_Session, recaller, arginfo_phalcon_auth_guards_session_recaller, ZEND_ACC_PROTECTED)
#else
	PHP_ME(Phalcon_Auth_Guards_Session, recaller, NULL, ZEND_ACC_PROTECTED)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_Session, getRememberData, arginfo_phalcon_auth_guards_session_getrememberdata, ZEND_ACC_PROTECTED)
#else
	PHP_ME(Phalcon_Auth_Guards_Session, getRememberData, NULL, ZEND_ACC_PROTECTED)
#endif
	PHP_ME(Phalcon_Auth_Guards_Session, getName, arginfo_phalcon_auth_guards_session_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_Session, getRememberName, arginfo_phalcon_auth_guards_session_getremembername, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_Session, login, arginfo_phalcon_auth_guards_session_login, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_Session, loginById, arginfo_phalcon_auth_guards_session_loginbyid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_Session, once, arginfo_phalcon_auth_guards_session_once, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_Session, rememberUser, arginfo_phalcon_auth_guards_session_rememberuser, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Guards_Session, createRememberToken, arginfo_phalcon_auth_guards_session_createremembertoken, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Guards_Session, updateSession, arginfo_phalcon_auth_guards_session_updatesession, ZEND_ACC_PROTECTED)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_Session, logout, arginfo_phalcon_auth_guards_session_logout, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_Session, logout, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_Session, getLastUserAttempted, arginfo_phalcon_auth_guards_session_getlastuserattempted, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_Session, getLastUserAttempted, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_Session, viaRemember, arginfo_phalcon_auth_guards_session_viaremember, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_Session, viaRemember, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_Session, getUser, arginfo_phalcon_auth_guards_session_getuser, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_Session, getUser, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Auth_Guards_Session, getRequest, arginfo_phalcon_auth_guards_session_getrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_Session, setRequest, arginfo_phalcon_auth_guards_session_setrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_Session, basic, arginfo_phalcon_auth_guards_session_basic, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_Session, attemptBasic, arginfo_phalcon_auth_guards_session_attemptbasic, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Guards_Session, basicCredentials, arginfo_phalcon_auth_guards_session_basiccredentials, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Guards_Session, onceBasic, arginfo_phalcon_auth_guards_session_oncebasic, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_Session, userFromBasic, arginfo_phalcon_auth_guards_session_userfrombasic, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Auth_Guards_Session, passwordFromBasic, arginfo_phalcon_auth_guards_session_passwordfrombasic, ZEND_ACC_PRIVATE)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_Session, id, arginfo_phalcon_auth_guards_session_id, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_Session, id, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Auth_Guards_Session, setUser, arginfo_phalcon_auth_guards_session_setuser, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_Session, check, arginfo_phalcon_auth_guards_session_check, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_Session, hasUser, arginfo_phalcon_auth_guards_session_hasuser, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_Session, guest, arginfo_phalcon_auth_guards_session_guest, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_Session, authenticate, arginfo_phalcon_auth_guards_session_authenticate, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_Session, authenticate, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
