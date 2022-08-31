
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Model)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Adapter, Model, phalcon, auth_adapter_model, phalcon_auth_adapter_abstractadapter_ce, phalcon_auth_adapter_model_method_entry, 0);

	zend_class_implements(phalcon_auth_adapter_model_ce, 1, phalcon_auth_adapter_adapterwithremembertokeninterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Adapter_Model, getProviderStorage)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("model"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Model is not defined", "phalcon/Auth/Adapter/Model.zep", 14);
		return;
	}
	RETURN_MEMBER(getThis(), "model");
}

PHP_METHOD(Phalcon_Auth_Adapter_Model, retrieveByCredentials)
{
	zend_string *_10;
	zend_ulong _9;
	zend_class_entry *_1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL, *_15 = NULL, *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *credentials_param = NULL, builder, _0, _2, _3, _4, _6, key, value, *_7, _8, _20, _11$$3, _12$$3, _16$$5, _17$$5;
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
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getproviderstorage", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_5, &_6);
	ZEPHIR_CALL_METHOD(&builder, &_4, "from", NULL, 0, &_5);
	zephir_check_call_status();
	zephir_is_iterable(&credentials, 0, "phalcon/Auth/Adapter/Model.zep", 35);
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
			ZEPHIR_CALL_FUNCTION(&_12$$3, "sprintf", &_13, 5, &_11$$3, &key, &key);
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
				ZEPHIR_CALL_FUNCTION(&_17$$5, "sprintf", &_13, 5, &_16$$5, &key, &key);
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
	ZEPHIR_CALL_METHOD(&_6, &builder, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_20, &_6, "execute", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_20, "getfirst", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Adapter_Model, retrieveById)
{
	zend_class_entry *_0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *identifier, identifier_sub, model;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&identifier_sub);
	ZVAL_UNDEF(&model);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(identifier)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier);


	ZEPHIR_CALL_METHOD(&model, this_ptr, "getproviderstorage", NULL, 0);
	zephir_check_call_status();
	_0 = zephir_fetch_class(&model);
	ZEPHIR_RETURN_CALL_CE_STATIC(_0, "findfirst", NULL, 0, identifier);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Adapter_Model, retrieveByToken)
{
	zend_bool _2, _4;
	zend_class_entry *_0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *identifier, identifier_sub, *token, token_sub, *user_agent, user_agent_sub, model, retrievedModel, rememberTokenModel, rememberToken, _1, _3, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&identifier_sub);
	ZVAL_UNDEF(&token_sub);
	ZVAL_UNDEF(&user_agent_sub);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&retrievedModel);
	ZVAL_UNDEF(&rememberTokenModel);
	ZVAL_UNDEF(&rememberToken);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
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


	ZEPHIR_CALL_METHOD(&model, this_ptr, "getproviderstorage", NULL, 0);
	zephir_check_call_status();
	_0 = zephir_fetch_class(&model);
	ZEPHIR_CALL_CE_STATIC(&retrievedModel, _0, "findfirst", NULL, 0, identifier);
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
	ZEPHIR_INIT_VAR(&_1);
	_2 = zephir_is_true(&rememberToken);
	if (_2) {
		ZEPHIR_INIT_VAR(&_3);
		_2 = zephir_hash_equals(&rememberToken, token);
	}
	_4 = _2;
	if (_4) {
		ZEPHIR_INIT_VAR(&_5);
		ZEPHIR_CALL_METHOD(&_6, &rememberTokenModel, "getuseragent", NULL, 0);
		zephir_check_call_status();
		_4 = zephir_hash_equals(&_6, user_agent);
	}
	if (_4) {
		ZEPHIR_CPY_WRT(&_1, &retrievedModel);
	} else {
		ZVAL_NULL(&_1);
	}
	RETURN_CCTOR(&_1);
}

PHP_METHOD(Phalcon_Auth_Adapter_Model, createRememberToken)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *user, user_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(user, zephir_get_internal_ce(SL("phalcon\\auth\\rememberinginterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &user);


	ZEPHIR_RETURN_CALL_METHOD(user, "createremembertoken", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Adapter_Model, validateCredentials)
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
	zephir_array_fetch_string(&_1, &credentials, SL("password"), PH_NOISY | PH_READONLY, "phalcon/Auth/Adapter/Model.zep", 73);
	ZEPHIR_CALL_METHOD(&_2, user, "getauthpassword", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "checkhash", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

