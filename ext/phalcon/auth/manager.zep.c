
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Manager)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth, Manager, phalcon, auth_manager, phalcon_auth_manager_method_entry, 0);

	zend_declare_property_null(phalcon_auth_manager_ce, SL("config"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_manager_ce, SL("security"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_manager_ce, SL("guards"), ZEND_ACC_PROTECTED);
	phalcon_auth_manager_ce->create_object = zephir_init_properties_Phalcon_Auth_Manager;

	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Manager, __construct)
{
	zend_class_entry *_1$$3, *_8$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, *security = NULL, security_sub, __$null, _0$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$4, _7$$5, _9$$5, _10$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&security_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
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


	if (Z_TYPE_P(config) == IS_NULL) {
		_1$$3 = zephir_fetch_class_str_ex(SL("Phalcon\\Di\\Di"), ZEND_FETCH_CLASS_AUTO);
		ZEPHIR_CALL_CE_STATIC(&_0$$3, _1$$3, "getdefault", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "config");
		ZEPHIR_CALL_METHOD(&_2$$3, &_0$$3, "getshared", NULL, 0, &_3$$3);
		zephir_check_call_status();
		zephir_read_property(&_4$$3, &_2$$3, ZEND_STRL("auth"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, ZEND_STRL("config"), &_4$$3);
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_5$$3) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_6$$4);
			object_init_ex(&_6$$4, phalcon_auth_exceptions_configfilenotexistexception_ce);
			ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", NULL, 13);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$4, "phalcon/Auth/Manager.zep", 28);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (Z_TYPE_P(security) == IS_NULL) {
		_8$$5 = zephir_fetch_class_str_ex(SL("Phalcon\\Di\\Di"), ZEND_FETCH_CLASS_AUTO);
		ZEPHIR_CALL_CE_STATIC(&_7$$5, _8$$5, "getdefault", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$5);
		ZVAL_STRING(&_10$$5, "security");
		ZEPHIR_CALL_METHOD(&_9$$5, &_7$$5, "getshared", NULL, 0, &_10$$5);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("security"), &_9$$5);
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
	zephir_array_fetch(&_2, &_1, &name, PH_NOISY | PH_READONLY, "phalcon/Auth/Manager.zep", 46);
	if (Z_TYPE_P(&_2) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&_3$$5, this_ptr, "resolve", NULL, 0, &name);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("guards"), &name, &_3$$5);
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("guards"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_5, &_4, &name, PH_NOISY | PH_READONLY, "phalcon/Auth/Manager.zep", 50);
	RETURN_CTOR(&_5);
}

PHP_METHOD(Phalcon_Auth_Manager, resolve)
{
	zend_bool _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, configGuard, provider, guard, _4, _5, _6, _8, _0$$3, _1$$3, _2$$3, _9$$6, _10$$6, _11$$6, _12$$6;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&configGuard);
	ZVAL_UNDEF(&provider);
	ZVAL_UNDEF(&guard);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
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
		zephir_throw_exception_debug(&_0$$3, "phalcon/Auth/Manager.zep", 60);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&provider, this_ptr, "createprovider", NULL, 0, &configGuard);
	zephir_check_call_status();
	zephir_read_property(&_4, &configGuard, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING(&_4, "session")) {
		ZEPHIR_INIT_VAR(&guard);
		object_init_ex(&guard, phalcon_auth_guards_sessionguard_ce);
		ZEPHIR_CALL_METHOD(NULL, &guard, "__construct", NULL, 15, &name, &provider);
		zephir_check_call_status();
	}
	zephir_read_property(&_5, &configGuard, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING(&_5, "token")) {
		ZEPHIR_INIT_NVAR(&guard);
		object_init_ex(&guard, phalcon_auth_guards_tokenguard_ce);
		ZEPHIR_CALL_METHOD(NULL, &guard, "__construct", NULL, 16, &name, &provider);
		zephir_check_call_status();
	}
	zephir_read_property(&_6, &configGuard, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
	_7 = !ZEPHIR_IS_STRING_IDENTICAL(&_6, "session");
	if (_7) {
		zephir_read_property(&_8, &configGuard, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
		_7 = !ZEPHIR_IS_STRING_IDENTICAL(&_8, "token");
	}
	if (_7) {
		ZEPHIR_INIT_VAR(&_9$$6);
		object_init_ex(&_9$$6, spl_ce_InvalidArgumentException);
		zephir_read_property(&_10$$6, &configGuard, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_11$$6);
		ZVAL_STRING(&_11$$6, "Auth driver %s for guard %s is not defined.");
		ZEPHIR_CALL_FUNCTION(&_12$$6, "sprintf", &_3, 6, &_11$$6, &_10$$6, &name);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_9$$6, "__construct", NULL, 14, &_12$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_9$$6, "phalcon/Auth/Manager.zep", 86);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&guard);
}

PHP_METHOD(Phalcon_Auth_Manager, createProvider)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *configGuard = NULL, configGuard_sub, __$null, driver, provider, _0, _1, _2, _3, _4$$3, _5$$3, _6$$3, _7$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&configGuard_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&driver);
	ZVAL_UNDEF(&provider);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, &_0, ZEND_STRL("providers"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property_zval(&_2, &_1, &provider, PH_NOISY_CC);
	zephir_read_property(&_3, &_2, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING(&_3, "model")) {
		ZEPHIR_INIT_VAR(&driver);
		object_init_ex(&driver, phalcon_auth_providers_modelprovider_ce);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("security"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_6$$3);
		zephir_read_property(&_6$$3, &_5$$3, ZEND_STRL("providers"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&_7$$3);
		zephir_read_property_zval(&_7$$3, &_6$$3, &provider, PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, &driver, "__construct", NULL, 17, &_4$$3, &_7$$3);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&driver);
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
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

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
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

