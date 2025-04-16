
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
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_Session)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Guard, Session, phalcon, auth_guard_session, zephir_get_internal_ce(SL("phalcon\\events\\abstracteventsaware")), phalcon_auth_guard_session_method_entry, 0);

	zend_declare_property_null(phalcon_auth_guard_session_ce, SL("session"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_guard_session_ce, SL("cookies"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_guard_session_ce, SL("request"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_guard_session_ce, SL("eventsManager"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_guard_session_ce, SL("lastUserAttempted"), ZEND_ACC_PROTECTED);
	zend_declare_property_bool(phalcon_auth_guard_session_ce, SL("viaRemember"), 0, ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_guard_session_ce, SL("adapter"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_guard_session_ce, SL("user"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_auth_guard_session_ce, 1, phalcon_auth_guard_guardinterface_ce);
	zend_class_implements(phalcon_auth_guard_session_ce, 1, phalcon_auth_guard_guardstatefulinterface_ce);
	zend_class_implements(phalcon_auth_guard_session_ce, 1, phalcon_auth_guard_basicauthinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Guard_Session, __construct)
{
	zval *adapter, adapter_sub, *session, session_sub, *cookies, cookies_sub, *request, request_sub, *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter_sub);
	ZVAL_UNDEF(&session_sub);
	ZVAL_UNDEF(&cookies_sub);
	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&eventsManager_sub);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(adapter, phalcon_auth_adapter_adapterinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(session, zephir_get_internal_ce(SL("phalcon\\session\\managerinterface")))
		Z_PARAM_OBJECT_OF_CLASS(cookies, zephir_get_internal_ce(SL("phalcon\\http\\response\\cookies")))
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("phalcon\\http\\request")))
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, zephir_get_internal_ce(SL("phalcon\\events\\managerinterface")))
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &adapter, &session, &cookies, &request, &eventsManager);
	zephir_update_property_zval(this_ptr, ZEND_STRL("adapter"), adapter);
	zephir_update_property_zval(this_ptr, ZEND_STRL("session"), session);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cookies"), cookies);
	zephir_update_property_zval(this_ptr, ZEND_STRL("request"), request);
	zephir_update_property_zval(this_ptr, ZEND_STRL("eventsManager"), eventsManager);
}

PHP_METHOD(Phalcon_Auth_Guard_Session, attempt)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool remember;
	zval *credentials_param = NULL, *remember_param = NULL, _0, _1, _2, _3, _4$$3, _5$$3;
	zval credentials;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(credentials)
		Z_PARAM_BOOL(remember)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &credentials_param, &remember_param);
	if (!credentials_param) {
		ZEPHIR_INIT_VAR(&credentials);
		array_init(&credentials);
	} else {
		zephir_get_arrval(&credentials, credentials_param);
	}
	if (!remember_param) {
		remember = 0;
	} else {
		}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "retrievebycredentials", NULL, 0, &credentials);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("lastUserAttempted"), &_1);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("lastUserAttempted"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "hasvalidcredentials", NULL, 0, &_3, &credentials);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("lastUserAttempted"), PH_NOISY_CC | PH_READONLY);
		if (remember) {
			ZVAL_BOOL(&_5$$3, 1);
		} else {
			ZVAL_BOOL(&_5$$3, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "login", NULL, 0, &_4$$3, &_5$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);
}

