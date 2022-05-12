
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Providers_ProviderInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Auth\\Providers, ProviderInterface, phalcon, auth_providers_providerinterface, phalcon_auth_providers_providerinterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Auth_Providers_ProviderInterface, retrieveByCredentials);
ZEPHIR_DOC_METHOD(Phalcon_Auth_Providers_ProviderInterface, retrieveById);
ZEPHIR_DOC_METHOD(Phalcon_Auth_Providers_ProviderInterface, validateCredentials);
