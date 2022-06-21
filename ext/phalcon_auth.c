
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "phalcon_auth.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *phalcon_auth_events_eventinterface_ce;
zend_class_entry *phalcon_auth_providers_providerinterface_ce;
zend_class_entry *phalcon_auth_authenticatableinterface_ce;
zend_class_entry *phalcon_auth_guards_basicauthinterface_ce;
zend_class_entry *phalcon_auth_guards_guardinterface_ce;
zend_class_entry *phalcon_auth_guards_guardstatefulinterface_ce;
zend_class_entry *phalcon_auth_middlewares_authenticatesrequestinterface_ce;
zend_class_entry *phalcon_auth_remembertoken_remembertokeninterface_ce;
zend_class_entry *phalcon_auth_remembertoken_rememberinginterface_ce;
zend_class_entry *phalcon_auth_events_eventabstract_ce;
zend_class_entry *phalcon_auth_exceptions_exception_ce;
zend_class_entry *phalcon_auth_collection_user_ce;
zend_class_entry *phalcon_auth_collection_userscollection_ce;
zend_class_entry *phalcon_auth_events_afterlogin_ce;
zend_class_entry *phalcon_auth_events_beforelogin_ce;
zend_class_entry *phalcon_auth_events_logout_ce;
zend_class_entry *phalcon_auth_exceptions_configfilenotexistexception_ce;
zend_class_entry *phalcon_auth_exceptions_jsonnotvalidexception_ce;
zend_class_entry *phalcon_auth_exceptions_unauthorizedhttpexception_ce;
zend_class_entry *phalcon_auth_guards_sessionguard_ce;
zend_class_entry *phalcon_auth_guards_tokenguard_ce;
zend_class_entry *phalcon_auth_guards_userremember_ce;
zend_class_entry *phalcon_auth_manager_ce;
zend_class_entry *phalcon_auth_middlewares_authenticate_ce;
zend_class_entry *phalcon_auth_providers_fileprovider_ce;
zend_class_entry *phalcon_auth_providers_fileprovider_parser_ce;
zend_class_entry *phalcon_auth_providers_modelprovider_ce;
zend_class_entry *phalcon_auth_remembertoken_remembertokenmodel_ce;

ZEND_DECLARE_MODULE_GLOBALS(phalcon_auth)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(phalcon_auth)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Phalcon_Auth_Events_EventInterface);
	ZEPHIR_INIT(Phalcon_Auth_Providers_ProviderInterface);
	ZEPHIR_INIT(Phalcon_Auth_AuthenticatableInterface);
	ZEPHIR_INIT(Phalcon_Auth_Guards_BasicAuthInterface);
	ZEPHIR_INIT(Phalcon_Auth_Guards_GuardInterface);
	ZEPHIR_INIT(Phalcon_Auth_Guards_GuardStatefulInterface);
	ZEPHIR_INIT(Phalcon_Auth_Middlewares_AuthenticatesRequestInterface);
	ZEPHIR_INIT(Phalcon_Auth_RememberToken_RememberTokenInterface);
	ZEPHIR_INIT(Phalcon_Auth_RememberToken_RememberingInterface);
	ZEPHIR_INIT(Phalcon_Auth_Events_EventAbstract);
	ZEPHIR_INIT(Phalcon_Auth_Exceptions_Exception);
	ZEPHIR_INIT(Phalcon_Auth_Collection_User);
	ZEPHIR_INIT(Phalcon_Auth_Collection_UsersCollection);
	ZEPHIR_INIT(Phalcon_Auth_Events_AfterLogin);
	ZEPHIR_INIT(Phalcon_Auth_Events_BeforeLogin);
	ZEPHIR_INIT(Phalcon_Auth_Events_Logout);
	ZEPHIR_INIT(Phalcon_Auth_Exceptions_ConfigFileNotExistException);
	ZEPHIR_INIT(Phalcon_Auth_Exceptions_JsonNotValidException);
	ZEPHIR_INIT(Phalcon_Auth_Exceptions_UnauthorizedHttpException);
	ZEPHIR_INIT(Phalcon_Auth_Guards_SessionGuard);
	ZEPHIR_INIT(Phalcon_Auth_Guards_TokenGuard);
	ZEPHIR_INIT(Phalcon_Auth_Guards_UserRemember);
	ZEPHIR_INIT(Phalcon_Auth_Manager);
	ZEPHIR_INIT(Phalcon_Auth_Middlewares_Authenticate);
	ZEPHIR_INIT(Phalcon_Auth_Providers_FileProvider);
	ZEPHIR_INIT(Phalcon_Auth_Providers_FileProvider_Parser);
	ZEPHIR_INIT(Phalcon_Auth_Providers_ModelProvider);
	ZEPHIR_INIT(Phalcon_Auth_RememberToken_RememberTokenModel);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(phalcon_auth)
{
	
	zephir_deinitialize_memory();
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_phalcon_auth_globals *phalcon_auth_globals)
{
	phalcon_auth_globals->initialized = 0;

	/* Cache Enabled */
	phalcon_auth_globals->cache_enabled = 1;

	/* Recursive Lock */
	phalcon_auth_globals->recursive_lock = 0;

	/* Static cache */
	memset(phalcon_auth_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_phalcon_auth_globals *phalcon_auth_globals)
{
	
}

static PHP_RINIT_FUNCTION(phalcon_auth)
{
	zend_phalcon_auth_globals *phalcon_auth_globals_ptr;
	phalcon_auth_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(phalcon_auth_globals_ptr);
	zephir_initialize_memory(phalcon_auth_globals_ptr);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(phalcon_auth)
{
	
	zephir_deinitialize_memory();
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(phalcon_auth)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_PHALCON_AUTH_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_PHALCON_AUTH_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_PHALCON_AUTH_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_PHALCON_AUTH_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_PHALCON_AUTH_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(phalcon_auth)
{
#if defined(COMPILE_DL_PHALCON_AUTH) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	php_zephir_init_globals(phalcon_auth_globals);
	php_zephir_init_module_globals(phalcon_auth_globals);
}

static PHP_GSHUTDOWN_FUNCTION(phalcon_auth)
{
	
}


zend_function_entry php_phalcon_auth_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_phalcon_auth_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry phalcon_auth_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_phalcon_auth_deps,
	PHP_PHALCON_AUTH_EXTNAME,
	php_phalcon_auth_functions,
	PHP_MINIT(phalcon_auth),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(phalcon_auth),
#else
	NULL,
#endif
	PHP_RINIT(phalcon_auth),
	PHP_RSHUTDOWN(phalcon_auth),
	PHP_MINFO(phalcon_auth),
	PHP_PHALCON_AUTH_VERSION,
	ZEND_MODULE_GLOBALS(phalcon_auth),
	PHP_GINIT(phalcon_auth),
	PHP_GSHUTDOWN(phalcon_auth),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(phalcon_auth),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

/* implement standard "stub" routine to introduce ourselves to Zend */
#ifdef COMPILE_DL_PHALCON_AUTH
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(phalcon_auth)
#endif
