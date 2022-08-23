
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
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_AbstractAdapter)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth\\Adapter, AbstractAdapter, phalcon, auth_adapter_abstractadapter, phalcon_auth_adapter_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_auth_adapter_abstractadapter_ce, SL("hasher"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_adapter_abstractadapter_ce, SL("config"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_auth_adapter_abstractadapter_ce, 1, phalcon_auth_adapter_adapterinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, __construct)
{
	zval *hasher, hasher_sub, *config, config_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hasher_sub);
	ZVAL_UNDEF(&config_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(hasher, zephir_get_internal_ce(SL("phalcon\\encryption\\security")))
		Z_PARAM_OBJECT_OF_CLASS(config, zephir_get_internal_ce(SL("phalcon\\config\\configinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(2, 0, &hasher, &config);


	zephir_update_property_zval(this_ptr, ZEND_STRL("hasher"), hasher);
	zephir_update_property_zval(this_ptr, ZEND_STRL("config"), config);
}

PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, getProviderStorage)
{
}

PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, retrieveByCredentials)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *credentials_param = NULL, providerStorage;
	zval credentials;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&providerStorage);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(credentials)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &credentials_param);
	zephir_get_arrval(&credentials, credentials_param);


	ZEPHIR_CALL_METHOD(&providerStorage, this_ptr, "getproviderstorage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "first", NULL, 0, &providerStorage, &credentials);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, retrieveById)
{
	zend_class_entry *_5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *identifier, identifier_sub, providerStorage, userData, userModel, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&identifier_sub);
	ZVAL_UNDEF(&providerStorage);
	ZVAL_UNDEF(&userData);
	ZVAL_UNDEF(&userModel);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(identifier)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier);


	ZEPHIR_CALL_METHOD(&providerStorage, this_ptr, "getproviderstorage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&userData);
	zephir_array_fetch(&userData, &providerStorage, identifier, PH_NOISY, "phalcon/Auth/Adapter/AbstractAdapter.zep", 33);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, &_0, ZEND_STRL("model"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Сonfig with key 'model' is empty", "phalcon/Auth/Adapter/AbstractAdapter.zep", 36);
		return;
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&userModel, &_2, ZEND_STRL("model"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	if (zephir_is_true(&userData)) {
		zephir_fetch_safe_class(&_4, &userModel);
		_5 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_4), Z_STRLEN_P(&_4), ZEND_FETCH_CLASS_AUTO);
		if(!_5) {
			RETURN_MM_NULL();
		}
		object_init_ex(&_3, _5);
		if (zephir_has_constructor(&_3)) {
			ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 0, &userData);
			zephir_check_call_status();
		}

	} else {
		ZVAL_NULL(&_3);
	}
	RETURN_CCTOR(&_3);
}

PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, validateCredentials)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval credentials;
	zval *user, user_sub, *credentials_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
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


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, &_1, ZEND_STRL("passsword_crypted"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_2)) {
		zephir_read_property(&_3, this_ptr, ZEND_STRL("hasher"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_4, &credentials, SL("password"), PH_NOISY | PH_READONLY, "phalcon/Auth/Adapter/AbstractAdapter.zep", 46);
		ZEPHIR_CALL_METHOD(&_5, user, "getauthpassword", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_0, &_3, "checkhash", NULL, 0, &_4, &_5);
		zephir_check_call_status();
	} else {
		zephir_array_fetch_string(&_6, &credentials, SL("password"), PH_NOISY | PH_READONLY, "phalcon/Auth/Adapter/AbstractAdapter.zep", 47);
		ZEPHIR_CALL_METHOD(&_7, user, "getauthpassword", NULL, 0);
		zephir_check_call_status();
		ZVAL_BOOL(&_0, ZEPHIR_IS_IDENTICAL(&_6, &_7));
	}
	RETURN_CCTOR(&_0);
}

PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, find)
{
	zend_class_entry *_9$$6, *_12$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *providerStorage_param = NULL, *credentials_param = NULL, field, _0, term, keys, _1, userModel, result, _2, _3, _4, key$$5, *_5$$5, _6$$5, data$$6, _7$$6, _8$$6, data$$7, _10$$7, _11$$7;
	zval providerStorage, credentials;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&providerStorage);
	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&term);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&userModel);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&key$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&data$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&data$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(providerStorage)
		Z_PARAM_ARRAY(credentials)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &providerStorage_param, &credentials_param);
	zephir_get_arrval(&providerStorage, providerStorage_param);
	zephir_get_arrval(&credentials, credentials_param);


	ZEPHIR_CALL_FUNCTION(&_0, "array_key_first", NULL, 1, &credentials);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&field);
		ZVAL_STRING(&field, "email");
	}
	ZEPHIR_OBS_VAR(&term);
	zephir_array_fetch(&term, &credentials, &field, PH_NOISY, "phalcon/Auth/Adapter/AbstractAdapter.zep", 58);
	ZEPHIR_CALL_FUNCTION(&_1, "array_column", NULL, 2, &providerStorage, &field);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&keys, "array_keys", NULL, 3, &_1, &term);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property(&_3, &_2, ZEND_STRL("model"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_3)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Сonfig with key 'model' is empty", "phalcon/Auth/Adapter/AbstractAdapter.zep", 63);
		return;
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&userModel, &_4, ZEND_STRL("model"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&keys) != IS_NULL) {
		zephir_is_iterable(&keys, 0, "phalcon/Auth/Adapter/AbstractAdapter.zep", 74);
		if (Z_TYPE_P(&keys) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keys), _5$$5)
			{
				ZEPHIR_INIT_NVAR(&key$$5);
				ZVAL_COPY(&key$$5, _5$$5);
				ZEPHIR_OBS_NVAR(&data$$6);
				zephir_array_fetch(&data$$6, &providerStorage, &key$$5, PH_NOISY, "phalcon/Auth/Adapter/AbstractAdapter.zep", 70);
				zephir_array_update_string(&data$$6, SL("id"), &key$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_7$$6);
				zephir_fetch_safe_class(&_8$$6, &userModel);
				_9$$6 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_8$$6), Z_STRLEN_P(&_8$$6), ZEND_FETCH_CLASS_AUTO);
				if(!_9$$6) {
					RETURN_MM_NULL();
				}
				object_init_ex(&_7$$6, _9$$6);
				if (zephir_has_constructor(&_7$$6)) {
					ZEPHIR_CALL_METHOD(NULL, &_7$$6, "__construct", NULL, 0, &data$$6);
					zephir_check_call_status();
				}

				zephir_array_append(&result, &_7$$6, PH_SEPARATE, "phalcon/Auth/Adapter/AbstractAdapter.zep", 72);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &keys, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_6$$5, &keys, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_6$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key$$5, &keys, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&data$$7);
					zephir_array_fetch(&data$$7, &providerStorage, &key$$5, PH_NOISY, "phalcon/Auth/Adapter/AbstractAdapter.zep", 70);
					zephir_array_update_string(&data$$7, SL("id"), &key$$5, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_10$$7);
					zephir_fetch_safe_class(&_11$$7, &userModel);
					_12$$7 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_11$$7), Z_STRLEN_P(&_11$$7), ZEND_FETCH_CLASS_AUTO);
					if(!_12$$7) {
						RETURN_MM_NULL();
					}
					object_init_ex(&_10$$7, _12$$7);
					if (zephir_has_constructor(&_10$$7)) {
						ZEPHIR_CALL_METHOD(NULL, &_10$$7, "__construct", NULL, 0, &data$$7);
						zephir_check_call_status();
					}

					zephir_array_append(&result, &_10$$7, PH_SEPARATE, "phalcon/Auth/Adapter/AbstractAdapter.zep", 72);
				ZEPHIR_CALL_METHOD(NULL, &keys, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&key$$5);
	}
	RETURN_CCTOR(&result);
}

PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, first)
{
	zend_class_entry *_5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *providerStorage_param = NULL, *credentials_param = NULL, __$true, field, userModel, term, key, _0, _1, _2, _3, data$$5, _4$$5;
	zval providerStorage, credentials;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&providerStorage);
	ZVAL_UNDEF(&credentials);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&userModel);
	ZVAL_UNDEF(&term);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&data$$5);
	ZVAL_UNDEF(&_4$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(providerStorage)
		Z_PARAM_ARRAY(credentials)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &providerStorage_param, &credentials_param);
	zephir_get_arrval(&providerStorage, providerStorage_param);
	zephir_get_arrval(&credentials, credentials_param);


	ZEPHIR_CALL_FUNCTION(&field, "array_key_first", NULL, 1, &credentials);
	zephir_check_call_status();
	if (Z_TYPE_P(&field) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&field);
		ZVAL_STRING(&field, "email");
	}
	ZEPHIR_OBS_VAR(&term);
	zephir_array_fetch(&term, &credentials, &field, PH_NOISY, "phalcon/Auth/Adapter/AbstractAdapter.zep", 87);
	ZEPHIR_CALL_FUNCTION(&_0, "array_column", NULL, 2, &providerStorage, &field);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&key, "array_search", NULL, 4, &term, &_0, &__$true);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, &_1, ZEND_STRL("model"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_2)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Сonfig with key 'model' is empty", "phalcon/Auth/Adapter/AbstractAdapter.zep", 91);
		return;
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&userModel, &_3, ZEND_STRL("model"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&key)) {
		ZEPHIR_OBS_VAR(&data$$5);
		zephir_array_fetch(&data$$5, &providerStorage, &key, PH_NOISY, "phalcon/Auth/Adapter/AbstractAdapter.zep", 96);
		zephir_array_update_string(&data$$5, SL("id"), &key, PH_COPY | PH_SEPARATE);
		zephir_fetch_safe_class(&_4$$5, &userModel);
		_5$$5 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_4$$5), Z_STRLEN_P(&_4$$5), ZEND_FETCH_CLASS_AUTO);
		if(!_5$$5) {
			RETURN_MM_NULL();
		}
		object_init_ex(return_value, _5$$5);
		if (zephir_has_constructor(return_value)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &data$$5);
			zephir_check_call_status();
		}

		RETURN_MM();
	}
	RETURN_MM_NULL();
}

