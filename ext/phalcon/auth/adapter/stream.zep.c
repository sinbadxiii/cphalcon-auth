
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
#include "kernel/operators.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Stream)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Adapter, Stream, phalcon, auth_adapter_stream, phalcon_auth_adapter_collectionadapterabstract_ce, phalcon_auth_adapter_stream_method_entry, 0);

	zend_class_implements(phalcon_auth_adapter_stream_ce, 1, phalcon_auth_adapter_adapterinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Adapter_Stream, getData)
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
	zval *path_param = NULL, fileData;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&fileData);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);
	zephir_get_strval(&path, path_param);


	if (!((zephir_file_exists(&path) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_ce_exception, "file dont exist", "phalcon/Auth/Adapter/Stream.zep", 18);
		return;
	}
	ZEPHIR_INIT_VAR(&fileData);
	zephir_file_get_contents(&fileData, &path);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "validate", NULL, 5, &fileData, &path);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Adapter_Stream, validate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fileData_param = NULL, *filepath, filepath_sub, __$true, decoded, _0, _1$$3, _2$$3, _3$$3;
	zval fileData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fileData);
	ZVAL_UNDEF(&filepath_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&decoded);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(fileData)
		Z_PARAM_ZVAL(filepath)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &fileData_param, &filepath);
	zephir_get_strval(&fileData, fileData_param);


	ZEPHIR_INIT_VAR(&decoded);
	zephir_json_decode(&decoded, &fileData, zephir_get_intval(&__$true) );
	ZEPHIR_CALL_FUNCTION(&_0, "json_last_error", NULL, 6);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_LONG_IDENTICAL(&_0, 0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "json_last_error_msg", NULL, 7);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_VSV(&_3$$3, filepath, " json_decode error: ", &_2$$3);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Auth/Adapter/Stream.zep", 34);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&decoded);
}

