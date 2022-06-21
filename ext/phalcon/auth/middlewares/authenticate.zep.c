
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Middlewares_Authenticate)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Middlewares, Authenticate, phalcon, auth_middlewares_authenticate, zephir_get_internal_ce(SL("phalcon\\di\\injectable")), phalcon_auth_middlewares_authenticate_method_entry, 0);

	zend_declare_property_null(phalcon_auth_middlewares_authenticate_ce, SL("dispatcher"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_middlewares_authenticate_ce, SL("app"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_middlewares_authenticate_ce, SL("controllerClass"), ZEND_ACC_PROTECTED);
	zephir_declare_class_constant_string(phalcon_auth_middlewares_authenticate_ce, SL("PROPERTY_AUTH_ACCESS"), "authAccess");

	zephir_declare_class_constant_string(phalcon_auth_middlewares_authenticate_ce, SL("METHOD_AUTH_ACCESS"), "authAccess");

	zephir_declare_class_constant_bool(phalcon_auth_middlewares_authenticate_ce, SL("AUTH_ACCESS_BY_DEFAULT"), 1);

	zend_class_implements(phalcon_auth_middlewares_authenticate_ce, 1, phalcon_auth_middlewares_authenticatesrequestinterface_ce);
	zend_class_implements(phalcon_auth_middlewares_authenticate_ce, 1, zephir_get_internal_ce(SL("phalcon\\mvc\\micro\\middlewareinterface")));
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Middlewares_Authenticate, beforeDispatch)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, *dispatcher, dispatcher_sub, *exception, exception_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&dispatcher_sub);
	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(event)
		Z_PARAM_ZVAL(dispatcher)
		Z_PARAM_ZVAL(exception)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &event, &dispatcher, &exception);


	zephir_update_property_zval(this_ptr, ZEND_STRL("dispatcher"), dispatcher);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("dispatcher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getcontrollerclass", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("controllerClass"), &_1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "authenticate", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Middlewares_Authenticate, call)
{
	zend_bool _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *application, application_sub, _0, handler$$3, _1$$3, _3$$3, _4$$3, _5$$5, _6$$6, _7$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&application_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&handler$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(application, zephir_get_internal_ce(SL("phalcon\\mvc\\micro")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &application);


	zephir_update_property_zval(this_ptr, ZEND_STRL("app"), application);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("app"), PH_NOISY_CC);
	if (zephir_is_instance_of(&_0, SL("Phalcon\\Mvc\\Micro"))) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&handler$$3, &_1$$3, "getactivehandler", NULL, 0);
		zephir_check_call_status();
		_2$$3 = Z_TYPE_P(&handler$$3) != IS_ARRAY;
		if (_2$$3) {
			_2$$3 = !(zephir_array_isset_long(&handler$$3, 0));
		}
		if (_2$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Handler is not defined.", "phalcon/Auth/Middlewares/Authenticate.zep", 36);
			return;
		}
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_array_fetch_long(&_4$$3, &handler$$3, 0, PH_NOISY | PH_READONLY, "phalcon/Auth/Middlewares/Authenticate.zep", 39);
		zephir_gettype(&_3$$3, &_4$$3);
		do {
			if (ZEPHIR_IS_STRING(&_3$$3, "string")) {
				zephir_array_fetch_long(&_5$$5, &handler$$3, 0, PH_NOISY | PH_READONLY, "phalcon/Auth/Middlewares/Authenticate.zep", 41);
				zephir_update_property_zval(this_ptr, ZEND_STRL("controllerClass"), &_5$$5);
				break;
			}
			if (ZEPHIR_IS_STRING(&_3$$3, "object")) {
				zephir_array_fetch_long(&_6$$6, &handler$$3, 0, PH_NOISY | PH_READONLY, "phalcon/Auth/Middlewares/Authenticate.zep", 44);
				ZEPHIR_CALL_METHOD(&_7$$6, &_6$$6, "getdefinition", NULL, 0);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, ZEND_STRL("controllerClass"), &_7$$6);
				break;
			}
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Unknow typeof Handler.", "phalcon/Auth/Middlewares/Authenticate.zep", 47);
			return;
		} while(0);

	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "authenticate", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Middlewares_Authenticate, authenticate)
{
	zend_bool _5;
	zend_class_entry *_1;
	zval _0, _2, _3, _4, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);


	ZEPHIR_MM_GROW();

	_1 = zephir_fetch_class_str_ex(SL("Phalcon\\Di\\Di"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_CALL_CE_STATIC(&_0, _1, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "auth");
	ZEPHIR_CALL_METHOD(&_2, &_0, "getshared", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &_2, "authenticate", NULL, 0);
	zephir_check_call_status();
	_5 = zephir_is_true(&_4);
	if (!(_5)) {
		ZEPHIR_CALL_METHOD(&_6, this_ptr, "isguest", NULL, 0);
		zephir_check_call_status();
		_5 = zephir_is_true(&_6);
	}
	if (_5) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "unauthenticated", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Middlewares_Authenticate, unauthenticated)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "redirectto", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Middlewares_Authenticate, redirectTo)
{
	zval *this_ptr = getThis();



}

PHP_METHOD(Phalcon_Auth_Middlewares_Authenticate, setGuest)
{
	zval *guest, guest_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&guest_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(guest)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &guest);


	zephir_update_property_zval(this_ptr, ZEND_STRL("guest"), guest);
}

PHP_METHOD(Phalcon_Auth_Middlewares_Authenticate, isGuest)
{
	zend_bool _4, _6;
	zend_class_entry *_2;
	zval authAccess, controller, controllerClass, authAccessProperty, methodAccessProperty, _0, _1, _3, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&authAccess);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&controllerClass);
	ZVAL_UNDEF(&authAccessProperty);
	ZVAL_UNDEF(&methodAccessProperty);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&authAccessProperty);
	ZVAL_STRING(&authAccessProperty, "authAccess");
	ZEPHIR_INIT_VAR(&methodAccessProperty);
	ZVAL_STRING(&methodAccessProperty, "authAccess");
	zephir_read_property(&_0, this_ptr, ZEND_STRL("controllerClass"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&controllerClass, &_0);
	ZEPHIR_INIT_VAR(&controller);
	zephir_fetch_safe_class(&_1, &controllerClass);
	_2 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_1), Z_STRLEN_P(&_1), ZEND_FETCH_CLASS_AUTO);
	if(!_2) {
		RETURN_MM_NULL();
	}
	object_init_ex(&controller, _2);
	if (zephir_has_constructor(&controller)) {
		ZEPHIR_CALL_METHOD(NULL, &controller, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_CALL_FUNCTION(&_3, "property_exists", NULL, 21, &controller, &authAccessProperty);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZEPHIR_OBS_VAR(&authAccess);
		zephir_read_property_zval(&authAccess, &controller, &authAccessProperty, PH_NOISY_CC);
	} else {
		ZEPHIR_INIT_NVAR(&authAccess);
		ZVAL_BOOL(&authAccess, 1);
	}
	_4 = (zephir_method_exists(&controller, &methodAccessProperty)  == SUCCESS);
	if (_4) {
		ZEPHIR_CALL_METHOD_ZVAL(&_5, &controller, &methodAccessProperty, NULL, 0);
		zephir_check_call_status();
		_4 = !zephir_is_true(&_5);
	}
	_6 = _4;
	if (!(_6)) {
		_6 = ZEPHIR_IS_FALSE_IDENTICAL(&authAccess);
	}
	RETURN_MM_BOOL(_6);
}

