
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


ZEPHIR_INIT_CLASS(Phalcon_Auth_ManagerFactory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth, ManagerFactory, phalcon, auth_managerfactory, phalcon_auth_manager_ce, phalcon_auth_managerfactory_method_entry, 0);

	zend_declare_property_null(phalcon_auth_managerfactory_ce, SL("config"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_managerfactory_ce, SL("security"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_managerfactory_ce, SL("customGuards"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_managerfactory_ce, SL("customAdapters"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_managerfactory_ce, SL("session"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_managerfactory_ce, SL("cookies"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_managerfactory_ce, SL("request"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_managerfactory_ce, SL("eventsManager"), ZEND_ACC_PROTECTED);
	phalcon_auth_managerfactory_ce->create_object = zephir_init_properties_Phalcon_Auth_ManagerFactory;

	zend_class_implements(phalcon_auth_managerfactory_ce, 1, zephir_get_internal_ce(SL("phalcon\\events\\eventsawareinterface")));
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_ManagerFactory, __construct)
{
	zend_class_entry *_2$$3, *_12$$6, *_17$$8;
	zend_string *_9;
	zend_ulong _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config_param = NULL, *security = NULL, security_sub, *session = NULL, session_sub, *cookies = NULL, cookies_sub, *request = NULL, request_sub, *eventsManager = NULL, eventsManager_sub, __$null, _0, service, nameService, *_6, _7, authConfig$$3, _1$$3, _3$$3, _4$$3, _5$$3, _10$$5, _11$$6, _14$$6, _15$$7, _16$$8, _18$$8;
	zval config, services;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&services);
	ZVAL_UNDEF(&security_sub);
	ZVAL_UNDEF(&session_sub);
	ZVAL_UNDEF(&cookies_sub);
	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&eventsManager_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&nameService);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&authConfig$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_18$$8);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 6)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(config)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(security, zephir_get_internal_ce(SL("phalcon\\encryption\\security")))
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(session, zephir_get_internal_ce(SL("phalcon\\session\\managerinterface")))
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(cookies, zephir_get_internal_ce(SL("phalcon\\http\\response\\cookies")))
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(request, zephir_get_internal_ce(SL("phalcon\\http\\request")))
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(eventsManager, zephir_get_internal_ce(SL("phalcon\\events\\managerinterface")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 6, &config_param, &security, &session, &cookies, &request, &eventsManager);
	if (!config_param) {
		ZEPHIR_INIT_VAR(&config);
		array_init(&config);
	} else {
		zephir_get_arrval(&config, config_param);
	}
	if (!security) {
		security = &security_sub;
		security = &__$null;
	}
	if (!session) {
		session = &session_sub;
		session = &__$null;
	}
	if (!cookies) {
		cookies = &cookies_sub;
		cookies = &__$null;
	}
	if (!request) {
		request = &request_sub;
		request = &__$null;
	}
	if (!eventsManager) {
		eventsManager = &eventsManager_sub;
		eventsManager = &__$null;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("config"), &config);
	zephir_memory_observe(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		_2$$3 = zephir_fetch_class_str_ex(SL("Phalcon\\Di\\Di"), ZEND_FETCH_CLASS_AUTO);
		ZEPHIR_CALL_CE_STATIC(&_1$$3, _2$$3, "getdefault", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "config");
		ZEPHIR_CALL_METHOD(&_3$$3, &_1$$3, "getshared", NULL, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "auth");
		ZEPHIR_CALL_METHOD(&authConfig$$3, &_3$$3, "get", NULL, 0, &_4$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(&authConfig$$3)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Configuration file auth.php (or key config->auth into your config) does not exist", "phalcon/Auth/ManagerFactory.zep", 48);
			return;
		}
		ZEPHIR_CALL_METHOD(&_5$$3, &authConfig$$3, "toarray", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("config"), &_5$$3);
	}
	ZEPHIR_INIT_VAR(&services);
	zephir_create_array(&services, 5, 0);
	zephir_array_update_string(&services, SL("security"), security, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&services, SL("session"), session, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&services, SL("cookies"), cookies, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&services, SL("request"), request, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&services, SL("eventsManager"), eventsManager, PH_COPY | PH_SEPARATE);
	zephir_is_iterable(&services, 0, "phalcon/Auth/ManagerFactory.zep", 72);
	if (Z_TYPE_P(&services) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&services), _8, _9, _6)
		{
			ZEPHIR_INIT_NVAR(&nameService);
			if (_9 != NULL) { 
				ZVAL_STR_COPY(&nameService, _9);
			} else {
				ZVAL_LONG(&nameService, _8);
			}
			ZEPHIR_INIT_NVAR(&service);
			ZVAL_COPY(&service, _6);
			zephir_update_property_zval_zval(this_ptr, &nameService, &service);
			ZEPHIR_OBS_NVAR(&_10$$5);
			zephir_read_property_zval(&_10$$5, this_ptr, &nameService, PH_NOISY_CC);
			if (Z_TYPE_P(&_10$$5) == IS_NULL) {
				_12$$6 = zephir_fetch_class_str_ex(SL("Phalcon\\Di\\Di"), ZEND_FETCH_CLASS_AUTO);
				ZEPHIR_CALL_CE_STATIC(&_11$$6, _12$$6, "getdefault", &_13, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_14$$6, &_11$$6, "getshared", NULL, 0, &nameService);
				zephir_check_call_status();
				zephir_update_property_zval_zval(this_ptr, &nameService, &_14$$6);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &services, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, &services, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&nameService, &services, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&service, &services, "current", NULL, 0);
			zephir_check_call_status();
				zephir_update_property_zval_zval(this_ptr, &nameService, &service);
				ZEPHIR_OBS_NVAR(&_15$$7);
				zephir_read_property_zval(&_15$$7, this_ptr, &nameService, PH_NOISY_CC);
				if (Z_TYPE_P(&_15$$7) == IS_NULL) {
					_17$$8 = zephir_fetch_class_str_ex(SL("Phalcon\\Di\\Di"), ZEND_FETCH_CLASS_AUTO);
					ZEPHIR_CALL_CE_STATIC(&_16$$8, _17$$8, "getdefault", &_13, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_18$$8, &_16$$8, "getshared", NULL, 0, &nameService);
					zephir_check_call_status();
					zephir_update_property_zval_zval(this_ptr, &nameService, &_18$$8);
				}
			ZEPHIR_CALL_METHOD(NULL, &services, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&service);
	ZEPHIR_INIT_NVAR(&nameService);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_ManagerFactory, getConfigGuard)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _0, _1, _2;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("guards"), PH_NOISY | PH_READONLY, "phalcon/Auth/ManagerFactory.zep", 76);
	zephir_array_fetch(&_2, &_1, &name, PH_NOISY | PH_READONLY, "phalcon/Auth/ManagerFactory.zep", 76);
	RETURN_CTOR(&_2);
}

PHP_METHOD(Phalcon_Auth_ManagerFactory, guard)
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
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdefaultguardname", NULL, 0);
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
	zephir_array_fetch(&_4, &_3, name, PH_NOISY | PH_READONLY, "phalcon/Auth/ManagerFactory.zep", 87);
	RETURN_CTOR(&_4);
}

