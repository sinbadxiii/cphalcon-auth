
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


ZEPHIR_INIT_CLASS(Phalcon_Auth_Exceptions_JsonNotValidException)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Exceptions, JsonNotValidException, phalcon, auth_exceptions_jsonnotvalidexception, phalcon_auth_exceptions_exception_ce, NULL, 0);

	return SUCCESS;
}

