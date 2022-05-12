namespace Phalcon\Auth\RememberToken;

use Phalcon\Mvc\Model;
use Phalcon\Di\Di;

class RememberTokenModel extends Model implements  RememberTokenInterface
{
    public id;
    public user_id;
    public token;
    public ip;
    public user_agent;
    public created_at;
    public updated_at;
    public expired_at;

    public function initialize()
    {
        var configAuth = Di::getDefault()->getShared("config")->auth,
        guard = configAuth->defaults->guard,
        tableRememberToken = sprintf("%s_remember_tokens", configAuth->guards->{guard}->provider);
        this->setSource(tableRememberToken);
    }

    public function beforeValidationOnCreate()
    {
        let this->created_at = date(DATE_ATOM);
        let  this->updated_at = date(DATE_ATOM);
        if (!this->expired_at) {
            let this->expired_at = date(DATE_ATOM);
        }
    }

    public function beforeValidationOnSave()
    {
        if (!this->created_at) {
            let this->created_at = date(DATE_ATOM);
        }
        if (!this->expired_at) {
            let this->expired_at = date(DATE_ATOM);
        }
        let this->updated_at = date(DATE_ATOM);
    }

    public function beforeValidationOnUpdate()
    {
        let this->updated_at = date(DATE_ATOM);
    }

    public function getToken() -> string
    {
        return this->token;
    }

    public function getUserAgent() -> string
    {
        return this->user_agent;
    }
}