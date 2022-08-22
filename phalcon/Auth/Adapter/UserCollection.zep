namespace Phalcon\Auth\Adapter;

use Phalcon\Support\Collection;

class UserCollection extends Collection
{
    protected static collection;

    public function __construct(array data = [], bool insensitive = true)
    {
        let self::collection = data;
        parent::__construct(data, insensitive);
    }

    public function find(array credentials)
    {
        var field;

        if (array_key_first(credentials) === null) {
            let field = "email";
        }

        var term = credentials[field],
        keys = array_keys(array_column(self::collection, field), term),
        result;

        if keys !== null {
            var key;
            for key in keys {
                var data = self::collection[key];
                let data["id"] = key;
                let result[] = new User(data);
            }
        }

        return result;
    }

    public function first(array credentials)
    {
        var field = array_key_first(credentials);

        if (field === null) {
            let field = "email";
        }

        var term = credentials[field];
        var key = array_search(term, array_column(self::collection, field), true);

        if key !== false {
            var data = self::collection[key];
            let data["id"] = key;
            return new User(data);
        }

        return null;
    }
}
