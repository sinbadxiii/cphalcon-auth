
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Manager)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth, Manager, phalcon, auth_manager, phalcon_auth_manager_method_entry, 0);

	zend_declare_property_null(phalcon_auth_manager_ce, SL("guards"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_manager_ce, SL("activeAccess"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_manager_ce, SL("accessList"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_manager_ce, SL("defaultGuard"), ZEND_ACC_PROTECTED);
	phalcon_auth_manager_ce->create_object = zephir_init_properties_Phalcon_Auth_Manager;

	zend_class_implements(phalcon_auth_manager_ce, 1, phalcon_auth_managerinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Manager, guard)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, name_sub, __$null, _0, _3, _4, _1$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
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
		name = &__$null;
	}


	if (Z_TYPE_P(name) == IS_NULL) {
		RETURN_MM_MEMBER(getThis(), "defaultGuard");
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("guards"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, name))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SVS(&_2$$4, "Auth guard [", name, "] is not defined.");
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 4, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Auth/Manager.zep", 21);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("guards"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, name, PH_NOISY | PH_READONLY, "phalcon/Auth/Manager.zep", 24);
	RETURN_CTOR(&_4);
}

PHP_METHOD(Phalcon_Auth_Manager, getDefaultGuard)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "defaultGuard");
}

PHP_METHOD(Phalcon_Auth_Manager, setDefaultGuard)
{
	zval *guard, guard_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&guard_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(guard, phalcon_auth_guard_guardinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &guard);


	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultGuard"), guard);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Auth_Manager, addGuard)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool isDefault;
	zval *nameGuard_param = NULL, *guard, guard_sub, *isDefault_param = NULL;
	zval nameGuard;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&nameGuard);
	ZVAL_UNDEF(&guard_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(nameGuard)
		Z_PARAM_OBJECT_OF_CLASS(guard, phalcon_auth_guard_guardinterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(isDefault)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &nameGuard_param, &guard, &isDefault_param);
	zephir_get_strval(&nameGuard, nameGuard_param);
	if (!isDefault_param) {
		isDefault = 0;
	} else {
		isDefault = zephir_get_boolval(isDefault_param);
	}


	zephir_update_property_array(this_ptr, SL("guards"), &nameGuard, guard);
	if (isDefault == 1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultGuard"), guard);
	}
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Auth_Manager, getAccess)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "activeAccess");
}

PHP_METHOD(Phalcon_Auth_Manager, setAccess)
{
	zval *access, access_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&access_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(access, phalcon_auth_access_accessinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &access);


	zephir_update_property_zval(this_ptr, ZEND_STRL("activeAccess"), access);
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
		zephir_array_fetch(&_3, &_2, &accessName, PH_NOISY | PH_READONLY, "phalcon/Auth/Manager.zep", 78);
		_1 = !(zephir_class_exists(&_3, 1));
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "Access with '%s' name is not included in the access list");
		ZEPHIR_CALL_FUNCTION(&_6$$3, "sprintf", NULL, 5, &_5$$3, &accessName);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 4, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "phalcon/Auth/Manager.zep", 81);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_7, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&access);
	zephir_array_fetch(&access, &_7, &accessName, PH_NOISY, "phalcon/Auth/Manager.zep", 84);
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

	zephir_update_property_zval(this_ptr, ZEND_STRL("activeAccess"), &_8);
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Auth_Manager, except)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("activeAccess"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_get_args(&_1);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setexceptactions", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Auth_Manager, only)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("activeAccess"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_get_args(&_1);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setonlyactions", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_THIS();
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
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

