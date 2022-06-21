
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Guards_TokenGuard)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth\\Guards, TokenGuard, phalcon, auth_guards_tokenguard, phalcon_auth_guards_tokenguard_method_entry, 0);

	zend_declare_property_null(phalcon_auth_guards_tokenguard_ce, SL("name"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_guards_tokenguard_ce, SL("eventsManager"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_guards_tokenguard_ce, SL("request"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_guards_tokenguard_ce, SL("inputKey"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_guards_tokenguard_ce, SL("storageKey"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_guards_tokenguard_ce, SL("provider"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_guards_tokenguard_ce, SL("user"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_auth_guards_tokenguard_ce, 1, phalcon_auth_guards_guardinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, __construct)
{
	zend_class_entry *_1, *_5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *provider, provider_sub, *inputKey = NULL, inputKey_sub, *storageKey = NULL, storageKey_sub, _0, _2, _3, _4, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&provider_sub);
	ZVAL_UNDEF(&inputKey_sub);
	ZVAL_UNDEF(&storageKey_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_ZVAL(name)
		Z_PARAM_ZVAL(provider)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(inputKey)
		Z_PARAM_ZVAL(storageKey)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &name, &provider, &inputKey, &storageKey);
	if (!inputKey) {
		inputKey = &inputKey_sub;
		ZEPHIR_INIT_VAR(inputKey);
		ZVAL_STRING(inputKey, "auth_token");
	}
	if (!storageKey) {
		storageKey = &storageKey_sub;
		ZEPHIR_INIT_VAR(storageKey);
		ZVAL_STRING(storageKey, "auth_token");
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), name);
	zephir_update_property_zval(this_ptr, ZEND_STRL("provider"), provider);
	_1 = zephir_fetch_class_str_ex(SL("Phalcon\\Di\\Di"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_CALL_CE_STATIC(&_0, _1, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "eventsManager");
	ZEPHIR_CALL_METHOD(&_2, &_0, "getshared", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("eventsManager"), &_2);
	_5 = zephir_fetch_class_str_ex(SL("Phalcon\\Di\\Di"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_CALL_CE_STATIC(&_4, _5, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "request");
	ZEPHIR_CALL_METHOD(&_6, &_4, "getshared", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("request"), &_6);
	zephir_update_property_zval(this_ptr, ZEND_STRL("inputKey"), inputKey);
	zephir_update_property_zval(this_ptr, ZEND_STRL("storageKey"), storageKey);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, user)
{
	zval _2$$4;
	zval _0, user, token, _1$$4, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_2$$4);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("user"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		RETURN_MM_MEMBER(getThis(), "user");
	}
	ZEPHIR_INIT_VAR(&user);
	ZVAL_NULL(&user);
	ZEPHIR_CALL_METHOD(&token, this_ptr, "gettokenforrequest", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&token))) {
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("provider"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_create_array(&_2$$4, 1, 0);
		ZEPHIR_OBS_VAR(&_3$$4);
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("storageKey"), PH_NOISY_CC);
		zephir_array_update_zval(&_2$$4, &_3$$4, &token, PH_COPY);
		ZEPHIR_CALL_METHOD(&user, &_1$$4, "retrievebycredentials", NULL, 0, &_2$$4);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("user"), &user);
	RETURN_CCTOR(&user);
}

PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, validate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *credentials_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7;
	zval credentials;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(credentials)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &credentials_param);
	if (!credentials_param) {
		ZEPHIR_INIT_VAR(&credentials);
		array_init(&credentials);
	} else {
		zephir_get_arrval(&credentials, credentials_param);
	}


	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("inputKey"), PH_NOISY_CC);
	zephir_array_fetch(&_0, &credentials, &_1, PH_NOISY | PH_READONLY, "phalcon/Auth/Guards/TokenGuard.zep", 50);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0);
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("storageKey"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&_4);
	ZEPHIR_OBS_VAR(&_5);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("inputKey"), PH_NOISY_CC);
	zephir_array_fetch(&_4, &credentials, &_5, PH_NOISY, "phalcon/Auth/Guards/TokenGuard.zep", 54);
	zephir_array_update_zval(&_2, &_3, &_4, PH_COPY);
	ZEPHIR_CPY_WRT(&credentials, &_2);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("provider"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_7, &_6, "retrievebycredentials", NULL, 0, &credentials);
	zephir_check_call_status();
	if (zephir_is_true(&_7)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);
}

PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, event)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(event, zephir_get_internal_ce(SL("phalcon\\auth\\events\\eventinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, event, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SV(&_2, "auth:", &_1);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "fire", NULL, 0, &_2, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, getTokenForRequest)
{
	zval token, _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("inputKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&token, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&token)) {
		ZEPHIR_CALL_METHOD(&token, this_ptr, "bearertoken", NULL, 17);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&token);
}

PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, bearerToken)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, header, _0, _1, helper, _2, _3$$3, _4$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&helper);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Authorization");
	ZEPHIR_CALL_METHOD(&header, &_0, "getheader", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&helper);
	object_init_ex(&helper, zephir_get_internal_ce(SL("phalcon\\support\\helper\\str\\startswith")));
	if (zephir_has_constructor(&helper)) {
		ZEPHIR_CALL_METHOD(NULL, &helper, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Bearer ");
	ZEPHIR_CALL_ZVAL_FUNCTION(&_2, &helper, NULL, 0, &header, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZVAL_LONG(&_3$$3, 7);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "UTF-8");
		ZEPHIR_RETURN_CALL_FUNCTION("mb_substr", NULL, 18, &header, &_3$$3, &__$null, &_4$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, id)
{
	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "user", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "user", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&_1$$3, "getauthidentifier", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, setUser)
{
	zval *user, user_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(user, zephir_get_internal_ce(SL("phalcon\\auth\\authenticatableinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &user);


	zephir_update_property_zval(this_ptr, ZEND_STRL("user"), user);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, check)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "user", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(Z_TYPE_P(&_0) != IS_NULL);
}

PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, hasUser)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("user"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(Z_TYPE_P(&_0) != IS_NULL);
}

PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, guest)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "check", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!zephir_is_true(&_0));
}

PHP_METHOD(Phalcon_Auth_Guards_TokenGuard, authenticate)
{
	zval user;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&user, this_ptr, "user", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&user) != IS_NULL) {
		RETURN_CCTOR(&user);
	}
	ZEPHIR_MM_RESTORE();
}

