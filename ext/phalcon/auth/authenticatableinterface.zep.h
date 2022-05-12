
extern zend_class_entry *phalcon_auth_authenticatableinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_AuthenticatableInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_authenticatableinterface_getauthidentifier, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_authenticatableinterface_getauthpassword, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_authenticatableinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Auth_AuthenticatableInterface, getAuthIdentifier, arginfo_phalcon_auth_authenticatableinterface_getauthidentifier)
	PHP_ABSTRACT_ME(Phalcon_Auth_AuthenticatableInterface, getAuthPassword, arginfo_phalcon_auth_authenticatableinterface_getauthpassword)
	PHP_FE_END
};
