
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Memory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Adapter, Memory, phalcon, auth_adapter_memory, phalcon_auth_adapter_abstractadapter_ce, phalcon_auth_adapter_memory_method_entry, 0);

	zend_declare_property_null(phalcon_auth_adapter_memory_ce, SL("data"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Adapter_Memory, retrieveByCredentials)
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

PHP_METHOD(Phalcon_Auth_Adapter_Memory, retrieveById)
{
	zend_class_entry *_3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *identifier, identifier_sub, providerStorage, userData, userModel, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&identifier_sub);
	ZVAL_UNDEF(&providerStorage);
	ZVAL_UNDEF(&userData);
	ZVAL_UNDEF(&userModel);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
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
	zephir_array_fetch(&userData, &providerStorage, identifier, PH_NOISY, "phalcon/Auth/Adapter/Memory.zep", 23);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("model"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Сonfig with key 'model' is empty", "phalcon/Auth/Adapter/Memory.zep", 26);
		return;
	}
	zephir_read_property(&userModel, this_ptr, ZEND_STRL("model"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_is_true(&userData)) {
		zephir_fetch_safe_class(&_2, &userModel);
		_3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_2), Z_STRLEN_P(&_2), ZEND_FETCH_CLASS_AUTO);
		if(!_3) {
			RETURN_MM_NULL();
		}
		object_init_ex(&_1, _3);
		if (zephir_has_constructor(&_1)) {
			ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0, &userData);
			zephir_check_call_status();
		}

	} else {
		ZVAL_NULL(&_1);
	}
	RETURN_CCTOR(&_1);
}

PHP_METHOD(Phalcon_Auth_Adapter_Memory, validateCredentials)
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
		Z_PARAM_OBJECT_OF_CLASS(user, phalcon_auth_authenticatableinterface_ce)
		Z_PARAM_ARRAY(credentials)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &user, &credentials_param);
	zephir_get_arrval(&credentials, credentials_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_2, &_1, SL("passsword_crypted"), PH_NOISY | PH_READONLY, "phalcon/Auth/Adapter/Memory.zep", 35);
	if (zephir_is_true(&_2)) {
		zephir_read_property(&_3, this_ptr, ZEND_STRL("hasher"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_4, &credentials, SL("password"), PH_NOISY | PH_READONLY, "phalcon/Auth/Adapter/Memory.zep", 36);
		ZEPHIR_CALL_METHOD(&_5, user, "getauthpassword", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_0, &_3, "checkhash", NULL, 0, &_4, &_5);
		zephir_check_call_status();
	} else {
		zephir_array_fetch_string(&_6, &credentials, SL("password"), PH_NOISY | PH_READONLY, "phalcon/Auth/Adapter/Memory.zep", 37);
		ZEPHIR_CALL_METHOD(&_7, user, "getauthpassword", NULL, 0);
		zephir_check_call_status();
		ZVAL_BOOL(&_0, ZEPHIR_IS_IDENTICAL(&_6, &_7));
	}
	RETURN_CCTOR(&_0);
}

PHP_METHOD(Phalcon_Auth_Adapter_Memory, first)
{
	zend_class_entry *_3$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *providerStorage_param = NULL, *credentials_param = NULL, __$true, field, userModel, term, key, _0, _1, data$$5, _2$$5;
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
	ZVAL_UNDEF(&data$$5);
	ZVAL_UNDEF(&_2$$5);
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
	zephir_array_fetch(&term, &credentials, &field, PH_NOISY, "phalcon/Auth/Adapter/Memory.zep", 48);
	ZEPHIR_CALL_FUNCTION(&_0, "array_column", NULL, 2, &providerStorage, &field);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&key, "array_search", NULL, 3, &term, &_0, &__$true);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("model"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Сonfig with key 'model' is empty", "phalcon/Auth/Adapter/Memory.zep", 52);
		return;
	}
	zephir_read_property(&userModel, this_ptr, ZEND_STRL("model"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&key)) {
		ZEPHIR_OBS_VAR(&data$$5);
		zephir_array_fetch(&data$$5, &providerStorage, &key, PH_NOISY, "phalcon/Auth/Adapter/Memory.zep", 57);
		zephir_array_update_string(&data$$5, SL("id"), &key, PH_COPY | PH_SEPARATE);
		zephir_fetch_safe_class(&_2$$5, &userModel);
		_3$$5 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_2$$5), Z_STRLEN_P(&_2$$5), ZEND_FETCH_CLASS_AUTO);
		if(!_3$$5) {
			RETURN_MM_NULL();
		}
		object_init_ex(return_value, _3$$5);
		if (zephir_has_constructor(return_value)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &data$$5);
			zephir_check_call_status();
		}

		RETURN_MM();
	}
	RETURN_MM_NULL();
}

PHP_METHOD(Phalcon_Auth_Adapter_Memory, getProviderStorage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Adapter_Memory, getData)
{
	zend_bool _1;
	zval _0, _2, _3, _4, _7, _5$$4, _6$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_is_true(&_0);
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
		_1 = !(zephir_array_isset_string(&_2, SL("data")));
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Сonfig key 'datа' with user data array empty or does not exist", "phalcon/Auth/Adapter/Memory.zep", 75);
		return;
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_4);
	zephir_array_fetch_string(&_4, &_3, SL("data"), PH_NOISY, "phalcon/Auth/Adapter/Memory.zep", 78);
	if (!(ZEPHIR_IS_EMPTY(&_4))) {
		zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_6$$4, &_5$$4, SL("data"), PH_NOISY | PH_READONLY, "phalcon/Auth/Adapter/Memory.zep", 79);
		zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &_6$$4);
	}
	ZEPHIR_OBS_VAR(&_7);
	zephir_read_property(&_7, this_ptr, ZEND_STRL("data"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_7)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Data is empty", "phalcon/Auth/Adapter/Memory.zep", 85);
		return;
	}
	RETURN_MM_MEMBER(getThis(), "data");
}

PHP_METHOD(Phalcon_Auth_Adapter_Memory, setData)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *data_param = NULL;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);
	zephir_get_arrval(&data, data_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &data);
	ZEPHIR_MM_RESTORE();
}

