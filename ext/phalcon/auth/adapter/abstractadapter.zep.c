
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_AbstractAdapter)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth\\Adapter, AbstractAdapter, phalcon, auth_adapter_abstractadapter, phalcon_auth_adapter_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_auth_adapter_abstractadapter_ce, SL("hasher"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_adapter_abstractadapter_ce, SL("config"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalcon_auth_adapter_abstractadapter_ce, SL("model"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_auth_adapter_abstractadapter_ce, 1, phalcon_auth_adapter_adapterinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval config;
	zval *hasher, hasher_sub, *config_param = NULL, _0, _1, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hasher_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&config);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(hasher, zephir_get_internal_ce(SL("phalcon\\encryption\\security")))
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(config)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &hasher, &config_param);
	if (!config_param) {
		ZEPHIR_INIT_VAR(&config);
		array_init(&config);
	} else {
		zephir_get_arrval(&config, config_param);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("hasher"), hasher);
	zephir_update_property_zval(this_ptr, ZEND_STRL("config"), &config);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&_1);
	zephir_array_fetch_string(&_1, &_0, SL("model"), PH_NOISY, "phalcon/Auth/Adapter/AbstractAdapter.zep", 18);
	if (!(ZEPHIR_IS_EMPTY(&_1))) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_3$$3, &_2$$3, SL("model"), PH_NOISY | PH_READONLY, "phalcon/Auth/Adapter/AbstractAdapter.zep", 19);
		zephir_update_property_zval(this_ptr, ZEND_STRL("model"), &_3$$3);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, getModel)
{

	RETURN_MEMBER(getThis(), "model");
}

PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, setModel)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *model_param = NULL;
	zval model;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(model)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &model_param);
	zephir_get_strval(&model, model_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("model"), &model);
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, getConfig)
{

	RETURN_MEMBER(getThis(), "config");
}

PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, setConfig)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *config_param = NULL;
	zval config;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(config)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config_param);
	zephir_get_arrval(&config, config_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("config"), &config);
	RETURN_THIS();
}

