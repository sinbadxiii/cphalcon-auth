
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Providers_ModelProvider)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth\\Providers, ModelProvider, phalcon, auth_providers_modelprovider, phalcon_auth_providers_modelprovider_method_entry, 0);

	zend_declare_property_null(phalcon_auth_providers_modelprovider_ce, SL("model"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_providers_modelprovider_ce, SL("hasher"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_providers_modelprovider_ce, SL("di"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_auth_providers_modelprovider_ce, 1, phalcon_auth_providers_providerinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Providers_ModelProvider, __construct)
{
	zval *hasher, hasher_sub, *config, config_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hasher_sub);
	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(hasher)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(2, 0, &hasher, &config);


	zephir_update_property_zval(this_ptr, ZEND_STRL("hasher"), hasher);
	zephir_read_property(&_0, config, ZEND_STRL("model"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, ZEND_STRL("model"), &_0);
}

PHP_METHOD(Phalcon_Auth_Providers_ModelProvider, retrieveByCredentials)
{
	zend_string *_10;
	zend_ulong _9;
	zend_class_entry *_1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL, *_15 = NULL, *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *credentials_param = NULL, builder, _0, _2, _3, _4, _6, key, value, *_7, _8, _20, _21, _11$$3, _12$$3, _16$$5, _17$$5;
	zval credentials, _5, _14$$3, _18$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(credentials)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &credentials_param);
	zephir_get_arrval(&credentials, credentials_param);


	_1 = zephir_fetch_class_str_ex(SL("Phalcon\\Di\\Di"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_CALL_CE_STATIC(&_0, _1, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "modelsManager");
	ZEPHIR_CALL_METHOD(&_2, &_0, "get", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &_2, "createbuilder", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 1, 0);
	ZEPHIR_OBS_VAR(&_6);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("model"), PH_NOISY_CC);
	zephir_array_fast_append(&_5, &_6);
	ZEPHIR_CALL_METHOD(&builder, &_4, "from", NULL, 0, &_5);
	zephir_check_call_status();
	zephir_is_iterable(&credentials, 0, "phalcon/Auth/Providers/ModelProvider.zep", 36);
	if (Z_TYPE_P(&credentials) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&credentials), _9, _10, _7)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_10 != NULL) { 
				ZVAL_STR_COPY(&key, _10);
			} else {
				ZVAL_LONG(&key, _9);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _7);
			if (ZEPHIR_IS_STRING(&key, "password")) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_11$$3);
			ZVAL_STRING(&_11$$3, "%s = :%s:");
			ZEPHIR_CALL_FUNCTION(&_12$$3, "sprintf", &_13, 6, &_11$$3, &key, &key);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_14$$3);
			zephir_create_array(&_14$$3, 1, 0);
			zephir_array_update_zval(&_14$$3, &key, &value, PH_COPY);
			ZEPHIR_CALL_METHOD(NULL, &builder, "andwhere", &_15, 0, &_12$$3, &_14$$3);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &credentials, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_8, &credentials, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &credentials, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &credentials, "current", NULL, 0);
			zephir_check_call_status();
				if (ZEPHIR_IS_STRING(&key, "password")) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_16$$5);
				ZVAL_STRING(&_16$$5, "%s = :%s:");
				ZEPHIR_CALL_FUNCTION(&_17$$5, "sprintf", &_13, 6, &_16$$5, &key, &key);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_18$$5);
				zephir_create_array(&_18$$5, 1, 0);
				zephir_array_update_zval(&_18$$5, &key, &value, PH_COPY);
				ZEPHIR_CALL_METHOD(NULL, &builder, "andwhere", &_19, 0, &_17$$5, &_18$$5);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &credentials, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_METHOD(&_20, &builder, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_21, &_20, "execute", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_21, "getfirst", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Providers_ModelProvider, retrieveById)
{
	zend_class_entry *_1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *identifier, identifier_sub, model, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&identifier_sub);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(identifier)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("model"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&model, &_0);
	_1 = zephir_fetch_class(&model);
	ZEPHIR_RETURN_CALL_CE_STATIC(_1, "findfirst", NULL, 0, identifier);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Providers_ModelProvider, retrieveByToken)
{
	zend_bool _3, _5;
	zend_class_entry *_1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *identifier, identifier_sub, *token, token_sub, *user_agent, user_agent_sub, model, _0, retrievedModel, rememberTokenModel, rememberToken, _2, _4, _6, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&identifier_sub);
	ZVAL_UNDEF(&token_sub);
	ZVAL_UNDEF(&user_agent_sub);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&retrievedModel);
	ZVAL_UNDEF(&rememberTokenModel);
	ZVAL_UNDEF(&rememberToken);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(identifier)
		Z_PARAM_ZVAL(token)
		Z_PARAM_ZVAL(user_agent)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &identifier, &token, &user_agent);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("model"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&model, &_0);
	_1 = zephir_fetch_class(&model);
	ZEPHIR_CALL_CE_STATIC(&retrievedModel, _1, "findfirst", NULL, 0, identifier);
	zephir_check_call_status();
	if (!(zephir_is_true(&retrievedModel))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&rememberTokenModel, &retrievedModel, "getremembertoken", NULL, 0, token);
	zephir_check_call_status();
	if (!(zephir_is_true(&rememberTokenModel))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&rememberToken, &rememberTokenModel, "gettoken", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	_3 = zephir_is_true(&rememberToken);
	if (_3) {
		ZEPHIR_INIT_VAR(&_4);
		_3 = zephir_hash_equals(&rememberToken, token);
	}
	_5 = _3;
	if (_5) {
		ZEPHIR_INIT_VAR(&_6);
		ZEPHIR_CALL_METHOD(&_7, &rememberTokenModel, "getuseragent", NULL, 0);
		zephir_check_call_status();
		_5 = zephir_hash_equals(&_7, user_agent);
	}
	if (_5) {
		ZEPHIR_CPY_WRT(&_2, &retrievedModel);
	} else {
		ZVAL_NULL(&_2);
	}
	RETURN_CCTOR(&_2);
}

