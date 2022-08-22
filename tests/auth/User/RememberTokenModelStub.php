<?php

declare(strict_types=1);

namespace Phalcon\Tests\Auth;

use Phalcon\Auth\RememberTokenInterface;

class RememberTokenModelStub implements  RememberTokenInterface
{
    public $id;
    public $user_id;
    public $token;
    public $ip;
    public $user_agent;
    public $created_at;
    public $updated_at;
    public $expired_at;

    public function getToken(): string
    {
        return $this->token;
    }

    public function getUserAgent(): string
    {
        return $this->user_agent;
    }
}