
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_ManagerInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Auth, ManagerInterface, phalcon, auth_managerinterface, phalcon_auth_managerinterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Auth_ManagerInterface, guard);
ZEPHIR_DOC_METHOD(Phalcon_Auth_ManagerInterface, access);
