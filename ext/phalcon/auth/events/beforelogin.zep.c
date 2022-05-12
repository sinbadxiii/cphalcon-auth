
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Events_BeforeLogin)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Events, BeforeLogin, phalcon, auth_events_beforelogin, phalcon_auth_events_eventabstract_ce, NULL, 0);

	return SUCCESS;
}

