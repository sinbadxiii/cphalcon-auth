
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
#include "kernel/operators.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Access_AbstractAccess)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Access, AbstractAccess, phalcon, auth_access_abstractaccess, zephir_get_internal_ce(SL("phalcon\\di\\injectable")), phalcon_auth_access_abstractaccess_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_auth_access_abstractaccess_ce, SL("exceptActions"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_access_abstractaccess_ce, SL("onlyActions"), ZEND_ACC_PROTECTED);
	phalcon_auth_access_abstractaccess_ce->create_object = zephir_init_properties_Phalcon_Auth_Access_AbstractAccess;

	zend_class_implements(phalcon_auth_access_abstractaccess_ce, 1, phalcon_auth_access_accessinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, setExceptActions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *exceptActions_param = NULL;
	zval exceptActions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exceptActions);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(exceptActions)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &exceptActions_param);
	if (!exceptActions_param) {
		ZEPHIR_INIT_VAR(&exceptActions);
		array_init(&exceptActions);
	} else {
		zephir_get_arrval(&exceptActions, exceptActions_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("exceptActions"), &exceptActions);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, getExceptActions)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "exceptActions");
}

PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, setOnlyActions)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_get_args(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("onlyActions"), &_0);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, getOnlyActions)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "onlyActions");
}

PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, redirectTo)
{
	zval *this_ptr = getThis();



}

PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, isAllowed)
{
	zend_bool _7, _1$$3, _4$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *actionName_param = NULL, isAllowed, _0, _3, _6, _8, _2$$3, _5$$5;
	zval actionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&isAllowed);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionName_param);
	zephir_get_strval(&actionName, actionName_param);


	ZEPHIR_CALL_METHOD(&isAllowed, this_ptr, "allowedif", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("exceptActions"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(&_0))) {
		_1$$3 = zephir_is_true(&isAllowed);
		if (!(_1$$3)) {
			zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("exceptActions"), PH_NOISY_CC | PH_READONLY);
			_1$$3 = zephir_fast_in_array(&actionName, &_2$$3);
		}
		if (_1$$3) {
			RETURN_MM_BOOL(1);
		}
	}
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("onlyActions"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(&_3))) {
		_4$$5 = zephir_is_true(&isAllowed);
		if (_4$$5) {
			zephir_read_property(&_5$$5, this_ptr, ZEND_STRL("onlyActions"), PH_NOISY_CC | PH_READONLY);
			_4$$5 = zephir_fast_in_array(&actionName, &_5$$5);
		}
		if (_4$$5) {
			RETURN_MM_BOOL(1);
		}
	}
	ZEPHIR_OBS_VAR(&_6);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("onlyActions"), PH_NOISY_CC);
	_7 = ZEPHIR_IS_EMPTY(&_6);
	if (_7) {
		ZEPHIR_OBS_VAR(&_8);
		zephir_read_property(&_8, this_ptr, ZEND_STRL("exceptActions"), PH_NOISY_CC);
		_7 = ZEPHIR_IS_EMPTY(&_8);
	}
	if (_7) {
		if (zephir_is_true(&isAllowed)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);
}

zend_object *zephir_init_properties_Phalcon_Auth_Access_AbstractAccess(zend_class_entry *class_type)
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("onlyActions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("onlyActions"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("exceptActions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("exceptActions"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

