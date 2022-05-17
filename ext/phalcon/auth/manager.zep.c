
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Manager)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth, Manager, phalcon, auth_manager, phalcon_auth_manager_method_entry, 0);

	zend_declare_property_null(phalcon_auth_manager_ce, SL("config"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_manager_ce, SL("security"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_manager_ce, SL("customGuards"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_manager_ce, SL("guards"), ZEND_ACC_PROTECTED);
	phalcon_auth_manager_ce->create_object = zephir_init_properties_Phalcon_Auth_Manager;

	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Manager, __construct)
{
	zend_class_entry *_2, *_8$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, *security = NULL, security_sub, __$null, _0, _1, _3, _4, _5, _6$$3, _7$$4, _9$$4, _10$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&security_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(config, zephir_get_internal_ce(SL("phalcon\\config\\configinterface")))
		Z_PARAM_ZVAL_OR_NULL(security)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &config, &security);
	if (!config) {
		config = &config_sub;
		config = &__$null;
	}
	if (!security) {
		security = &security_sub;
		security = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	if (zephir_is_true(config)) {
		ZEPHIR_CPY_WRT(&_0, config);
	} else {
		_2 = zephir_fetch_class_str_ex(SL("Phalcon\\Di\\Di"), ZEND_FETCH_CLASS_AUTO);
		ZEPHIR_CALL_CE_STATIC(&_1, _2, "getdefault", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_STRING(&_4, "config");
		ZEPHIR_CALL_METHOD(&_3, &_1, "getshared", NULL, 0, &_4);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&_0);
		zephir_read_property(&_0, &_3, ZEND_STRL("auth"), PH_NOISY_CC);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("config"), &_0);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_5) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_6$$3);
		object_init_ex(&_6$$3, phalcon_auth_exceptions_configfilenotexistexception_ce);
		ZEPHIR_CALL_METHOD(NULL, &_6$$3, "__construct", NULL, 13);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$3, "phalcon/Auth/Manager.zep", 25);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(security) == IS_NULL) {
		_8$$4 = zephir_fetch_class_str_ex(SL("Phalcon\\Di\\Di"), ZEND_FETCH_CLASS_AUTO);
		ZEPHIR_CALL_CE_STATIC(&_7$$4, _8$$4, "getdefault", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$4);
		ZVAL_STRING(&_10$$4, "security");
		ZEPHIR_CALL_METHOD(&_9$$4, &_7$$4, "getshared", NULL, 0, &_10$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("security"), &_9$$4);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Manager, getConfigGuard)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _0, _1, _2;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, &_0, ZEND_STRL("guards"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property_zval(&_2, &_1, &name, PH_NOISY_CC);
	RETURN_CCTOR(&_2);
}

PHP_METHOD(Phalcon_Auth_Manager, guard)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _1, _2, _4, _5, _3$$5;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(!(ZEPHIR_IS_EMPTY(&name)))) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdefaultdriver", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&_0, &name);
	}
	zephir_get_strval(&name, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("guards"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_2, &_1, &name, PH_NOISY | PH_READONLY, "phalcon/Auth/Manager.zep", 43);
	if (Z_TYPE_P(&_2) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&_3$$5, this_ptr, "resolve", NULL, 0, &name);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("guards"), &name, &_3$$5);
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("guards"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_5, &_4, &name, PH_NOISY | PH_READONLY, "phalcon/Auth/Manager.zep", 47);
	RETURN_CTOR(&_5);
}

PHP_METHOD(Phalcon_Auth_Manager, resolve)
{
	zend_class_entry *_14;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, configGuard, _4, _5, provider, guard, guardName, _6, _7, _8, _13, _0$$3, _1$$3, _2$$3, _9$$5, _10$$5, _11$$5, _12$$5;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&configGuard);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&provider);
	ZVAL_UNDEF(&guard);
	ZVAL_UNDEF(&guardName);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(&configGuard, this_ptr, "getconfigguard", NULL, 0, &name);
	zephir_check_call_status();
	if (Z_TYPE_P(&configGuard) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Auth guard [%s] is not defined.");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "sprintf", &_3, 6, &_1$$3, &name);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 14, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Auth/Manager.zep", 57);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("customGuards"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_5, &configGuard, SL("driver"), PH_READONLY, "phalcon/Auth/Manager.zep", 60);
	if (zephir_array_isset(&_4, &_5)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callcustomguard", NULL, 0, &name, &configGuard);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&provider, this_ptr, "createprovider", NULL, 0, &configGuard);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	zephir_read_property(&_7, &configGuard, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
	zephir_ucfirst(&_6, &_7);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "\\Phalcon\\Auth\\Guards\\%sGuard");
	ZEPHIR_CALL_FUNCTION(&guardName, "sprintf", &_3, 6, &_8, &_6);
	zephir_check_call_status();
	if (!(zephir_class_exists(&guardName, 1))) {
		ZEPHIR_INIT_VAR(&_9$$5);
		object_init_ex(&_9$$5, spl_ce_InvalidArgumentException);
		zephir_read_property(&_10$$5, &configGuard, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_11$$5);
		ZVAL_STRING(&_11$$5, "Auth driver %s for guard %s is not defined.");
		ZEPHIR_CALL_FUNCTION(&_12$$5, "sprintf", &_3, 6, &_11$$5, &_10$$5, &name);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_9$$5, "__construct", NULL, 14, &_12$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_9$$5, "phalcon/Auth/Manager.zep", 80);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&guard);
	zephir_fetch_safe_class(&_13, &guardName);
	_14 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_13), Z_STRLEN_P(&_13), ZEND_FETCH_CLASS_AUTO);
	if(!_14) {
		RETURN_MM_NULL();
	}
	object_init_ex(&guard, _14);
	if (zephir_has_constructor(&guard)) {
		ZEPHIR_CALL_METHOD(NULL, &guard, "__construct", NULL, 0, &name, &provider);
		zephir_check_call_status();
	}

	RETURN_CCTOR(&guard);
}

