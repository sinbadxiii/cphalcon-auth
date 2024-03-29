
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Access_AuthenticatesRequestInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Auth\\Access, AuthenticatesRequestInterface, phalcon, auth_access_authenticatesrequestinterface, phalcon_auth_access_authenticatesrequestinterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Auth_Access_AuthenticatesRequestInterface, beforeExecuteRoute);
