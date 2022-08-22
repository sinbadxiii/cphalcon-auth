
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_GuardInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Auth\\Guard, GuardInterface, phalcon, auth_guard_guardinterface, phalcon_auth_guard_guardinterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Auth_Guard_GuardInterface, check);
ZEPHIR_DOC_METHOD(Phalcon_Auth_Guard_GuardInterface, user);
ZEPHIR_DOC_METHOD(Phalcon_Auth_Guard_GuardInterface, setUser);
ZEPHIR_DOC_METHOD(Phalcon_Auth_Guard_GuardInterface, id);
ZEPHIR_DOC_METHOD(Phalcon_Auth_Guard_GuardInterface, guest);
ZEPHIR_DOC_METHOD(Phalcon_Auth_Guard_GuardInterface, validate);
