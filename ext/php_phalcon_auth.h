
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_PHALCON_AUTH_H
#define PHP_PHALCON_AUTH_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_PHALCON_AUTH_NAME        "Phalcon Auth"
#define PHP_PHALCON_AUTH_VERSION     "2.0.0"
#define PHP_PHALCON_AUTH_EXTNAME     "phalcon_auth"
#define PHP_PHALCON_AUTH_AUTHOR      "Sergey Mukhin"
#define PHP_PHALCON_AUTH_ZEPVERSION  "0.18.0-$Id$"
#define PHP_PHALCON_AUTH_DESCRIPTION "Phalcon Auth - Guard-Based Authentication"



ZEND_BEGIN_MODULE_GLOBALS(phalcon_auth)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(phalcon_auth)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(phalcon_auth)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(phalcon_auth, v)
#else
	#define ZEPHIR_GLOBAL(v) (phalcon_auth_globals.v)
#endif

#ifdef ZTS
	ZEND_TSRMLS_CACHE_EXTERN()
	#define ZEPHIR_VGLOBAL ((zend_phalcon_auth_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(phalcon_auth_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(phalcon_auth_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def phalcon_auth_globals
#define zend_zephir_globals_def zend_phalcon_auth_globals

extern zend_module_entry phalcon_auth_module_entry;
#define phpext_phalcon_auth_ptr &phalcon_auth_module_entry

#endif
