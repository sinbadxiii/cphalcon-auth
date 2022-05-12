
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
#include "kernel/object.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_Events_Logout)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Events, Logout, phalcon, auth_events_logout, phalcon_auth_events_eventabstract_ce, phalcon_auth_events_logout_method_entry, 0);

	zend_declare_property_null(phalcon_auth_events_logout_ce, SL("user"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Events_Logout, __construct)
{
	zval *user, user_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(user)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &user);


	zephir_update_property_zval(this_ptr, ZEND_STRL("user"), user);
}

