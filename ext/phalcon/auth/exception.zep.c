
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


ZEPHIR_INIT_CLASS(Phalcon_Auth_Exception)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth, Exception, phalcon, auth_exception, zend_ce_exception, NULL, 0);

	zend_declare_property_string(phalcon_auth_exception_ce, SL("message"), "An error occurred", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

