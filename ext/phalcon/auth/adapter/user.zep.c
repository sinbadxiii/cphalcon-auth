
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
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_User)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth\\Adapter, User, phalcon, auth_adapter_user, phalcon_auth_adapter_user_method_entry, 0);

	zend_declare_property_null(phalcon_auth_adapter_user_ce, SL("id"), ZEND_ACC_PRIVATE);
	zend_declare_property_null(phalcon_auth_adapter_user_ce, SL("key"), ZEND_ACC_PRIVATE);
	zend_declare_property_null(phalcon_auth_adapter_user_ce, SL("password"), ZEND_ACC_PRIVATE);
	zend_class_implements(phalcon_auth_adapter_user_ce, 1, phalcon_auth_authenticatableinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Adapter_User, __construct)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, field, value, *_0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);


	zephir_is_iterable(data, 0, "phalcon/Auth/Adapter/User.zep", 18);
	if (Z_TYPE_P(data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(data), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&field);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&field, _3);
			} else {
				ZVAL_LONG(&field, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			zephir_update_property_zval_zval(this_ptr, &field, &value);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, data, "current", NULL, 0);
			zephir_check_call_status();
				zephir_update_property_zval_zval(this_ptr, &field, &value);
			ZEPHIR_CALL_METHOD(NULL, data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&field);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Adapter_User, setKey)
{
	zval *key, key_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &key);


	zephir_update_property_zval(this_ptr, ZEND_STRL("key"), key);
}

PHP_METHOD(Phalcon_Auth_Adapter_User, getAuthIdentifier)
{
	zval ident, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ident);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&ident, this_ptr, "getkey", NULL, 9);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property_zval(&_0, this_ptr, &ident, PH_NOISY_CC);
	RETURN_CCTOR(&_0);
}

PHP_METHOD(Phalcon_Auth_Adapter_User, getAuthPassword)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "password");
}

PHP_METHOD(Phalcon_Auth_Adapter_User, getKey)
{
	zval *this_ptr = getThis();



	RETURN_STRING("id");
}

PHP_METHOD(Phalcon_Auth_Adapter_User, getId)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "id");
}

