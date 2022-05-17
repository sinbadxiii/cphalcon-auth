
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Middlewares_Authenticate)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Middlewares, Authenticate, phalcon, auth_middlewares_authenticate, zephir_get_internal_ce(SL("phalcon\\di\\injectable")), phalcon_auth_middlewares_authenticate_method_entry, 0);

	zend_declare_property_null(phalcon_auth_middlewares_authenticate_ce, SL("dispatcher"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_middlewares_authenticate_ce, SL("app"), ZEND_ACC_PROTECTED);
	zephir_declare_class_constant_string(phalcon_auth_middlewares_authenticate_ce, SL("PROPERTY_AUTH_ACCESS"), "authAccess");

	zephir_declare_class_constant_bool(phalcon_auth_middlewares_authenticate_ce, SL("AUTH_ACCESS_BY_DEFAULT"), 1);

	zend_class_implements(phalcon_auth_middlewares_authenticate_ce, 1, phalcon_auth_middlewares_authenticatesrequestinterface_ce);
	zend_class_implements(phalcon_auth_middlewares_authenticate_ce, 1, zephir_get_internal_ce(SL("phalcon\\mvc\\micro\\middlewareinterface")));
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Middlewares_Authenticate, beforeDispatch)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, *dispatcher, dispatcher_sub, *exception, exception_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&dispatcher_sub);
	ZVAL_UNDEF(&exception_sub);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "authenticate", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Middlewares_Authenticate, call)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *application, application_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&application_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(application, zephir_get_internal_ce(SL("phalcon\\mvc\\micro")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &application);


	zephir_update_property_zval(this_ptr, ZEND_STRL("app"), application);
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
	zend_bool _10, _15;
	zend_class_entry *_9, *_13;
	zval controller, _0, authAccess, _5, _6, _7, _8, _11, _12, _14, _1$$3, _2$$3, _3$$3, _4$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&authAccess);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("app"), PH_NOISY_CC);
	if (zephir_is_instance_of(&_0, SL("Phalcon\\Mvc\\Micro"))) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("app"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_2$$3, &_1$$3, "getactivehandler", NULL, 0);
		zephir_check_call_status();
		zephir_array_fetch_long(&_3$$3, &_2$$3, 0, PH_NOISY | PH_READONLY, "phalcon/Auth/Middlewares/Authenticate.zep", 60);
		ZEPHIR_CALL_METHOD(&controller, &_3$$3, "getdefinition", NULL, 0);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("dispatcher"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&controller, &_4$$4, "getcontrollerclass", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "authAccess");
	ZEPHIR_CALL_FUNCTION(&_7, "property_exists", NULL, 15, &controller, &_6);
	zephir_check_call_status();
	if (zephir_is_true(&_7)) {
		ZEPHIR_INIT_NVAR(&_6);
		zephir_fetch_safe_class(&_8, &controller);
		_9 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_8), Z_STRLEN_P(&_8), ZEND_FETCH_CLASS_AUTO);
		if(!_9) {
			RETURN_MM_NULL();
		}
		object_init_ex(&_6, _9);
		if (zephir_has_constructor(&_6)) {
			ZEPHIR_CALL_METHOD(NULL, &_6, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZEPHIR_OBS_NVAR(&_5);
		zephir_read_property(&_5, &_6, ZEND_STRL("authAccess"), PH_NOISY_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_5);
		ZVAL_BOOL(&_5, 1);
	}
	ZEPHIR_CPY_WRT(&authAccess, &_5);
	_10 = (zephir_method_exists_ex(&controller, ZEND_STRL("authaccess")) == SUCCESS);
	if (_10) {
		ZEPHIR_INIT_VAR(&_11);
		zephir_fetch_safe_class(&_12, &controller);
		_13 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_12), Z_STRLEN_P(&_12), ZEND_FETCH_CLASS_AUTO);
		if(!_13) {
			RETURN_MM_NULL();
		}
		object_init_ex(&_11, _13);
		if (zephir_has_constructor(&_11)) {
			ZEPHIR_CALL_METHOD(NULL, &_11, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZEPHIR_CALL_METHOD(&_14, &_11, "authaccess", NULL, 0);
		zephir_check_call_status();
		_10 = !zephir_is_true(&_14);
	}
	_15 = _10;
	if (!(_15)) {
		_15 = ZEPHIR_IS_FALSE_IDENTICAL(&authAccess);
	}
	RETURN_MM_BOOL(_15);
}

