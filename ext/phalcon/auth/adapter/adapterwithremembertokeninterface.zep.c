
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_AdapterWithRememberTokenInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Auth\\Adapter, AdapterWithRememberTokenInterface, phalcon, auth_adapter_adapterwithremembertokeninterface, phalcon_auth_adapter_adapterwithremembertokeninterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Auth_Adapter_AdapterWithRememberTokenInterface, retrieveByToken);
ZEPHIR_DOC_METHOD(Phalcon_Auth_Adapter_AdapterWithRememberTokenInterface, createRememberToken);
