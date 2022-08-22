
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/file.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Providers_FileProvider_Parser)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth\\Providers\\FileProvider, Parser, phalcon, auth_providers_fileprovider_parser, phalcon_auth_providers_fileprovider_parser_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Providers_FileProvider_Parser, file)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *path, path_sub, fileData, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&fileData);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(path)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);


	if (!((zephir_file_exists(path) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_auth_exceptions_exception_ce, "file dont exist", "phalcon/Auth/Providers/FileProvider/Parser.zep", 12);
		return;
	}
	ZEPHIR_INIT_VAR(&fileData);
	zephir_file_get_contents(&fileData, path);
	object_init_ex(return_value, phalcon_auth_collection_userscollection_ce);
	ZEPHIR_CALL_SELF(&_0, "jsonvalidate", &_1, 22, &fileData);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 23, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Providers_FileProvider_Parser, jsonValidate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, __$true, result, error, _0, _1$$13;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$13);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);
	zephir_get_strval(&data, data_param);


	ZEPHIR_INIT_VAR(&result);
	zephir_json_decode(&result, &data, zephir_get_intval(&__$true) );
	ZEPHIR_CALL_FUNCTION(&_0, "json_last_error", NULL, 24);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_LONG(&_0, 0)) {
			ZEPHIR_INIT_VAR(&error);
			ZVAL_STRING(&error, "");
			break;
		}
		if (ZEPHIR_IS_LONG(&_0, 1)) {
			ZEPHIR_INIT_NVAR(&error);
			ZVAL_STRING(&error, "The maximum stack depth has been exceeded.");
			break;
		}
		if (ZEPHIR_IS_LONG(&_0, 2)) {
			ZEPHIR_INIT_NVAR(&error);
			ZVAL_STRING(&error, "Invalid or malformed JSON.");
			break;
		}
		if (ZEPHIR_IS_LONG(&_0, 3)) {
			ZEPHIR_INIT_NVAR(&error);
			ZVAL_STRING(&error, "Control character error, possibly incorrectly encoded.");
			break;
		}
		if (ZEPHIR_IS_LONG(&_0, 4)) {
			ZEPHIR_INIT_NVAR(&error);
			ZVAL_STRING(&error, "Syntax error, malformed JSON.");
			break;
		}
		if (ZEPHIR_IS_LONG(&_0, 5)) {
			ZEPHIR_INIT_NVAR(&error);
			ZVAL_STRING(&error, "Malformed UTF-8 characters, possibly incorrectly encoded.");
			break;
		}
		if (ZEPHIR_IS_LONG(&_0, 6)) {
			ZEPHIR_INIT_NVAR(&error);
			ZVAL_STRING(&error, "One or more recursive references in the value to be encoded.");
			break;
		}
		if (ZEPHIR_IS_LONG(&_0, 7)) {
			ZEPHIR_INIT_NVAR(&error);
			ZVAL_STRING(&error, "One or more NAN or INF values in the value to be encoded.");
			break;
		}
		if (ZEPHIR_IS_LONG(&_0, 8)) {
			ZEPHIR_INIT_NVAR(&error);
			ZVAL_STRING(&error, "A value of a type that cannot be encoded was given.");
			break;
		}
		ZEPHIR_INIT_NVAR(&error);
		ZVAL_STRING(&error, "Unknown JSON error occured.");
		break;
	} while(0);

	if (!(ZEPHIR_IS_EMPTY(&error))) {
		ZEPHIR_INIT_VAR(&_1$$13);
		object_init_ex(&_1$$13, phalcon_auth_exceptions_jsonnotvalidexception_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$13, "__construct", NULL, 19, &error);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$13, "phalcon/Auth/Providers/FileProvider/Parser.zep", 59);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&result);
}

