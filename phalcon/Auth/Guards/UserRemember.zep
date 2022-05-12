namespace Phalcon\Auth\Guards;

class UserRemember
{
    protected data;

    public function __construct(data)
    {
        let this->data = json_decode($data, false, 512, JSON_THROW_ON_ERROR);
    }

    public function id()
    {
        return this->data->id;
    }

    public function token()
    {
        return this->data->token;
    }

    public function userAgent()
    {
        return this->data->user_agent;
    }
}