PHP_METHOD(Phalcon_Auth_ManagerFactory, resolve)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *nameGuard_param = NULL, configGuard, providerAdapter, _2, _3, _4, _8, _12, _17, _18, _19, _0$$3, _5$$4, _6$$4, _7$$4, _9$$6, _10$$7, _11$$5, _13$$8, _14$$8, _15$$8, _16$$8;
	zval nameGuard, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&nameGuard);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&configGuard);
	ZVAL_UNDEF(&providerAdapter);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(nameGuard)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &nameGuard_param);
	zephir_get_strval(&nameGuard, nameGuard_param);
	ZEPHIR_CALL_METHOD(&configGuard, this_ptr, "getconfigguard", NULL, 0, &nameGuard);
	zephir_check_call_status();
	if (Z_TYPE_P(&configGuard) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SVS(&_1$$3, "Auth guard [", &nameGuard, "] is not defined.");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 4, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Auth/ManagerFactory.zep", 97);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch_string(&_2, &configGuard, SL("provider"), PH_NOISY | PH_READONLY, "phalcon/Auth/ManagerFactory.zep", 100);
	ZEPHIR_CALL_METHOD(&providerAdapter, this_ptr, "getadapterprovider", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("customGuards"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_4, &configGuard, SL("driver"), PH_READONLY, "phalcon/Auth/ManagerFactory.zep", 102);
	if (zephir_array_isset(&_3, &_4)) {
		zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("customGuards"), PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_7$$4);
		zephir_array_fetch_string(&_7$$4, &configGuard, SL("driver"), PH_NOISY, "phalcon/Auth/ManagerFactory.zep", 104);
		zephir_array_fetch(&_6$$4, &_5$$4, &_7$$4, PH_NOISY | PH_READONLY, "phalcon/Auth/ManagerFactory.zep", 104);
		ZEPHIR_RETURN_CALL_FUNCTION("call_user_func", NULL, 17, &_6$$4, &providerAdapter, &configGuard);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_array_fetch_string(&_8, &configGuard, SL("driver"), PH_NOISY | PH_READONLY, "phalcon/Auth/ManagerFactory.zep", 110);
	if (ZEPHIR_IS_STRING_IDENTICAL(&_8, "token")) {
		if (!(zephir_array_isset_string(&configGuard, SL("inputKey")))) {
			ZEPHIR_INIT_VAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "auth_token");
			zephir_array_update_string(&configGuard, SL("inputKey"), &_9$$6, PH_COPY | PH_SEPARATE);
		}
		if (!(zephir_array_isset_string(&configGuard, SL("storageKey")))) {
			ZEPHIR_INIT_VAR(&_10$$7);
			ZVAL_STRING(&_10$$7, "auth_token");
			zephir_array_update_string(&configGuard, SL("storageKey"), &_10$$7, PH_COPY | PH_SEPARATE);
		}
		object_init_ex(return_value, phalcon_auth_guard_token_ce);
		zephir_read_property(&_11$$5, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 18, &providerAdapter, &configGuard, &_11$$5);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_array_fetch_string(&_12, &configGuard, SL("driver"), PH_NOISY | PH_READONLY, "phalcon/Auth/ManagerFactory.zep", 126);
	if (ZEPHIR_IS_STRING_IDENTICAL(&_12, "session")) {
		object_init_ex(return_value, phalcon_auth_guard_session_ce);
		zephir_read_property(&_13$$8, this_ptr, ZEND_STRL("session"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_14$$8, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_15$$8, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_16$$8, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 19, &providerAdapter, &_13$$8, &_14$$8, &_15$$8, &_16$$8);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_17);
	object_init_ex(&_17, spl_ce_InvalidArgumentException);
	zephir_array_fetch_string(&_18, &configGuard, SL("driver"), PH_NOISY | PH_READONLY, "phalcon/Auth/ManagerFactory.zep", 138);
	ZEPHIR_INIT_VAR(&_19);
	ZEPHIR_CONCAT_SVSVS(&_19, "Auth driver [", &_18, "] for guard [", &nameGuard, "] is not defined.");
	ZEPHIR_CALL_METHOD(NULL, &_17, "__construct", NULL, 4, &_19);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_17, "phalcon/Auth/ManagerFactory.zep", 139);
	ZEPHIR_MM_RESTORE();
	return;
}

PHP_METHOD(Phalcon_Auth_ManagerFactory, getAdapterProvider)
{
	zend_class_entry *_16;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *provider_param = NULL, configProvider, _0, _1, adapterName, _6, adapterClass, _10, _11, adapter, _15, _17, _2$$3, _4$$4, _7$$5, _8$$5, _9$$5, _12$$6, _13$$6, _14$$6, _18$$7, _19$$7;
	zval provider, _3$$3, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&provider);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&configProvider);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&adapterName);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&adapterClass);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(provider)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &provider_param);
	if (!provider_param) {
		ZEPHIR_INIT_VAR(&provider);
	} else {
		zephir_get_strval(&provider, provider_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("providers"), PH_NOISY | PH_READONLY, "phalcon/Auth/ManagerFactory.zep", 145);
	zephir_memory_observe(&configProvider);
	zephir_array_fetch(&configProvider, &_1, &provider, PH_NOISY, "phalcon/Auth/ManagerFactory.zep", 145);
	if (Z_TYPE_P(&configProvider) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVS(&_3$$3, "Config adapter '", &provider, "' not defined");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 4, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Auth/ManagerFactory.zep", 150);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&adapterName);
	zephir_array_fetch_string(&adapterName, &configProvider, SL("adapter"), PH_NOISY, "phalcon/Auth/ManagerFactory.zep", 153);
	if (Z_TYPE_P(&adapterName) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SVS(&_5$$4, "Adapter not assigned in config->auth->providers->", &provider, "->adapter = ?");
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 4, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Auth/ManagerFactory.zep", 158);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("customAdapters"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_6, &adapterName)) {
		zephir_read_property(&_7$$5, this_ptr, ZEND_STRL("customAdapters"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_8$$5, &_7$$5, &adapterName, PH_NOISY | PH_READONLY, "phalcon/Auth/ManagerFactory.zep", 163);
		zephir_read_property(&_9$$5, this_ptr, ZEND_STRL("security"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_FUNCTION("call_user_func", NULL, 17, &_8$$5, &_9$$5, &configProvider);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_10);
	zephir_ucfirst(&_10, &adapterName);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "\\Phalcon\\Auth\\Adapter\\%s");
	ZEPHIR_CALL_FUNCTION(&adapterClass, "sprintf", NULL, 5, &_11, &_10);
	zephir_check_call_status();
	if (!(zephir_class_exists(&adapterClass, 1))) {
		ZEPHIR_INIT_VAR(&_12$$6);
		object_init_ex(&_12$$6, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_13$$6);
		ZVAL_STRING(&_13$$6, "%s not found.");
		ZEPHIR_CALL_FUNCTION(&_14$$6, "sprintf", NULL, 5, &_13$$6, &adapterClass);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_12$$6, "__construct", NULL, 4, &_14$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_12$$6, "phalcon/Auth/ManagerFactory.zep", 176);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&adapter);
	zephir_fetch_safe_class(&_15, &adapterClass);
	_16 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_15), Z_STRLEN_P(&_15), ZEND_FETCH_CLASS_AUTO);
	if(!_16) {
		RETURN_MM_NULL();
	}
	object_init_ex(&adapter, _16);
	if (zephir_has_constructor(&adapter)) {
		zephir_read_property(&_17, this_ptr, ZEND_STRL("security"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &adapter, "__construct", NULL, 0, &_17, &configProvider);
		zephir_check_call_status();
	}

	if (!(zephir_instance_of_ev(&adapter, phalcon_auth_adapter_adapterinterface_ce))) {
		ZEPHIR_INIT_VAR(&_18$$7);
		object_init_ex(&_18$$7, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_19$$7);
		ZEPHIR_CONCAT_VS(&_19$$7, &adapterClass, " not implementing AdapterInterface");
		ZEPHIR_CALL_METHOD(NULL, &_18$$7, "__construct", NULL, 4, &_19$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_18$$7, "phalcon/Auth/ManagerFactory.zep", 183);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&adapter);
}

PHP_METHOD(Phalcon_Auth_ManagerFactory, getDefaultGuardName)
{
	zval _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("defaults"), PH_NOISY | PH_READONLY, "phalcon/Auth/ManagerFactory.zep", 191);
	zephir_array_fetch_string(&_2, &_1, SL("guard"), PH_NOISY | PH_READONLY, "phalcon/Auth/ManagerFactory.zep", 191);
	RETURN_CTORW(&_2);
}

