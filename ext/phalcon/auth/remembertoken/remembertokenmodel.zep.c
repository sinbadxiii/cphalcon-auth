
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Phalcon_Auth_RememberToken_RememberTokenModel)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\RememberToken, RememberTokenModel, phalcon, auth_remembertoken_remembertokenmodel, zephir_get_internal_ce(SL("phalcon\\mvc\\model")), phalcon_auth_remembertoken_remembertokenmodel_method_entry, 0);

	zend_declare_property_null(phalcon_auth_remembertoken_remembertokenmodel_ce, SL("id"), ZEND_ACC_PUBLIC);
	zend_declare_property_null(phalcon_auth_remembertoken_remembertokenmodel_ce, SL("user_id"), ZEND_ACC_PUBLIC);
	zend_declare_property_null(phalcon_auth_remembertoken_remembertokenmodel_ce, SL("token"), ZEND_ACC_PUBLIC);
	zend_declare_property_null(phalcon_auth_remembertoken_remembertokenmodel_ce, SL("ip"), ZEND_ACC_PUBLIC);
	zend_declare_property_null(phalcon_auth_remembertoken_remembertokenmodel_ce, SL("user_agent"), ZEND_ACC_PUBLIC);
	zend_declare_property_null(phalcon_auth_remembertoken_remembertokenmodel_ce, SL("created_at"), ZEND_ACC_PUBLIC);
	zend_declare_property_null(phalcon_auth_remembertoken_remembertokenmodel_ce, SL("updated_at"), ZEND_ACC_PUBLIC);
	zend_declare_property_null(phalcon_auth_remembertoken_remembertokenmodel_ce, SL("expired_at"), ZEND_ACC_PUBLIC);
	zend_class_implements(phalcon_auth_remembertoken_remembertokenmodel_ce, 1, zephir_get_internal_ce(SL("phalcon\\auth\\remembertoken\\remembertokeninterface")));
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_RememberToken_RememberTokenModel, initialize)
{
	zend_class_entry *_1;
	zval configAuth, _0, _2, _3, guard, _4, _5, tableRememberToken, _6, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&configAuth);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&guard);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&tableRememberToken);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);


	ZEPHIR_MM_GROW();

	_1 = zephir_fetch_class_str_ex(SL("Phalcon\\Di\\Di"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_CALL_CE_STATIC(&_0, _1, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "config");
	ZEPHIR_CALL_METHOD(&_2, &_0, "getshared", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&configAuth);
	zephir_read_property(&configAuth, &_2, ZEND_STRL("auth"), PH_NOISY_CC);
	zephir_read_property(&_4, &configAuth, ZEND_STRL("defaults"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, &_4, ZEND_STRL("guard"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&guard, &_5);
	ZEPHIR_OBS_VAR(&_6);
	zephir_read_property(&_6, &configAuth, ZEND_STRL("guards"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&_7);
	zephir_read_property_zval(&_7, &_6, &guard, PH_NOISY_CC);
	zephir_read_property(&_5, &_7, ZEND_STRL("provider"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "%s_remember_tokens");
	ZEPHIR_CALL_FUNCTION(&tableRememberToken, "sprintf", NULL, 12, &_3, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsource", NULL, 0, &tableRememberToken);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_RememberToken_RememberTokenModel, beforeValidationOnCreate)
{
	zval _0, _1, _2, _3, _4$$3, _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Y-m-d\\TH:i:sP");
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, 13, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("created_at"), &_1);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Y-m-d\\TH:i:sP");
	ZEPHIR_CALL_FUNCTION(&_2, "date", NULL, 13, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("updated_at"), &_2);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("expired_at"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_3))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Y-m-d\\TH:i:sP");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "date", NULL, 13, &_4$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("expired_at"), &_5$$3);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_RememberToken_RememberTokenModel, beforeValidationOnSave)
{
	zval _0, _3, _6, _7, _1$$3, _2$$3, _4$$4, _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("created_at"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Y-m-d\\TH:i:sP");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "date", NULL, 13, &_1$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("created_at"), &_2$$3);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("expired_at"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_3))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "Y-m-d\\TH:i:sP");
		ZEPHIR_CALL_FUNCTION(&_5$$4, "date", NULL, 13, &_4$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("expired_at"), &_5$$4);
	}
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "Y-m-d\\TH:i:sP");
	ZEPHIR_CALL_FUNCTION(&_7, "date", NULL, 13, &_6);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("updated_at"), &_7);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_RememberToken_RememberTokenModel, beforeValidationOnUpdate)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Y-m-d\\TH:i:sP");
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, 13, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("updated_at"), &_1);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_RememberToken_RememberTokenModel, getToken)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "token");
}

PHP_METHOD(Phalcon_Auth_RememberToken_RememberTokenModel, getUserAgent)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "user_agent");
}

