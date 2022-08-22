namespace Phalcon\Auth\Adapter;

use InvalidArgumentException;
use Exception;

class Stream extends CollectionAdapterAbstract implements AdapterInterface
{
    protected function getData()
    {
        return this->read(this->config->src);
    }

    public function read(string path)
    {
        var fileData;

        if (!file_exists(path)) {
            throw new Exception("file dont exist");
        }

        let fileData = file_get_contents(path);

        return this->validate(fileData, $path);
    }

    private function validate(string fileData, var filepath) -> var
    {
        var decoded;
        let decoded = json_decode(fileData, true);

        if unlikely JSON_ERROR_NONE !== json_last_error() {
            throw new InvalidArgumentException(
                filepath . " json_decode error: " . json_last_error_msg()
            );
        }

        return decoded;
    }
}