PHP_METHOD(Phalcon_Auth_Guard_Session, user)
{
	zend_bool _6;
	zval _0, id, recaller, _1, _2, _5, _3$$4, _4$$4, _7$$5, _8$$5, _9$$6, _10$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&recaller);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("user"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		RETURN_MM_MEMBER(getThis(), "user");
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("session"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&id, &_1, "get", NULL, 0, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&id) != IS_NULL) {
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4$$4, &_3$$4, "retrievebyid", NULL, 0, &id);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("user"), &_4$$4);
	}
	ZEPHIR_CALL_METHOD(&recaller, this_ptr, "recaller", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, ZEND_STRL("user"), PH_NOISY_CC | PH_READONLY);
	_6 = Z_TYPE_P(&_5) != IS_NULL;
	if (_6) {
		_6 = Z_TYPE_P(&recaller) != IS_NULL;
	}
	if (_6) {
		ZEPHIR_CALL_METHOD(&_7$$5, this_ptr, "userfromrecaller", NULL, 0, &recaller);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("user"), &_7$$5);
		zephir_read_property(&_8$$5, this_ptr, ZEND_STRL("user"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_8$$5)) {
			zephir_read_property(&_9$$6, this_ptr, ZEND_STRL("user"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_10$$6, &_9$$6, "getauthidentifier", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "updatesession", NULL, 0, &_10$$6);
			zephir_check_call_status();
		}
	}
	RETURN_MM_MEMBER(getThis(), "user");
}

PHP_METHOD(Phalcon_Auth_Guard_Session, hasValidCredentials)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval credentials;
	zval *user, user_sub, *credentials_param = NULL, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&credentials);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(user)
		Z_PARAM_ARRAY(credentials)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &user, &credentials_param);
	zephir_get_arrval(&credentials, credentials_param);
	_0 = Z_TYPE_P(user) != IS_NULL;
	if (_0) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_2, &_1, "validatecredentials", NULL, 0, user, &credentials);
		zephir_check_call_status();
		_0 = zephir_is_true(&_2);
	}
	RETURN_MM_BOOL(_0);
}

PHP_METHOD(Phalcon_Auth_Guard_Session, validate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *credentials_param = NULL, _0, _1, _2;
	zval credentials;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(credentials)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &credentials_param);
	if (!credentials_param) {
		ZEPHIR_INIT_VAR(&credentials);
		array_init(&credentials);
	} else {
		zephir_get_arrval(&credentials, credentials_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "retrievebycredentials", NULL, 0, &credentials);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("lastUserAttempted"), &_1);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("lastUserAttempted"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hasvalidcredentials", NULL, 0, &_2, &credentials);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, userFromRecaller)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *recaller, recaller_sub, __$true, __$false, user, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&recaller_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(recaller)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &recaller);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, recaller, "id", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, recaller, "token", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, recaller, "useragent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&user, &_0, "retrievebytoken", NULL, 0, &_1, &_2, &_3);
	zephir_check_call_status();
	if (Z_TYPE_P(&user) != IS_NULL) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("viaRemember"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("viaRemember"), &__$false);
	}
	RETURN_CCTOR(&user);
}

