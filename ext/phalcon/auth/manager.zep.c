
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "Zend/zend_closures.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Manager)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth, Manager, phalcon, auth_manager, phalcon_auth_manager_method_entry, 0);

	zend_declare_property_null(phalcon_auth_manager_ce, SL("config"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_manager_ce, SL("security"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_manager_ce, SL("customGuards"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_manager_ce, SL("customAdapters"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_manager_ce, SL("guards"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_manager_ce, SL("access"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_manager_ce, SL("accessList"), ZEND_ACC_PROTECTED);
	phalcon_auth_manager_ce->create_object = zephir_init_properties_Phalcon_Auth_Manager;

	zend_class_implements(phalcon_auth_manager_ce, 1, phalcon_auth_managerinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Manager, __construct)
{
	zend_class_entry *_1$$3, *_8$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, *security = NULL, security_sub, __$null, _0$$3, _2$$3, _3$$3, _4$$3, _5, _6, _7$$5, _9$$5, _10$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&security_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(config, zephir_get_internal_ce(SL("phalcon\\config\\configinterface")))
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(security, zephir_get_internal_ce(SL("phalcon\\encryption\\security")))
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


	zephir_update_property_zval(this_ptr, ZEND_STRL("config"), config);
	if (Z_TYPE_P(config) == IS_NULL) {
		_1$$3 = zephir_fetch_class_str_ex(SL("Phalcon\\Di\\Di"), ZEND_FETCH_CLASS_AUTO);
		ZEPHIR_CALL_CE_STATIC(&_0$$3, _1$$3, "getdefault", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "config");
		ZEPHIR_CALL_METHOD(&_2$$3, &_0$$3, "getshared", NULL, 0, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "auth");
		ZEPHIR_CALL_METHOD(&_4$$3, &_2$$3, "get", NULL, 0, &_3$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("config"), &_4$$3);
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_5) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Configuration file auth.php (or key config->auth into your config) does not exist", "phalcon/Auth/Manager.zep", 36);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("security"), security);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("security"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_6) == IS_NULL) {
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
	zval *name = NULL, name_sub, __$null, _0, _1, _3, _4, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name);
	if (!name) {
		name = &name_sub;
		ZEPHIR_CPY_WRT(name, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(name);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (zephir_is_true(name)) {
		ZEPHIR_CPY_WRT(&_0, name);
	} else {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdefaultdriver", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CPY_WRT(name, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("guards"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_1, name))) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "resolve", NULL, 0, name);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("guards"), name, &_2$$3);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("guards"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, name, PH_NOISY | PH_READONLY, "phalcon/Auth/Manager.zep", 59);
	RETURN_CTOR(&_4);
}

PHP_METHOD(Phalcon_Auth_Manager, resolve)
{
	zend_class_entry *_15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, configGuard, providerAdapter, _2, _3, _4, guardName, _8, _9, _10, _14, _0$$3, _5$$4, _6$$4, _7$$4, _11$$5, _12$$5, _13$$5;
	zval name, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&configGuard);
	ZVAL_UNDEF(&providerAdapter);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&guardName);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
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
		ZEPHIR_CONCAT_SVS(&_1$$3, "Auth guard [", &name, "] is not defined.");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 8, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Auth/Manager.zep", 69);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_2, &configGuard, ZEND_STRL("provider"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&providerAdapter, this_ptr, "getadapterprovider", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("customGuards"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, &configGuard, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_3, &_4)) {
		zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("customGuards"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_7$$4);
		zephir_read_property(&_7$$4, &configGuard, ZEND_STRL("driver"), PH_NOISY_CC);
		zephir_array_fetch(&_6$$4, &_5$$4, &_7$$4, PH_NOISY | PH_READONLY, "phalcon/Auth/Manager.zep", 76);
		ZEPHIR_RETURN_CALL_FUNCTION("call_user_func", NULL, 21, &_6$$4, &providerAdapter, &configGuard, &name);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_8);
	zephir_read_property(&_9, &configGuard, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
	zephir_ucfirst(&_8, &_9);
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "\\Phalcon\\Auth\\Guard\\%s");
	ZEPHIR_CALL_FUNCTION(&guardName, "sprintf", NULL, 4, &_10, &_8);
	zephir_check_call_status();
	if (!(zephir_class_exists(&guardName, 1))) {
		ZEPHIR_INIT_VAR(&_11$$5);
		object_init_ex(&_11$$5, spl_ce_InvalidArgumentException);
		zephir_read_property(&_12$$5, &configGuard, ZEND_STRL("driver"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_13$$5);
		ZEPHIR_CONCAT_SVSVS(&_13$$5, "Auth driver ", &_12$$5, " for guard ", &name, " is not defined.");
		ZEPHIR_CALL_METHOD(NULL, &_11$$5, "__construct", NULL, 8, &_13$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$5, "phalcon/Auth/Manager.zep", 90);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_fetch_safe_class(&_14, &guardName);
	_15 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_14), Z_STRLEN_P(&_14), ZEND_FETCH_CLASS_AUTO);
	if(!_15) {
		RETURN_MM_NULL();
	}
	object_init_ex(return_value, _15);
	if (zephir_has_constructor(return_value)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &providerAdapter, &configGuard, &name);
		zephir_check_call_status();
	}

	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Manager, getAdapterProvider)
{
	zend_class_entry *_14;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *provider_param = NULL, configProvider, _0, _1, adapterName, _4, adapterClass, _8, _9, adapter, _13, _15, _2$$4, _5$$5, _6$$5, _7$$5, _10$$6, _11$$6, _12$$6, _16$$7, _17$$7, _18$$8, _19$$8;
	zval provider, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&provider);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&configProvider);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&adapterName);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&adapterClass);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(provider)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &provider_param);
	if (!provider_param) {
		ZEPHIR_INIT_VAR(&provider);
	} else {
		zephir_get_strval(&provider, provider_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, &_0, ZEND_STRL("providers"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&configProvider);
	zephir_read_property_zval(&configProvider, &_1, &provider, PH_NOISY_CC);
	if (Z_TYPE_P(&configProvider) == IS_NULL) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(&adapterName);
	zephir_read_property(&adapterName, &configProvider, ZEND_STRL("adapter"), PH_NOISY_CC);
	if (Z_TYPE_P(&adapterName) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_CONCAT_SVS(&_3$$4, "Adapter not assigned in config->auth->providers->", &provider, "->adapter = ?");
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 8, &_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Auth/Manager.zep", 110);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("customAdapters"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_4, &adapterName)) {
		zephir_read_property(&_5$$5, this_ptr, ZEND_STRL("customAdapters"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_6$$5, &_5$$5, &adapterName, PH_NOISY | PH_READONLY, "phalcon/Auth/Manager.zep", 115);
		zephir_read_property(&_7$$5, this_ptr, ZEND_STRL("security"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_FUNCTION("call_user_func", NULL, 21, &_6$$5, &_7$$5, &configProvider);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_8);
	zephir_ucfirst(&_8, &adapterName);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "\\Phalcon\\Auth\\Adapter\\%s");
	ZEPHIR_CALL_FUNCTION(&adapterClass, "sprintf", NULL, 4, &_9, &_8);
	zephir_check_call_status();
	if (!(zephir_class_exists(&adapterClass, 1))) {
		ZEPHIR_INIT_VAR(&_10$$6);
		object_init_ex(&_10$$6, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_11$$6);
		ZVAL_STRING(&_11$$6, "%s not found.");
		ZEPHIR_CALL_FUNCTION(&_12$$6, "sprintf", NULL, 4, &_11$$6, &adapterClass);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_10$$6, "__construct", NULL, 8, &_12$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$6, "phalcon/Auth/Manager.zep", 128);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&adapter);
	zephir_fetch_safe_class(&_13, &adapterClass);
	_14 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_13), Z_STRLEN_P(&_13), ZEND_FETCH_CLASS_AUTO);
	if(!_14) {
		RETURN_MM_NULL();
	}
	object_init_ex(&adapter, _14);
	if (zephir_has_constructor(&adapter)) {
		zephir_read_property(&_15, this_ptr, ZEND_STRL("security"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &adapter, "__construct", NULL, 0, &_15, &configProvider);
		zephir_check_call_status();
	}

	if (!(zephir_instance_of_ev(&adapter, phalcon_auth_adapter_adapterinterface_ce))) {
		ZEPHIR_INIT_VAR(&_16$$7);
		object_init_ex(&_16$$7, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_17$$7);
		ZEPHIR_CONCAT_VS(&_17$$7, &adapterClass, " not implementing AdapterInterface");
		ZEPHIR_CALL_METHOD(NULL, &_16$$7, "__construct", NULL, 8, &_17$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_16$$7, "phalcon/Auth/Manager.zep", 135);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(zephir_instance_of_ev(&adapter, phalcon_auth_adapter_adapterinterface_ce))) {
		ZEPHIR_INIT_VAR(&_18$$8);
		object_init_ex(&_18$$8, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_19$$8);
		ZEPHIR_CONCAT_VS(&_19$$8, &adapterClass, " not implementing AdapterInterface");
		ZEPHIR_CALL_METHOD(NULL, &_18$$8, "__construct", NULL, 8, &_19$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_18$$8, "phalcon/Auth/Manager.zep", 139);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&adapter);
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

PHP_METHOD(Phalcon_Auth_Manager, addGuard)
{
	zval *driver, driver_sub, *callback, callback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&driver_sub);
	ZVAL_UNDEF(&callback_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(driver)
		Z_PARAM_OBJECT_OF_CLASS(callback, zend_ce_closure)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(2, 0, &driver, &callback);


	zephir_update_property_array(this_ptr, SL("customGuards"), driver, callback);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Auth_Manager, addProviderAdapter)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *callback, callback_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&callback_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OBJECT_OF_CLASS(callback, zend_ce_closure)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &callback);
	zephir_get_strval(&name, name_param);


	zephir_update_property_array(this_ptr, SL("customAdapters"), &name, callback);
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Auth_Manager, getAccess)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "access");
}

