
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Access_AccessInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Auth\\Access, AccessInterface, phalcon, auth_access_accessinterface, phalcon_auth_access_accessinterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Auth_Access_AccessInterface, except);
ZEPHIR_DOC_METHOD(Phalcon_Auth_Access_AccessInterface, only);
ZEPHIR_DOC_METHOD(Phalcon_Auth_Access_AccessInterface, isAllowed);
ZEPHIR_DOC_METHOD(Phalcon_Auth_Access_AccessInterface, redirectTo);
ZEPHIR_DOC_METHOD(Phalcon_Auth_Access_AccessInterface, allowedIf);
