namespace Phalcon\Auth\Adapter;

use InvalidArgumentException;
use Exception;

class Stream extends AbstractAdapter
{
    protected function getProviderStorage() -> var
    {
        return this->read(this->config->src);
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
}