PHP_METHOD(Phalcon_Auth_Guard_Session, recaller)
{
	zval recaller;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&recaller);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&recaller, this_ptr, "getrememberdata", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&recaller)) {
		object_init_ex(return_value, phalcon_auth_guard_userremember_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 10, &recaller);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, getRememberData)
{
	zval _0, _1, _2, _3$$3, _4$$3, _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getremembername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &_0, "has", NULL, 0, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "getremembername", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, &_3$$3, "get", NULL, 0, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&_4$$3, "getvalue", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, getName)
{
	zval _0, _1, _2, _3, _4, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, this_ptr, 0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	zephir_get_class(&_1, &_2, 0);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VV(&_3, &_0, &_1);
	ZEPHIR_CALL_FUNCTION(&_4, "sha1", NULL, 11, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "auth_%s");
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", NULL, 5, &_5, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, getRememberName)
{
	zval _0, _1, _2, _3, _4, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, this_ptr, 0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	zephir_get_class(&_1, &_2, 0);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VV(&_3, &_0, &_1);
	ZEPHIR_CALL_FUNCTION(&_4, "sha1", NULL, 11, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "remember_%s");
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", NULL, 5, &_5, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, login)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool remember;
	zval *user, user_sub, *remember_param = NULL, _0, _1, _2, _8, _3$$3, _4$$4, _5$$4, _6$$4, _7$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(user, phalcon_auth_authenticatableinterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(remember)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &user, &remember_param);
	if (!remember_param) {
		remember = 0;
	} else {
		}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "auth:beforeLogin");
	ZEPHIR_CALL_METHOD(NULL, &_0, "fire", NULL, 0, &_1, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, user, "getauthidentifier", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "updatesession", NULL, 0, &_2);
	zephir_check_call_status();
	if (remember) {
		zephir_memory_observe(&_3$$3);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC);
		if (!(zephir_instance_of_ev(&_3$$3, phalcon_auth_adapter_adapterwithremembertokeninterface_ce))) {
			ZEPHIR_INIT_VAR(&_4$$4);
			object_init_ex(&_4$$4, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(&_5$$4);
			zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
			zephir_get_class(&_5$$4, &_6$$4, 0);
			ZEPHIR_INIT_VAR(&_7$$4);
			ZEPHIR_CONCAT_SVS(&_7$$4, "Adapter ", &_5$$4, " not instanceof AdapterWithRememberTokenInterface");
			ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 4, &_7$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$4, "phalcon/Auth/Guard/Session.zep", 140);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "rememberuser", NULL, 0, user);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setuser", NULL, 0, user);
	zephir_check_call_status();
	zephir_read_property(&_8, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "auth:afterLogin");
	ZEPHIR_CALL_METHOD(NULL, &_8, "fire", NULL, 0, &_1, this_ptr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, loginById)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool remember;
	zval *id, id_sub, *remember_param = NULL, user, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(id)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(remember)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &id, &remember_param);
	if (!remember_param) {
		remember = 0;
	} else {
		}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&user, &_0, "retrievebyid", NULL, 0, id);
	zephir_check_call_status();
	if (Z_TYPE_P(&user) != IS_NULL) {
		if (remember) {
			ZVAL_BOOL(&_1$$3, 1);
		} else {
			ZVAL_BOOL(&_1$$3, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "login", NULL, 0, &user, &_1$$3);
		zephir_check_call_status();
		RETURN_CCTOR(&user);
	}
	RETURN_MM_BOOL(0);
}

PHP_METHOD(Phalcon_Auth_Guard_Session, once)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *credentials_param = NULL, _0, _1, _2, _3$$3, _4$$3, _5$$3;
	zval credentials;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(credentials)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &credentials_param);
	if (!credentials_param) {
		ZEPHIR_INIT_VAR(&credentials);
		array_init(&credentials);
	} else {
		zephir_get_arrval(&credentials, credentials_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "auth:beforeLogin");
	ZEPHIR_CALL_METHOD(NULL, &_0, "fire", NULL, 0, &_1, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "validate", NULL, 0, &credentials);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("lastUserAttempted"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setuser", NULL, 0, &_3$$3);
		zephir_check_call_status();
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "auth:afterLogin");
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "fire", NULL, 0, &_5$$3, this_ptr);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);
}