PHP_METHOD(Phalcon_Auth_Manager, setAccess)
{
	zval *access, access_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&access_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(access, zephir_get_internal_ce(SL("phalcon\\auth\\access\\accessinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &access);


	zephir_update_property_zval(this_ptr, ZEND_STRL("access"), access);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Auth_Manager, setAccessList)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *accessList_param = NULL;
	zval accessList;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&accessList);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(accessList)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &accessList_param);
	zephir_get_arrval(&accessList, accessList_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("accessList"), &accessList);
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Auth_Manager, addAccessList)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *accessList_param = NULL;
	zval accessList;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&accessList);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(accessList)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &accessList_param);
	zephir_get_arrval(&accessList, accessList_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("accessList"), &accessList);
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Auth_Manager, access)
{
	zend_class_entry *_10;
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *accessName_param = NULL, _0, _2, _3, access, _7, _8, _9, _4$$3, _5$$3, _6$$3;
	zval accessName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&access);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(accessName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &accessName_param);
	zephir_get_strval(&accessName, accessName_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
	_1 = !(zephir_array_isset(&_0, &accessName));
	if (!(_1)) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3, &_2, &accessName, PH_NOISY | PH_READONLY, "phalcon/Auth/Manager.zep", 192);
		_1 = !(zephir_class_exists(&_3, 1));
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "Access with '%s' name is not included in the access list");
		ZEPHIR_CALL_FUNCTION(&_6$$3, "sprintf", NULL, 4, &_5$$3, &accessName);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 8, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "phalcon/Auth/Manager.zep", 195);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_7, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&access);
	zephir_array_fetch(&access, &_7, &accessName, PH_NOISY, "phalcon/Auth/Manager.zep", 198);
	ZEPHIR_INIT_VAR(&_8);
	zephir_fetch_safe_class(&_9, &access);
	_10 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_9), Z_STRLEN_P(&_9), ZEND_FETCH_CLASS_AUTO);
	if(!_10) {
		RETURN_MM_NULL();
	}
	object_init_ex(&_8, _10);
	if (zephir_has_constructor(&_8)) {
		ZEPHIR_CALL_METHOD(NULL, &_8, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_update_property_zval(this_ptr, ZEND_STRL("access"), &_8);
	RETURN_MM_MEMBER(getThis(), "access");
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
		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("accessList"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("guards"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("guards"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("customAdapters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("customAdapters"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("customGuards"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("customGuards"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

