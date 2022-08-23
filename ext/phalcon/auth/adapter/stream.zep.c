
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/file.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Stream)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Adapter, Stream, phalcon, auth_adapter_stream, phalcon_auth_adapter_abstractadapter_ce, phalcon_auth_adapter_stream_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Adapter_Stream, getProviderStorage)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, &_0, ZEND_STRL("src"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "read", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Adapter_Stream, read)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *src_param = NULL, fileData, _0$$3;
	zval src, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&src);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&fileData);
	ZVAL_UNDEF(&_0$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(src)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &src_param);
	zephir_get_strval(&src, src_param);


	if (!((zephir_file_exists(&src) == SUCCESS))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, zend_ce_exception);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_VS(&_1$$3, &src, " file dont exist");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 6, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Auth/Adapter/Stream.zep", 18);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&fileData);
	zephir_file_get_contents(&fileData, &src);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "validate", NULL, 7, &fileData, &src);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Adapter_Stream, validate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval src;
	zval *fileData, fileData_sub, *src_param = NULL, __$true, decoded, _0, _1$$3, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fileData_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&decoded);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&src);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(fileData)
		Z_PARAM_STR(src)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &fileData, &src_param);
	zephir_get_strval(&src, src_param);


	ZEPHIR_INIT_VAR(&decoded);
	zephir_json_decode(&decoded, fileData, zephir_get_intval(&__$true) );
	ZEPHIR_CALL_FUNCTION(&_0, "json_last_error", NULL, 8);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_LONG_IDENTICAL(&_0, 0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "json_last_error_msg", NULL, 9);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_VSV(&_3$$3, &src, " json_decode error: ", &_2$$3);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 10, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Auth/Adapter/Stream.zep", 34);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&decoded);
}

