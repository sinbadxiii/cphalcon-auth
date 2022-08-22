
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


ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_CollectionAdapterAbstract)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth\\Adapter, CollectionAdapterAbstract, phalcon, auth_adapter_collectionadapterabstract, phalcon_auth_adapter_collectionadapterabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_auth_adapter_collectionadapterabstract_ce, SL("config"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_adapter_collectionadapterabstract_ce, SL("hasher"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_auth_adapter_collectionadapterabstract_ce, 1, phalcon_auth_adapter_adapterinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Adapter_CollectionAdapterAbstract, __construct)
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

PHP_METHOD(Phalcon_Auth_Adapter_CollectionAdapterAbstract, getData)
{
}

PHP_METHOD(Phalcon_Auth_Adapter_CollectionAdapterAbstract, retrieveByCredentials)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *credentials_param = NULL, collection, _0;
	zval credentials;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&collection);
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


	ZEPHIR_INIT_VAR(&collection);
	object_init_ex(&collection, phalcon_auth_adapter_usercollection_ce);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &collection, "__construct", NULL, 1, &_0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&collection, "first", NULL, 2, &credentials);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Adapter_CollectionAdapterAbstract, retrieveById)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *identifier, identifier_sub, collection, userData, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&identifier_sub);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&userData);
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


	ZEPHIR_INIT_VAR(&collection);
	object_init_ex(&collection, phalcon_auth_adapter_usercollection_ce);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &collection, "__construct", NULL, 1, &_0);
	zephir_check_call_status();
	zephir_array_fetch(&userData, &collection, identifier, PH_NOISY | PH_READONLY, "phalcon/Auth/Adapter/CollectionAdapterAbstract.zep", 32);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_is_true(&userData)) {
		object_init_ex(&_1, phalcon_auth_adapter_user_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 3, &userData);
		zephir_check_call_status();
	} else {
		ZVAL_NULL(&_1);
	}
	RETURN_CCTOR(&_1);
}

PHP_METHOD(Phalcon_Auth_Adapter_CollectionAdapterAbstract, validateCredentials)
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
		zephir_array_fetch_string(&_4, &credentials, SL("password"), PH_NOISY | PH_READONLY, "phalcon/Auth/Adapter/CollectionAdapterAbstract.zep", 40);
		ZEPHIR_CALL_METHOD(&_5, user, "getauthpassword", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_0, &_3, "checkhash", NULL, 0, &_4, &_5);
		zephir_check_call_status();
	} else {
		zephir_array_fetch_string(&_6, &credentials, SL("password"), PH_NOISY | PH_READONLY, "phalcon/Auth/Adapter/CollectionAdapterAbstract.zep", 41);
		ZEPHIR_CALL_METHOD(&_7, user, "getauthpassword", NULL, 0);
		zephir_check_call_status();
		ZVAL_BOOL(&_0, ZEPHIR_IS_IDENTICAL(&_6, &_7));
	}
	RETURN_CCTOR(&_0);
}

