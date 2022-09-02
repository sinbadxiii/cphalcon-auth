namespace Phalcon\Auth\Adapter;

use InvalidArgumentException;
use Exception;

class Stream extends Memory
{
    protected srcFile;

    public function getData()
    {
        if this->config && !isset(this->config["src"]) {
            throw new InvalidArgumentException(
                "Сonfig key 'src' with path source file not exist"
            );
        }

        if !empty(this->config["src"]) {
            let this->srcFile = this->config["src"];
        }

         if (empty(this->data) && empty(this->srcFile)) {
            throw new InvalidArgumentException(
                "File source is empty"
            );
        }

        if (empty(this->data)) {
            let this->data = this->read(this->srcFile);
        }

        if (empty(this->data)) {
            throw new InvalidArgumentException(
                "Data is empty"
            );
        }

        return this->data;
    }

    public function read(string src)
    {
        var fileData;

        if (!file_exists(src)) {
            throw new Exception(src . " file don't exist");
        }

        let fileData = file_get_contents(src);

        return this->validate(fileData, $src);
    }

    private function validate(var fileData, string src) -> var
    {
        var decoded;
        let decoded = json_decode(fileData, true);

        if unlikely JSON_ERROR_NONE !== json_last_error() {
            throw new InvalidArgumentException(
                src . " json_decode error: " . json_last_error_msg()
            );
        }

        return decoded;
    }

    public function getFileSource() -> string
    {
        return this->srcFile;
    }

    public function setFileSource(string src) -> void
    {
        let this->srcFile = src;
    }
}