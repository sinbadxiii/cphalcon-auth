namespace Phalcon\Auth\Providers\FileProvider;

use Phalcon\Auth\Exceptions\JsonNotValidException;
use Phalcon\Auth\Exceptions\Exception;
use Phalcon\Auth\Collection\UsersCollection;

class Parser
{
    public static function file(path)
    {
        if (!file_exists(path)) {
            throw new Exception("file dont exist");
        }

        var fileData = file_get_contents(path);

        return new UsersCollection(self::jsonValidate(fileData));
    }

    private static function jsonValidate(string data)
    {
        var result = json_decode(data, true), error;

        switch (json_last_error()) {
            case JSON_ERROR_NONE:
                let error = "";
                break;
            case JSON_ERROR_DEPTH:
                let error = "The maximum stack depth has been exceeded.";
                break;
            case JSON_ERROR_STATE_MISMATCH:
                let error = "Invalid or malformed JSON.";
                break;
            case JSON_ERROR_CTRL_CHAR:
                let error = "Control character error, possibly incorrectly encoded.";
                break;
            case JSON_ERROR_SYNTAX:
                let error = "Syntax error, malformed JSON.";
                break;
            case JSON_ERROR_UTF8:
                let error = "Malformed UTF-8 characters, possibly incorrectly encoded.";
                break;
            case JSON_ERROR_RECURSION:
                let error = "One or more recursive references in the value to be encoded.";
                break;
            // PHP >= 5.5.0
            case JSON_ERROR_INF_OR_NAN:
                let error = "One or more NAN or INF values in the value to be encoded.";
                break;
            case JSON_ERROR_UNSUPPORTED_TYPE:
                let error = "A value of a type that cannot be encoded was given.";
                break;
            default:
                let error = "Unknown JSON error occured.";
                break;
        }

        if (!empty(error)) {
            throw new JsonNotValidException(error);
        }

        return result;
    }
}