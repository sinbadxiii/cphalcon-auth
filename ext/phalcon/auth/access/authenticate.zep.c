
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Access_Authenticate)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Access, Authenticate, phalcon, auth_access_authenticate, zephir_get_internal_ce(SL("phalcon\\di\\injectable")), phalcon_auth_access_authenticate_method_entry, 0);

	zend_declare_property_null(phalcon_auth_access_authenticate_ce, SL("accessList"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_access_authenticate_ce, SL("authManager"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_access_authenticate_ce, SL("actionName"), ZEND_ACC_PROTECTED);
	phalcon_auth_access_authenticate_ce->create_object = zephir_init_properties_Phalcon_Auth_Access_Authenticate;

	zend_class_implements(phalcon_auth_access_authenticate_ce, 1, phalcon_auth_access_authenticatesrequestinterface_ce);
	zend_class_implements(phalcon_auth_access_authenticate_ce, 1, zephir_get_internal_ce(SL("phalcon\\mvc\\micro\\middlewareinterface")));
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Access_Authenticate, __construct)
{
	zend_class_entry *_1$$3;
	zval _0, container$$3, authManager$$3, _2$$3, _3$$3, _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&container$$3);
	ZVAL_UNDEF(&authManager$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(&_0))) {
		_1$$3 = zephir_fetch_class_str_ex(SL("Phalcon\\Di\\Di"), ZEND_FETCH_CLASS_AUTO);
		ZEPHIR_CALL_CE_STATIC(&container$$3, _1$$3, "getdefault", NULL, 0);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&container$$3) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_ce_exception, "A dependency injection container is required to access the services related to the Auth", "phalcon/Auth/Access/Authenticate.zep", 30);
			return;
		}
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "auth");
		ZEPHIR_CALL_METHOD(&_2$$3, &container$$3, "getshared", NULL, 0, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&authManager$$3, &_2$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("authManager"), &authManager$$3);
		if (UNEXPECTED(Z_TYPE_P(&authManager$$3) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_ce_exception, "The injected service 'auth' is not valid", "phalcon/Auth/Access/Authenticate.zep", 39);
			return;
		}
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &authManager$$3, "addaccesslist", NULL, 0, &_4$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Access_Authenticate, beforeExecuteRoute)
{
	zend_bool _1$$4, _2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, *app, app_sub, *exception, exception_sub, _0$$3, handler$$4, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&app_sub);
	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&handler$$4);
	ZVAL_UNDEF(&_3$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(event, zephir_get_internal_ce(SL("phalcon\\events\\event")))
		Z_PARAM_ZVAL(app)
		Z_PARAM_ZVAL(exception)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &event, &app, &exception);


	if (zephir_is_instance_of(app, SL("Phalcon\\Mvc\\Dispatcher"))) {
		ZEPHIR_CALL_METHOD(&_0$$3, app, "getactionname", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("actionName"), &_0$$3);
	}
	if (zephir_is_instance_of(app, SL("Phalcon\\Mvc\\Micro"))) {
		ZEPHIR_CALL_METHOD(&handler$$4, app, "getactivehandler", NULL, 0);
		zephir_check_call_status();
		_1$$4 = Z_TYPE_P(&handler$$4) != IS_OBJECT;
		if (_1$$4) {
			_1$$4 = Z_TYPE_P(&handler$$4) != IS_ARRAY;
		}
		_2$$4 = _1$$4;
		if (_2$$4) {
			_2$$4 = !(zephir_array_isset_long(&handler$$4, 1));
		}
		if (_2$$4) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Handler is not defined.", "phalcon/Auth/Access/Authenticate.zep", 56);
			return;
		}
		zephir_array_fetch_long(&_3$$4, &handler$$4, 1, PH_NOISY | PH_READONLY, "phalcon/Auth/Access/Authenticate.zep", 59);
		zephir_update_property_zval(this_ptr, ZEND_STRL("actionName"), &_3$$4);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "authenticate", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Access_Authenticate, call)
{
	zval *app, app_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(app, zephir_get_internal_ce(SL("phalcon\\mvc\\micro")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &app);


	RETURN_BOOL(1);
}

PHP_METHOD(Phalcon_Auth_Access_Authenticate, authenticate)
{
	zval access, _0, _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&access);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("authManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&access, &_0, "getaccess", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&access) != IS_NULL) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("actionName"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_1$$3, &access, "isallowed", NULL, 0, &_2$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_1$$3)) {
			RETURN_MM_BOOL(1);
		}
		ZEPHIR_RETURN_CALL_METHOD(&access, "redirectto", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();
}

zend_object *zephir_init_properties_Phalcon_Auth_Access_Authenticate(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

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
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

