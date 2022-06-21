
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


ZEPHIR_INIT_CLASS(Phalcon_Auth_Providers_FileProvider)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth\\Providers, FileProvider, phalcon, auth_providers_fileprovider, phalcon_auth_providers_fileprovider_method_entry, 0);

	zend_declare_property_null(phalcon_auth_providers_fileprovider_ce, SL("collection"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_providers_fileprovider_ce, SL("hasher"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_providers_fileprovider_ce, SL("config"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_auth_providers_fileprovider_ce, 1, phalcon_auth_providers_providerinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Providers_FileProvider, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *hasher, hasher_sub, *config, config_sub, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hasher_sub);
	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(hasher)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &hasher, &config);


	zephir_update_property_zval(this_ptr, ZEND_STRL("hasher"), hasher);
	zephir_update_property_zval(this_ptr, ZEND_STRL("config"), config);
	zephir_read_property(&_2, config, ZEND_STRL("filepath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_auth_providers_fileprovider_parser_ce, "file", &_1, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("collection"), &_0);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Providers_FileProvider, retrieveByCredentials)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *credentials_param = NULL, _0;
	zval credentials;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(credentials)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &credentials_param);
	zephir_get_arrval(&credentials, credentials_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("collection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "first", NULL, 0, &credentials);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Providers_FileProvider, retrieveById)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *identifier, identifier_sub, data, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&identifier_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(identifier)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("collection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&data);
	zephir_array_fetch(&data, &_0, identifier, PH_NOISY, "phalcon/Auth/Providers/FileProvider.zep", 27);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_is_true(&data)) {
		object_init_ex(&_1, phalcon_auth_collection_user_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 8, &data);
		zephir_check_call_status();
	} else {
		ZVAL_NULL(&_1);
	}
	RETURN_CCTOR(&_1);
}

PHP_METHOD(Phalcon_Auth_Providers_FileProvider, validateCredentials)
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
		zephir_array_fetch_string(&_4, &credentials, SL("password"), PH_NOISY | PH_READONLY, "phalcon/Auth/Providers/FileProvider.zep", 34);
		ZEPHIR_CALL_METHOD(&_5, user, "getauthpassword", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_0, &_3, "checkhash", NULL, 0, &_4, &_5);
		zephir_check_call_status();
	} else {
		zephir_array_fetch_string(&_6, &credentials, SL("password"), PH_NOISY | PH_READONLY, "phalcon/Auth/Providers/FileProvider.zep", 35);
		ZEPHIR_CALL_METHOD(&_7, user, "getauthpassword", NULL, 0);
		zephir_check_call_status();
		ZVAL_BOOL(&_0, ZEPHIR_IS_IDENTICAL(&_6, &_7));
	}
	RETURN_CCTOR(&_0);
}

PHP_METHOD(Phalcon_Auth_Providers_FileProvider, createRememberToken)
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


	RETURN_BOOL(1);
}

PHP_METHOD(Phalcon_Auth_Providers_FileProvider, retrieveByToken)
{
	zval *identifier, identifier_sub, *token, token_sub, *user_agent, user_agent_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&identifier_sub);
	ZVAL_UNDEF(&token_sub);
	ZVAL_UNDEF(&user_agent_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(identifier)
		Z_PARAM_ZVAL(token)
		Z_PARAM_ZVAL(user_agent)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(3, 0, &identifier, &token, &user_agent);


	array_init(return_value);
	return;
}

