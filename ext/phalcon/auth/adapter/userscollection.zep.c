
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_UsersCollection)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Adapter, UsersCollection, phalcon, auth_adapter_userscollection, zephir_get_internal_ce(SL("phalcon\\support\\collection")), phalcon_auth_adapter_userscollection_method_entry, 0);

	zend_declare_property_null(phalcon_auth_adapter_userscollection_ce, SL("collection"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Adapter_UsersCollection, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool insensitive;
	zval *data_param = NULL, *insensitive_param = NULL, _0;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(data)
		Z_PARAM_BOOL(insensitive)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &data_param, &insensitive_param);
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}
	if (!insensitive_param) {
		insensitive = 1;
	} else {
		insensitive = zephir_get_boolval(insensitive_param);
	}


	zephir_update_static_property_ce(phalcon_auth_adapter_userscollection_ce, ZEND_STRL("collection"), &data);
	if (insensitive) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_auth_adapter_userscollection_ce, getThis(), "__construct", NULL, 0, &data, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Adapter_UsersCollection, find)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *credentials_param = NULL, field, _0, term, keys, _1, _2, result, key$$4, *_3$$4, _4$$4, data$$5, _5$$5, _6$$5, data$$6, _8$$6, _9$$6;
	zval credentials;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&term);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&key$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&data$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&data$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(credentials)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &credentials_param);
	zephir_get_arrval(&credentials, credentials_param);


	ZEPHIR_CALL_FUNCTION(&_0, "array_key_first", NULL, 7, &credentials);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&field);
		ZVAL_STRING(&field, "email");
	}
	ZEPHIR_OBS_VAR(&term);
	zephir_array_fetch(&term, &credentials, &field, PH_NOISY, "phalcon/Auth/Adapter/UsersCollection.zep", 23);
	zephir_read_static_property_ce(&_1, phalcon_auth_adapter_userscollection_ce, SL("collection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_2, "array_column", NULL, 8, &_1, &field);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&keys, "array_keys", NULL, 9, &_2, &term);
	zephir_check_call_status();
	if (Z_TYPE_P(&keys) != IS_NULL) {
		zephir_is_iterable(&keys, 0, "phalcon/Auth/Adapter/UsersCollection.zep", 34);
		if (Z_TYPE_P(&keys) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keys), _3$$4)
			{
				ZEPHIR_INIT_NVAR(&key$$4);
				ZVAL_COPY(&key$$4, _3$$4);
				zephir_read_static_property_ce(&_5$$5, phalcon_auth_adapter_userscollection_ce, SL("collection"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&data$$5);
				zephir_array_fetch(&data$$5, &_5$$5, &key$$4, PH_NOISY, "phalcon/Auth/Adapter/UsersCollection.zep", 30);
				zephir_array_update_string(&data$$5, SL("id"), &key$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_6$$5);
				object_init_ex(&_6$$5, phalcon_auth_adapter_user_ce);
				ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", &_7, 1, &data$$5);
				zephir_check_call_status();
				zephir_array_append(&result, &_6$$5, PH_SEPARATE, "phalcon/Auth/Adapter/UsersCollection.zep", 32);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &keys, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$4, &keys, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key$$4, &keys, "current", NULL, 0);
				zephir_check_call_status();
					zephir_read_static_property_ce(&_8$$6, phalcon_auth_adapter_userscollection_ce, SL("collection"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&data$$6);
					zephir_array_fetch(&data$$6, &_8$$6, &key$$4, PH_NOISY, "phalcon/Auth/Adapter/UsersCollection.zep", 30);
					zephir_array_update_string(&data$$6, SL("id"), &key$$4, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_9$$6);
					object_init_ex(&_9$$6, phalcon_auth_adapter_user_ce);
					ZEPHIR_CALL_METHOD(NULL, &_9$$6, "__construct", &_7, 1, &data$$6);
					zephir_check_call_status();
					zephir_array_append(&result, &_9$$6, PH_SEPARATE, "phalcon/Auth/Adapter/UsersCollection.zep", 32);
				ZEPHIR_CALL_METHOD(NULL, &keys, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&key$$4);
	}
	RETURN_CCTOR(&result);
}

PHP_METHOD(Phalcon_Auth_Adapter_UsersCollection, first)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *credentials_param = NULL, __$true, field, term, key, _0, _1, data$$4, _2$$4;
	zval credentials;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&term);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&data$$4);
	ZVAL_UNDEF(&_2$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(credentials)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &credentials_param);
	zephir_get_arrval(&credentials, credentials_param);


	ZEPHIR_CALL_FUNCTION(&field, "array_key_first", NULL, 7, &credentials);
	zephir_check_call_status();
	if (Z_TYPE_P(&field) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&field);
		ZVAL_STRING(&field, "email");
	}
	ZEPHIR_OBS_VAR(&term);
	zephir_array_fetch(&term, &credentials, &field, PH_NOISY, "phalcon/Auth/Adapter/UsersCollection.zep", 47);
	zephir_read_static_property_ce(&_0, phalcon_auth_adapter_userscollection_ce, SL("collection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "array_column", NULL, 8, &_0, &field);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&key, "array_search", NULL, 10, &term, &_1, &__$true);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&key)) {
		zephir_read_static_property_ce(&_2$$4, phalcon_auth_adapter_userscollection_ce, SL("collection"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&data$$4);
		zephir_array_fetch(&data$$4, &_2$$4, &key, PH_NOISY, "phalcon/Auth/Adapter/UsersCollection.zep", 51);
		zephir_array_update_string(&data$$4, SL("id"), &key, PH_COPY | PH_SEPARATE);
		object_init_ex(return_value, phalcon_auth_adapter_user_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 1, &data$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();
}