PHP_METHOD(Phalcon_Auth_Guard_Session, rememberUser)
{
	zval _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *user, user_sub, rememberToken, _0$$3, _1$$3, _2$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&rememberToken);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_3$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(user, phalcon_auth_authenticatableinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &user);
	ZEPHIR_CALL_METHOD(&rememberToken, this_ptr, "createremembertoken", NULL, 0, user);
	zephir_check_call_status();
	if (Z_TYPE_P(&rememberToken) != IS_NULL) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "getremembername", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 3, 0);
		ZEPHIR_CALL_METHOD(&_4$$3, user, "getauthidentifier", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&_3$$3, SL("id"), &_4$$3, PH_COPY | PH_SEPARATE);
		zephir_memory_observe(&_5$$3);
		zephir_read_property(&_5$$3, &rememberToken, ZEND_STRL("token"), PH_NOISY_CC);
		zephir_array_update_string(&_3$$3, SL("token"), &_5$$3, PH_COPY | PH_SEPARATE);
		zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4$$3, &_6$$3, "getuseragent", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&_3$$3, SL("user_agent"), &_4$$3, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_7$$3, 4194304);
		zephir_json_encode(&_2$$3, &_3$$3, zephir_get_intval(&_7$$3) );
		ZEPHIR_INIT_VAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "U");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "date", NULL, 12, &_8$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_9$$3, (zephir_get_numberval(&_4$$3) + ((8640 * 60) * 60)));
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "set", NULL, 0, &_1$$3, &_2$$3, &_9$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, createRememberToken)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *user, user_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(user, phalcon_auth_authenticatableinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &user);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "createremembertoken", NULL, 0, user);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, updateSession)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(id)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &id);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("session"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &_1, id);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, logout)
{
	zval _1, _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, user, _0, _2, recaller, _6, _7, _8, token$$3, tokenRemember$$3, _3$$3, _4$$3, _5$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&recaller);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&token$$3);
	ZVAL_UNDEF(&tokenRemember$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_9);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&user, this_ptr, "user", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	zephir_array_update_string(&_1, SL("user"), &user, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "auth:beforeLogout");
	ZEPHIR_CALL_METHOD(NULL, &_0, "fire", NULL, 0, &_2, this_ptr, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&recaller, this_ptr, "recaller", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&recaller) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&token$$3, &recaller, "token", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&tokenRemember$$3, &user, "getremembertoken", NULL, 0, &token$$3);
		zephir_check_call_status();
		if (zephir_is_true(&tokenRemember$$3)) {
			ZEPHIR_CALL_METHOD(NULL, &tokenRemember$$3, "delete", NULL, 0);
			zephir_check_call_status();
		}
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "getremembername", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, &_3$$3, "get", NULL, 0, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "delete", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("session"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_6, "remove", NULL, 0, &_7);
	zephir_check_call_status();
	zephir_read_property(&_8, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 1, 0);
	zephir_array_update_string(&_9, SL("user"), &user, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "auth:afterLogout");
	ZEPHIR_CALL_METHOD(NULL, &_8, "fire", NULL, 0, &_2, this_ptr, &_9);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("user"), &__$null);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, getLastUserAttempted)
{

	RETURN_MEMBER(getThis(), "lastUserAttempted");
}

PHP_METHOD(Phalcon_Auth_Guard_Session, viaRemember)
{

	RETURN_MEMBER(getThis(), "viaRemember");
}

PHP_METHOD(Phalcon_Auth_Guard_Session, getUser)
{

	RETURN_MEMBER(getThis(), "user");
}

PHP_METHOD(Phalcon_Auth_Guard_Session, setRequest)
{
	zval *request, request_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("phalcon\\http\\request")))
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &request);
	zephir_update_property_zval(this_ptr, ZEND_STRL("request"), request);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, setSession)
{
	zval *session, session_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(session, zephir_get_internal_ce(SL("phalcon\\session\\managerinterface")))
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &session);
	zephir_update_property_zval(this_ptr, ZEND_STRL("session"), session);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, setCookies)
{
	zval *cookies, cookies_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cookies_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(cookies, zephir_get_internal_ce(SL("phalcon\\http\\response\\cookies")))
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &cookies);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cookies"), cookies);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, getAdapter)
{

	RETURN_MEMBER(getThis(), "adapter");
}

PHP_METHOD(Phalcon_Auth_Guard_Session, setAdapter)
{
	zval *adapter, adapter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(adapter, phalcon_auth_adapter_adapterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &adapter);
	zephir_update_property_zval(this_ptr, ZEND_STRL("adapter"), adapter);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, basic)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval extraConditions;
	zval *field_param = NULL, *extraConditions_param = NULL, _0, _1, _2;
	zval field;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&extraConditions);
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(field)
		Z_PARAM_ARRAY(extraConditions)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &field_param, &extraConditions_param);
	if (!field_param) {
		ZEPHIR_INIT_VAR(&field);
		ZVAL_STRING(&field, "email");
	} else {
		zephir_get_strval(&field, field_param);
	}
	if (!extraConditions_param) {
		ZEPHIR_INIT_VAR(&extraConditions);
		array_init(&extraConditions);
	} else {
		zephir_get_arrval(&extraConditions, extraConditions_param);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "check", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(1);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "attemptbasic", NULL, 0, &_2, &field, &extraConditions);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);
}