PHP_METHOD(Phalcon_Auth_Providers_ModelProvider, createRememberToken)
{
	zend_class_entry *_5, *_10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *user, user_sub, rememberToken, _0, _1, _2, _3, _4, _6, _7, _8, _9, _11, _12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&rememberToken);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(user, zephir_get_internal_ce(SL("phalcon\\auth\\authenticatableinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &user);


	ZEPHIR_INIT_VAR(&rememberToken);
	object_init_ex(&rememberToken, phalcon_auth_remembertoken_remembertokenmodel_ce);
	ZEPHIR_CALL_METHOD(NULL, &rememberToken, "__construct", NULL, 19);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("hasher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getrandom", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 60);
	ZEPHIR_CALL_METHOD(&_2, &_1, "base64", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_update_property_zval(&rememberToken, ZEND_STRL("token"), &_2);
	_5 = zephir_fetch_class_str_ex(SL("Phalcon\\Di\\Di"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_CALL_CE_STATIC(&_4, _5, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "request");
	ZEPHIR_CALL_METHOD(&_6, &_4, "get", NULL, 0, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, &_6, "getuseragent", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(&rememberToken, ZEND_STRL("user_agent"), &_8);
	_10 = zephir_fetch_class_str_ex(SL("Phalcon\\Di\\Di"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_CALL_CE_STATIC(&_9, _10, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "request");
	ZEPHIR_CALL_METHOD(&_11, &_9, "get", NULL, 0, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_12, &_11, "getclientaddress", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(&rememberToken, ZEND_STRL("ip"), &_12);
	ZEPHIR_CALL_METHOD(NULL, user, "setremembertoken", NULL, 0, &rememberToken);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, user, "update", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(&rememberToken);
}

PHP_METHOD(Phalcon_Auth_Providers_ModelProvider, validateCredentials)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval credentials;
	zval *user, user_sub, *credentials_param = NULL, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&credentials);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(user, zephir_get_internal_ce(SL("phalcon\\auth\\authenticatableinterface")))
		Z_PARAM_ARRAY(credentials)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &user, &credentials_param);
	zephir_get_arrval(&credentials, credentials_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("hasher"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &credentials, SL("password"), PH_NOISY | PH_READONLY, "phalcon/Auth/Providers/ModelProvider.zep", 83);
	ZEPHIR_CALL_METHOD(&_2, user, "getauthpassword", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "checkhash", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

