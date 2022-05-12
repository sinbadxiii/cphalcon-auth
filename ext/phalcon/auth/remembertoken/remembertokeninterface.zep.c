
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_RememberToken_RememberTokenInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Auth\\RememberToken, RememberTokenInterface, phalcon, auth_remembertoken_remembertokeninterface, phalcon_auth_remembertoken_remembertokeninterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Auth_RememberToken_RememberTokenInterface, getToken);
ZEPHIR_DOC_METHOD(Phalcon_Auth_RememberToken_RememberTokenInterface, getUserAgent);
