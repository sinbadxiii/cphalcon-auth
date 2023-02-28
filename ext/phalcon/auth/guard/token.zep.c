
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_Token)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth\\Guard, Token, phalcon, auth_guard_token, phalcon_auth_guard_token_method_entry, 0);

	zend_declare_property_null(phalcon_auth_guard_token_ce, SL("request"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_guard_token_ce, SL("inputKey"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_guard_token_ce, SL("storageKey"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_guard_token_ce, SL("adapter"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_guard_token_ce, SL("user"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_auth_guard_token_ce, 1, phalcon_auth_guard_guardinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Guard_Token, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval config;
	zval *adapter, adapter_sub, *config_param = NULL, *request, request_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter_sub);
	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&config);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(adapter, phalcon_auth_adapter_adapterinterface_ce)
		Z_PARAM_ARRAY(config)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("phalcon\\http\\request")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &adapter, &config_param, &request);
	zephir_get_arrval(&config, config_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("adapter"), adapter);
	zephir_update_property_zval(this_ptr, ZEND_STRL("request"), request);
	zephir_array_fetch_string(&_0, &config, SL("inputKey"), PH_NOISY | PH_READONLY, "phalcon/Auth/Guard/Token.zep", 21);
	zephir_update_property_zval(this_ptr, ZEND_STRL("inputKey"), &_0);
	zephir_array_fetch_string(&_1, &config, SL("storageKey"), PH_NOISY | PH_READONLY, "phalcon/Auth/Guard/Token.zep", 22);
	zephir_update_property_zval(this_ptr, ZEND_STRL("storageKey"), &_1);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Guard_Token, user)
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
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
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

PHP_METHOD(Phalcon_Auth_Guard_Token, validate)
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
	zephir_array_fetch(&_0, &credentials, &_1, PH_NOISY | PH_READONLY, "phalcon/Auth/Guard/Token.zep", 47);
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
	zephir_array_fetch(&_4, &credentials, &_5, PH_NOISY, "phalcon/Auth/Guard/Token.zep", 51);
	zephir_array_update_zval(&_2, &_3, &_4, PH_COPY);
	ZEPHIR_CPY_WRT(&credentials, &_2);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_7, &_6, "retrievebycredentials", NULL, 0, &credentials);
	zephir_check_call_status();
	if (zephir_is_true(&_7)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);
}

PHP_METHOD(Phalcon_Auth_Guard_Token, getTokenForRequest)
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
		ZEPHIR_CALL_METHOD(&token, this_ptr, "bearertoken", NULL, 15);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&token);
}

PHP_METHOD(Phalcon_Auth_Guard_Token, bearerToken)
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
		ZEPHIR_RETURN_CALL_FUNCTION("mb_substr", NULL, 16, &header, &_3$$3, &__$null, &_4$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Guard_Token, setRequest)
{
	zval *request, request_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("phalcon\\http\\request")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &request);


	zephir_update_property_zval(this_ptr, ZEND_STRL("request"), request);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Auth_Guard_Token, getAdapter)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "adapter");
}

PHP_METHOD(Phalcon_Auth_Guard_Token, setAdapter)
{
	zval *adapter, adapter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(adapter, phalcon_auth_adapter_adapterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &adapter);


	zephir_update_property_zval(this_ptr, ZEND_STRL("adapter"), adapter);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Auth_Guard_Token, id)
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

PHP_METHOD(Phalcon_Auth_Guard_Token, setUser)
{
	zval *user, user_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(user, phalcon_auth_authenticatableinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &user);


	zephir_update_property_zval(this_ptr, ZEND_STRL("user"), user);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Auth_Guard_Token, check)
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

PHP_METHOD(Phalcon_Auth_Guard_Token, hasUser)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("user"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(Z_TYPE_P(&_0) != IS_NULL);
}

PHP_METHOD(Phalcon_Auth_Guard_Token, guest)
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

PHP_METHOD(Phalcon_Auth_Guard_Token, authenticate)
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

