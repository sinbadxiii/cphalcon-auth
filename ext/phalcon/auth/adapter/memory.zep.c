
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
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Memory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Adapter, Memory, phalcon, auth_adapter_memory, phalcon_auth_adapter_collectionadapterabstract_ce, phalcon_auth_adapter_memory_method_entry, 0);

	zend_class_implements(phalcon_auth_adapter_memory_ce, 1, phalcon_auth_adapter_adapterinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Adapter_Memory, getData)
{
	zval _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "data");
	ZEPHIR_CALL_METHOD(&_1, &_0, "has", NULL, 0, &_2);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Сonfig key 'datа' with user data array empty or does not exist", "phalcon/Auth/Adapter/Memory.zep", 10);
		return;
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, &_3, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_4, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

