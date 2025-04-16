
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/file.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Stream)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Adapter, Stream, phalcon, auth_adapter_stream, phalcon_auth_adapter_memory_ce, phalcon_auth_adapter_stream_method_entry, 0);

	zend_declare_property_null(phalcon_auth_adapter_stream_ce, SL("srcFile"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Adapter_Stream, getData)
{
	zend_bool _1, _8;
	zval _0, _2, _3, _4, _7, _9, _10, _13, _5$$4, _6$$4, _11$$6, _12$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_is_true(&_0);
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
		_1 = !(zephir_array_isset_string(&_2, SL("src")));
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Сonfig key 'src' with path source file not exist", "phalcon/Auth/Adapter/Stream.zep", 15);
		return;
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&_4);
	zephir_array_fetch_string(&_4, &_3, SL("src"), PH_NOISY, "phalcon/Auth/Adapter/Stream.zep", 18);
	if (!(ZEPHIR_IS_EMPTY(&_4))) {
		zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_6$$4, &_5$$4, SL("src"), PH_NOISY | PH_READONLY, "phalcon/Auth/Adapter/Stream.zep", 19);
		zephir_update_property_zval(this_ptr, ZEND_STRL("srcFile"), &_6$$4);
	}
	zephir_memory_observe(&_7);
	zephir_read_property(&_7, this_ptr, ZEND_STRL("data"), PH_NOISY_CC);
	_8 = ZEPHIR_IS_EMPTY(&_7);
	if (_8) {
		zephir_memory_observe(&_9);
		zephir_read_property(&_9, this_ptr, ZEND_STRL("srcFile"), PH_NOISY_CC);
		_8 = ZEPHIR_IS_EMPTY(&_9);
	}
	if (_8) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "File source is empty", "phalcon/Auth/Adapter/Stream.zep", 25);
		return;
	}
	zephir_memory_observe(&_10);
	zephir_read_property(&_10, this_ptr, ZEND_STRL("data"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_10)) {
		zephir_read_property(&_12$$6, this_ptr, ZEND_STRL("srcFile"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_11$$6, this_ptr, "read", NULL, 0, &_12$$6);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &_11$$6);
	}
	zephir_memory_observe(&_13);
	zephir_read_property(&_13, this_ptr, ZEND_STRL("data"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_13)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Data is empty", "phalcon/Auth/Adapter/Stream.zep", 35);
		return;
	}
	RETURN_MM_MEMBER(getThis(), "data");
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(src)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &src_param);
	zephir_get_strval(&src, src_param);
	if (!((zephir_file_exists(&src) == SUCCESS))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, zend_ce_exception);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_VS(&_1$$3, &src, " file don't exist");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 6, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Auth/Adapter/Stream.zep", 46);
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

	ZVAL_UNDEF(&fileData_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&decoded);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&src);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(fileData)
		Z_PARAM_STR(src)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 4, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Auth/Adapter/Stream.zep", 62);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&decoded);
}

PHP_METHOD(Phalcon_Auth_Adapter_Stream, getFileSource)
{

	RETURN_MEMBER(getThis(), "srcFile");
}

PHP_METHOD(Phalcon_Auth_Adapter_Stream, setFileSource)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *src_param = NULL;
	zval src;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&src);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(src)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &src_param);
	zephir_get_strval(&src, src_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("srcFile"), &src);
	ZEPHIR_MM_RESTORE();
}

