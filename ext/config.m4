PHP_ARG_ENABLE(phalcon_auth, whether to enable phalcon_auth, [ --enable-phalcon_auth   Enable Phalcon_auth])

if test "$PHP_PHALCON_AUTH" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, PHALCON_AUTH_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_PHALCON_AUTH, 1, [Whether you have Phalcon_auth])
	phalcon_auth_sources="phalcon_auth.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c phalcon/auth/events/eventinterface.zep.c
	phalcon/auth/events/eventabstract.zep.c
	phalcon/auth/exceptions/exception.zep.c
	phalcon/auth/guards/basicauthinterface.zep.c
	phalcon/auth/guards/guardinterface.zep.c
	phalcon/auth/guards/guardstatefulinterface.zep.c
	phalcon/auth/middlewares/authenticatesrequestinterface.zep.c
	phalcon/auth/providers/providerinterface.zep.c
	phalcon/auth/remembertoken/remembertokeninterface.zep.c
	phalcon/auth/authenticatableinterface.zep.c
	phalcon/auth/events/afterlogin.zep.c
	phalcon/auth/events/beforelogin.zep.c
	phalcon/auth/events/logout.zep.c
	phalcon/auth/exceptions/configfilenotexistexception.zep.c
	phalcon/auth/exceptions/unauthorizedhttpexception.zep.c
	phalcon/auth/guards/sessionguard.zep.c
	phalcon/auth/guards/tokenguard.zep.c
	phalcon/auth/guards/userremember.zep.c
	phalcon/auth/manager.zep.c
	phalcon/auth/middlewares/authenticate.zep.c
	phalcon/auth/providers/modelprovider.zep.c
	phalcon/auth/remembertoken/remembertokenmodel.zep.c
	phalcon/auth/remembertoken/rememberinginterface.zep.c "
	PHP_NEW_EXTENSION(phalcon_auth, $phalcon_auth_sources, $ext_shared,, )
	PHP_ADD_BUILD_DIR([$ext_builddir/kernel/])
	for dir in "phalcon/auth phalcon/auth/events phalcon/auth/exceptions phalcon/auth/guards phalcon/auth/middlewares phalcon/auth/providers phalcon/auth/remembertoken"; do
		PHP_ADD_BUILD_DIR([$ext_builddir/$dir])
	done
	PHP_SUBST(PHALCON_AUTH_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([phalcon_auth], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([phalcon_auth], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/phalcon_auth], [php_PHALCON_AUTH.h])

fi
