
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


ZEPHIR_INIT_CLASS(Phalcon_Auth_Exceptions_ConfigFileNotExistException)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Exceptions, ConfigFileNotExistException, phalcon, auth_exceptions_configfilenotexistexception, phalcon_auth_exceptions_exception_ce, NULL, 0);

	zend_declare_property_string(phalcon_auth_exceptions_configfilenotexistexception_ce, SL("message"), "Configuration file auth.php (or key ->auth into your config) does not exist", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

