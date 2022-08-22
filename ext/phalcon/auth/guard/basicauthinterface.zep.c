
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_BasicAuthInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Auth\\Guard, BasicAuthInterface, phalcon, auth_guard_basicauthinterface, phalcon_auth_guard_basicauthinterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Auth_Guard_BasicAuthInterface, basic);
ZEPHIR_DOC_METHOD(Phalcon_Auth_Guard_BasicAuthInterface, onceBasic);