PHP_METHOD(Phalcon_Auth_ManagerFactory, extendGuard)
{
	zval *driver, driver_sub, *callback, callback_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&driver_sub);
	ZVAL_UNDEF(&callback_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(driver)
		Z_PARAM_OBJECT_OF_CLASS(callback, zend_ce_closure)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &driver, &callback);
	zephir_update_property_array(this_ptr, SL("customGuards"), driver, callback);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Auth_ManagerFactory, extendProviderAdapter)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *callback, callback_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&callback_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OBJECT_OF_CLASS(callback, zend_ce_closure)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &name_param, &callback);
	zephir_get_strval(&name, name_param);
	zephir_update_property_array(this_ptr, SL("customAdapters"), &name, callback);
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Auth_ManagerFactory, getEventsManager)
{

	RETURN_MEMBER(getThis(), "eventsManager");
}

PHP_METHOD(Phalcon_Auth_ManagerFactory, setEventsManager)
{
	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, zephir_get_internal_ce(SL("phalcon\\events\\managerinterface")))
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);
	zephir_update_property_zval(this_ptr, ZEND_STRL("eventsManager"), eventsManager);
}

zend_object *zephir_init_properties_Phalcon_Auth_ManagerFactory(zend_class_entry *class_type)
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
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("customAdapters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("customAdapters"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("accessList"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("guards"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("guards"), &_5$$5);
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

