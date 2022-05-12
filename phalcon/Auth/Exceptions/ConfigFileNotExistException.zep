namespace Phalcon\Auth\Exceptions;

class ConfigFileNotExistException extends Exception
{
    protected message = "Configuration file auth.php (or key ->auth into your config) does not exist";
}
