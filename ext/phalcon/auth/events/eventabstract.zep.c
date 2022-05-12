
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Events_EventAbstract)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth\\Events, EventAbstract, phalcon, auth_events_eventabstract, phalcon_auth_events_eventabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(phalcon_auth_events_eventabstract_ce, 1, phalcon_auth_events_eventinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Events_EventAbstract, getType)
{
	zval reflect, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reflect);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&reflect);
	object_init_ex(&reflect, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &reflect, "__construct", NULL, 1, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &reflect, "getshortname", NULL, 2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("lcfirst", NULL, 3, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

