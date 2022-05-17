
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
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


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
	zend_bool _19, _24, _2$$3;
	zend_class_entry *_18, *_22;
	zval controller, authAccess, _0, _14, _15, _16, _17, _20, _21, _23, handler$$3, _1$$3, _7$$3, _8$$3, _3$$4, _4$$4, _5$$4, _9$$6, _10$$7, _11$$7, _12$$7, _13$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&authAccess);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&handler$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$8);


	ZEPHIR_MM_GROW();

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
			ZEPHIR_INIT_VAR(&_3$$4);
			object_init_ex(&_3$$4, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "Handler is not defined.");
			ZEPHIR_CALL_FUNCTION(&_5$$4, "sprintf", &_6, 6, &_4$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 14, &_5$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$4, "phalcon/Auth/Middlewares/Authenticate.zep", 64);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_7$$3);
		zephir_array_fetch_long(&_8$$3, &handler$$3, 0, PH_NOISY | PH_READONLY, "phalcon/Auth/Middlewares/Authenticate.zep", 67);
		zephir_gettype(&_7$$3, &_8$$3);
		do {
			if (ZEPHIR_IS_STRING(&_7$$3, "string")) {
				ZEPHIR_OBS_VAR(&controller);
				zephir_array_fetch_long(&controller, &handler$$3, 0, PH_NOISY, "phalcon/Auth/Middlewares/Authenticate.zep", 69);
				break;
			}
			if (ZEPHIR_IS_STRING(&_7$$3, "object")) {
				zephir_array_fetch_long(&_9$$6, &handler$$3, 0, PH_NOISY | PH_READONLY, "phalcon/Auth/Middlewares/Authenticate.zep", 72);
				ZEPHIR_CALL_METHOD(&controller, &_9$$6, "getdefinition", NULL, 0);
				zephir_check_call_status();
				break;
			}
			ZEPHIR_INIT_VAR(&_10$$7);
			object_init_ex(&_10$$7, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(&_11$$7);
			ZVAL_STRING(&_11$$7, "Unknow type Handler.");
			ZEPHIR_CALL_FUNCTION(&_12$$7, "sprintf", &_6, 6, &_11$$7);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_10$$7, "__construct", NULL, 14, &_12$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_10$$7, "phalcon/Auth/Middlewares/Authenticate.zep", 75);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

	} else {
		zephir_read_property(&_13$$8, this_ptr, ZEND_STRL("dispatcher"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&controller, &_13$$8, "getcontrollerclass", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_14);
	ZEPHIR_INIT_VAR(&_15);
	ZVAL_STRING(&_15, "authAccess");
	ZEPHIR_CALL_FUNCTION(&_16, "property_exists", NULL, 15, &controller, &_15);
	zephir_check_call_status();
	if (zephir_is_true(&_16)) {
		ZEPHIR_INIT_NVAR(&_15);
		zephir_fetch_safe_class(&_17, &controller);
		_18 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_17), Z_STRLEN_P(&_17), ZEND_FETCH_CLASS_AUTO);
		if(!_18) {
			RETURN_MM_NULL();
		}
		object_init_ex(&_15, _18);
		if (zephir_has_constructor(&_15)) {
			ZEPHIR_CALL_METHOD(NULL, &_15, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZEPHIR_OBS_NVAR(&_14);
		zephir_read_property(&_14, &_15, ZEND_STRL("authAccess"), PH_NOISY_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_14);
		ZVAL_BOOL(&_14, 1);
	}
	ZEPHIR_CPY_WRT(&authAccess, &_14);
	_19 = (zephir_method_exists_ex(&controller, ZEND_STRL("authaccess")) == SUCCESS);
	if (_19) {
		ZEPHIR_INIT_VAR(&_20);
		zephir_fetch_safe_class(&_21, &controller);
		_22 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_21), Z_STRLEN_P(&_21), ZEND_FETCH_CLASS_AUTO);
		if(!_22) {
			RETURN_MM_NULL();
		}
		object_init_ex(&_20, _22);
		if (zephir_has_constructor(&_20)) {
			ZEPHIR_CALL_METHOD(NULL, &_20, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZEPHIR_CALL_METHOD(&_23, &_20, "authaccess", NULL, 0);
		zephir_check_call_status();
		_19 = !zephir_is_true(&_23);
	}
	_24 = _19;
	if (!(_24)) {
		_24 = ZEPHIR_IS_FALSE_IDENTICAL(&authAccess);
	}
	RETURN_MM_BOOL(_24);
}

