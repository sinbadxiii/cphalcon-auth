<?php

namespace Phalcon\Tests\Auth\User;

use Phalcon\Auth\AuthenticatableInterface;
use Phalcon\Auth\RememberingInterface;
use Phalcon\Tests\Auth\AbstractTestCase;

/**
 * Class UsersTest
 * @package Phalcon\Tests\Auth\User
 */
class UserTest extends AbstractTestCase
{
    /**
     * @test
     */
    public function itImplementModel(): void
    {
        $userFake = new UserModelFake();

        $this->assertInstanceOf(AuthenticatableInterface::class, $userFake);
        $this->assertInstanceOf(RememberingInterface::class, $userFake);
    }

    /**
     * @test
     */
    public function itReturnsSameRememberToken(): void
    {
        $userFake = new UserModelFake();

        $rememberToken = new RememberTokenModelFake();
        $rememberToken->token = "Token";

        $userFake->setRememberToken($rememberToken);
        $this->assertSame($rememberToken, $userFake->getRememberToken());
    }

    /**
     * @test
     */
    public function itReturnsSameRememberTokenString(): void
    {
        $userFake = new UserModelFake();

        $rememberToken = new RememberTokenModelFake();
        $rememberToken->token = "Token";

        $userFake->setRememberToken($rememberToken);
        $this->assertEquals("Token", $userFake->getRememberToken()->getToken());
    }
}