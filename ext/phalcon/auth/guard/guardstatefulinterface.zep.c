
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_GuardStatefulInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Auth\\Guard, GuardStatefulInterface, phalcon, auth_guard_guardstatefulinterface, phalcon_auth_guard_guardstatefulinterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Auth_Guard_GuardStatefulInterface, attempt);
ZEPHIR_DOC_METHOD(Phalcon_Auth_Guard_GuardStatefulInterface, login);
ZEPHIR_DOC_METHOD(Phalcon_Auth_Guard_GuardStatefulInterface, loginById);
ZEPHIR_DOC_METHOD(Phalcon_Auth_Guard_GuardStatefulInterface, once);
ZEPHIR_DOC_METHOD(Phalcon_Auth_Guard_GuardStatefulInterface, viaRemember);
ZEPHIR_DOC_METHOD(Phalcon_Auth_Guard_GuardStatefulInterface, logout);
