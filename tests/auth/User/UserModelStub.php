<?php

namespace Phalcon\Tests\Auth;

use Phalcon\Auth\AuthenticatableInterface;
use Phalcon\Auth\RememberingInterface;
use Phalcon\Auth\RememberTokenInterface;

/**
 * Class UserStub
 * @package Phalcon\Tests\Auth\\User
 */
class UserModelStub implements AuthenticatableInterface, RememberingInterface
{
    public int $id;
    public string $password;
    public RememberTokenInterface $remember_token;

    public function getAuthIdentifier(): int
    {
        return $this->id;
    }

    public function getAuthPassword(): string
    {
        return $this->password;
    }

    public function setRememberToken(RememberTokenInterface $value): static
    {
        $this->remember_token = $value;

        return $this;
    }

    public function createRememberToken(): RememberTokenInterface
    {
        return new RememberTokenModelStub();
    }

    public function getRememberToken(string $token = null): ?RememberTokenInterface
    {
        return $this->remember_token;
    }
}