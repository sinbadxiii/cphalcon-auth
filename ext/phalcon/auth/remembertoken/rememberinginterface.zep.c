
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_RememberToken_RememberingInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Auth\\RememberToken, RememberingInterface, phalcon, auth_remembertoken_rememberinginterface, phalcon_auth_remembertoken_rememberinginterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Auth_RememberToken_RememberingInterface, getRememberToken);
ZEPHIR_DOC_METHOD(Phalcon_Auth_RememberToken_RememberingInterface, setRememberToken);