PHP_METHOD(Phalcon_Auth_Manager, createProvider)
{
	zend_class_entry *_10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *configGuard = NULL, configGuard_sub, __$null, provider, _0, driver, _1, _2, _3, _4, _5, _9, _11, _12, _13, _14, _6$$3, _7$$3, _8$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&configGuard_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&provider);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&driver);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(configGuard)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &configGuard);
	if (!configGuard) {
		configGuard = &configGuard_sub;
		configGuard = &__$null;
	}


	zephir_read_property(&_0, configGuard, ZEND_STRL("provider"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&provider, &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, &_0, ZEND_STRL("providers"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property_zval(&_3, &_2, &provider, PH_NOISY_CC);
	zephir_read_property(&_4, &_3, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
	zephir_ucfirst(&_1, &_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "\\Phalcon\\Auth\\Providers\\%sProvider");
	ZEPHIR_CALL_FUNCTION(&driver, "sprintf", NULL, 6, &_5, &_1);
	zephir_check_call_status();
	if (!(zephir_class_exists(&driver, 1))) {
		ZEPHIR_INIT_VAR(&_6$$3);
		object_init_ex(&_6$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "Provider %s is not defined.");
		ZEPHIR_CALL_FUNCTION(&_8$$3, "sprintf", NULL, 6, &_7$$3, &provider);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_6$$3, "__construct", NULL, 14, &_8$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$3, "phalcon/Auth/Manager.zep", 102);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_fetch_safe_class(&_9, &driver);
	_10 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_9), Z_STRLEN_P(&_9), ZEND_FETCH_CLASS_AUTO);
	if(!_10) {
		RETURN_MM_NULL();
	}
	object_init_ex(return_value, _10);
	if (zephir_has_constructor(return_value)) {
		zephir_read_property(&_11, this_ptr, ZEND_STRL("security"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_12, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_13);
		zephir_read_property(&_13, &_12, ZEND_STRL("providers"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&_14);
		zephir_read_property_zval(&_14, &_13, &provider, PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_11, &_14);
		zephir_check_call_status();
	}

	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Manager, getDefaultDriver)
{
	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, &_0, ZEND_STRL("defaults"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, &_1, ZEND_STRL("guard"), PH_NOISY_CC);
	RETURN_CCTOR(&_2);
}

PHP_METHOD(Phalcon_Auth_Manager, extend)
{
	zval *driver, driver_sub, *callback, callback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&driver_sub);
	ZVAL_UNDEF(&callback_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(driver)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(2, 0, &driver, &callback);


	zephir_update_property_array(this_ptr, SL("customGuards"), driver, callback);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Auth_Manager, callCustomGuard)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *config, config_sub, customGuard, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&customGuard);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OBJECT_OF_CLASS(config, zephir_get_internal_ce(SL("phalcon\\config\\configinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &config);
	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("customGuards"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&customGuard);
	ZEPHIR_OBS_VAR(&_1);
	zephir_array_fetch_string(&_1, config, SL("driver"), PH_NOISY, "phalcon/Auth/Manager.zep", 122);
	zephir_array_fetch(&customGuard, &_0, &_1, PH_NOISY, "phalcon/Auth/Manager.zep", 122);
	ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(&customGuard, NULL, 0, &name, config);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Manager, __call)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method, method_sub, *params, params_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(method)
		Z_PARAM_ZVAL(params)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method, &params);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "guard", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, params);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Auth_Manager(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("guards"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("guards"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("customGuards"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("customGuards"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

