
extern zend_class_entry *phalcon_auth_managerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_ManagerInterface);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_managerinterface_guard, 0, 0, Phalcon\\Auth\\Guard\\GuardInterface, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_managerinterface_access, 0, 1, Phalcon\\Auth\\Access\\AccessInterface, 1)
	ZEND_ARG_TYPE_INFO(0, accessName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_managerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Auth_ManagerInterface, guard, arginfo_phalcon_auth_managerinterface_guard)
	PHP_ABSTRACT_ME(Phalcon_Auth_ManagerInterface, access, arginfo_phalcon_auth_managerinterface_access)
	PHP_FE_END
};
