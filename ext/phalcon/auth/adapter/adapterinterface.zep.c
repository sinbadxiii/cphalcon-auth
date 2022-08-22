
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_AdapterInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Auth\\Adapter, AdapterInterface, phalcon, auth_adapter_adapterinterface, phalcon_auth_adapter_adapterinterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Auth_Adapter_AdapterInterface, retrieveByCredentials);
ZEPHIR_DOC_METHOD(Phalcon_Auth_Adapter_AdapterInterface, retrieveById);
ZEPHIR_DOC_METHOD(Phalcon_Auth_Adapter_AdapterInterface, validateCredentials);
