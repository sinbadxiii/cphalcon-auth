
extern zend_class_entry *phalcon_auth_guards_sessionguard_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Guards_SessionGuard);

PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, __construct);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, attempt);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, user);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, hasValidCredentials);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, validate);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, userFromRecaller);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, recaller);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, getRememberData);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, getName);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, getRememberName);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, login);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, loginById);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, once);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, rememberUser);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, createRememberToken);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, updateSession);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, logout);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, getLastUserAttempted);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, event);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, viaRemember);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, getUser);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, getRequest);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, setRequest);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, basic);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, attemptBasic);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, failedBasicResponse);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, basicCredentials);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, onceBasic);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, userFromBasic);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, passwordFromBasic);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, id);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, setUser);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, check);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, hasUser);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, guest);
PHP_METHOD(Phalcon_Auth_Guards_SessionGuard, authenticate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, provider)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_attempt, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
#endif
	ZEND_ARG_TYPE_INFO(0, remember, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_user, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_hasvalidcredentials, 0, 0, 2)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_validate, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_userfromrecaller, 0, 0, 1)
	ZEND_ARG_INFO(0, recaller)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_recaller, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_getrememberdata, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_getremembername, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_login, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
	ZEND_ARG_TYPE_INFO(0, remember, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_loginbyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_TYPE_INFO(0, remember, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_once, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_rememberuser, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_createremembertoken, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_updatesession, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, id, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_logout, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_getlastuserattempted, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_event, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Auth\\Events\\EventInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_viaremember, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_getuser, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_getrequest, 0, 0, Phalcon\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_setrequest, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_basic, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, extraConditions, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, extraConditions, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_attemptbasic, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\Request, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, extraConditions, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, extraConditions, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_failedbasicresponse, 0, 0, Phalcon\\Auth\\Exception, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_basiccredentials, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\Request, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_oncebasic, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, extraConditions, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, extraConditions, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_userfrombasic, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_passwordfrombasic, 0, 0, 1)
	ZEND_ARG_INFO(0, request)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_id, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_setuser, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Auth\\AuthenticatableInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_check, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_hasuser, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_guest, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guards_sessionguard_authenticate, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_guards_sessionguard_method_entry) {
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, __construct, arginfo_phalcon_auth_guards_sessionguard___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, attempt, arginfo_phalcon_auth_guards_sessionguard_attempt, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, user, arginfo_phalcon_auth_guards_sessionguard_user, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, user, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, hasValidCredentials, arginfo_phalcon_auth_guards_sessionguard_hasvalidcredentials, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, validate, arginfo_phalcon_auth_guards_sessionguard_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, userFromRecaller, arginfo_phalcon_auth_guards_sessionguard_userfromrecaller, ZEND_ACC_PROTECTED)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, recaller, arginfo_phalcon_auth_guards_sessionguard_recaller, ZEND_ACC_PROTECTED)
#else
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, recaller, NULL, ZEND_ACC_PROTECTED)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, getRememberData, arginfo_phalcon_auth_guards_sessionguard_getrememberdata, ZEND_ACC_PROTECTED)
#else
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, getRememberData, NULL, ZEND_ACC_PROTECTED)
#endif
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, getName, arginfo_phalcon_auth_guards_sessionguard_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, getRememberName, arginfo_phalcon_auth_guards_sessionguard_getremembername, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, login, arginfo_phalcon_auth_guards_sessionguard_login, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, loginById, arginfo_phalcon_auth_guards_sessionguard_loginbyid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, once, arginfo_phalcon_auth_guards_sessionguard_once, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, rememberUser, arginfo_phalcon_auth_guards_sessionguard_rememberuser, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, createRememberToken, arginfo_phalcon_auth_guards_sessionguard_createremembertoken, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, updateSession, arginfo_phalcon_auth_guards_sessionguard_updatesession, ZEND_ACC_PROTECTED)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, logout, arginfo_phalcon_auth_guards_sessionguard_logout, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, logout, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, getLastUserAttempted, arginfo_phalcon_auth_guards_sessionguard_getlastuserattempted, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, getLastUserAttempted, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, event, arginfo_phalcon_auth_guards_sessionguard_event, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, viaRemember, arginfo_phalcon_auth_guards_sessionguard_viaremember, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, viaRemember, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, getUser, arginfo_phalcon_auth_guards_sessionguard_getuser, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, getUser, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, getRequest, arginfo_phalcon_auth_guards_sessionguard_getrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, setRequest, arginfo_phalcon_auth_guards_sessionguard_setrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, basic, arginfo_phalcon_auth_guards_sessionguard_basic, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, attemptBasic, arginfo_phalcon_auth_guards_sessionguard_attemptbasic, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, failedBasicResponse, arginfo_phalcon_auth_guards_sessionguard_failedbasicresponse, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, basicCredentials, arginfo_phalcon_auth_guards_sessionguard_basiccredentials, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, onceBasic, arginfo_phalcon_auth_guards_sessionguard_oncebasic, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, userFromBasic, arginfo_phalcon_auth_guards_sessionguard_userfrombasic, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, passwordFromBasic, arginfo_phalcon_auth_guards_sessionguard_passwordfrombasic, ZEND_ACC_PRIVATE)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, id, arginfo_phalcon_auth_guards_sessionguard_id, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, id, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, setUser, arginfo_phalcon_auth_guards_sessionguard_setuser, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, check, arginfo_phalcon_auth_guards_sessionguard_check, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, check, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, hasUser, arginfo_phalcon_auth_guards_sessionguard_hasuser, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, hasUser, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, guest, arginfo_phalcon_auth_guards_sessionguard_guest, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, guest, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, authenticate, arginfo_phalcon_auth_guards_sessionguard_authenticate, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Auth_Guards_SessionGuard, authenticate, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
