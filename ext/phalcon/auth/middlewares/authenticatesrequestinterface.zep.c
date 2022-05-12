
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Middlewares_AuthenticatesRequestInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Auth\\Middlewares, AuthenticatesRequestInterface, phalcon, auth_middlewares_authenticatesrequestinterface, NULL);

	return SUCCESS;
}