PHP_METHOD(Phalcon_Auth_Guard_Session, attemptBasic)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval extraConditions;
	zval field;
	zval *request, request_sub, *field_param = NULL, *extraConditions_param = NULL, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&extraConditions);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("phalcon\\http\\request")))
		Z_PARAM_STR(field)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(extraConditions)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &request, &field_param, &extraConditions_param);
	zephir_get_strval(&field, field_param);
	if (!extraConditions_param) {
		ZEPHIR_INIT_VAR(&extraConditions);
		array_init(&extraConditions);
	} else {
		zephir_get_arrval(&extraConditions, extraConditions_param);
	}
	ZEPHIR_CALL_METHOD(&_0, request, "getbasicauth", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "basiccredentials", NULL, 0, request, &field);
	zephir_check_call_status();
	zephir_fast_array_merge(&_1, &_2, &extraConditions);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "attempt", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, basicCredentials)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *request, request_sub, *field_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&field);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("phalcon\\http\\request")))
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &request, &field_param);
	zephir_get_strval(&field, field_param);
	zephir_create_array(return_value, 2, 0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "userfrombasic", NULL, 13, request);
	zephir_check_call_status();
	zephir_array_update_zval(return_value, &field, &_0, PH_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "passwordfrombasic", NULL, 14, request);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("password"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, onceBasic)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval extraConditions;
	zval *field_param = NULL, *extraConditions_param = NULL, credentials, _0, _1, _2;
	zval field;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&extraConditions);
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(field)
		Z_PARAM_ARRAY(extraConditions)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &field_param, &extraConditions_param);
	if (!field_param) {
		ZEPHIR_INIT_VAR(&field);
		ZVAL_STRING(&field, "email");
	} else {
		zephir_get_strval(&field, field_param);
	}
	if (!extraConditions_param) {
		ZEPHIR_INIT_VAR(&extraConditions);
		array_init(&extraConditions);
	} else {
		zephir_get_arrval(&extraConditions, extraConditions_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&credentials, this_ptr, "basiccredentials", NULL, 0, &_0, &field);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_array_merge(&_2, &credentials, &extraConditions);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "once", NULL, 0, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getuser", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);
}

PHP_METHOD(Phalcon_Auth_Guard_Session, userFromBasic)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, _0, _1;

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, zephir_get_internal_ce(SL("phalcon\\http\\request")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &request);
	ZEPHIR_CALL_METHOD(&_0, request, "getbasicauth", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_1, &_0, SL("username"), PH_NOISY | PH_READONLY, "phalcon/Auth/Guard/Session.zep", 328);
	RETURN_CTOR(&_1);
}

PHP_METHOD(Phalcon_Auth_Guard_Session, passwordFromBasic)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, _0, _1;

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(request)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &request);
	ZEPHIR_CALL_METHOD(&_0, request, "getbasicauth", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_1, &_0, SL("password"), PH_NOISY | PH_READONLY, "phalcon/Auth/Guard/Session.zep", 333);
	RETURN_CTOR(&_1);
}

PHP_METHOD(Phalcon_Auth_Guard_Session, id)
{
	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "user", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "user", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&_1$$3, "getauthidentifier", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, setUser)
{
	zval *user, user_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(user, phalcon_auth_authenticatableinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &user);
	zephir_update_property_zval(this_ptr, ZEND_STRL("user"), user);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, check)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "user", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(Z_TYPE_P(&_0) != IS_NULL);
}

PHP_METHOD(Phalcon_Auth_Guard_Session, hasUser)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("user"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(Z_TYPE_P(&_0) != IS_NULL);
}

PHP_METHOD(Phalcon_Auth_Guard_Session, guest)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "check", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!zephir_is_true(&_0));
}

PHP_METHOD(Phalcon_Auth_Guard_Session, authenticate)
{
	zval user;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&user, this_ptr, "user", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&user) != IS_NULL) {
		RETURN_CCTOR(&user);
	}
	ZEPHIR_MM_RESTORE();
}

