<?php

namespace Phalcon\Tests\Auth;

use Phalcon\Auth\AuthenticatableInterface;
use Phalcon\Auth\RememberingInterface;

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
        $userStub = new UserModelStub();

        $this->assertInstanceOf(AuthenticatableInterface::class, $userStub);
        $this->assertInstanceOf(RememberingInterface::class, $userStub);
    }

    /**
     * @test
     */
    public function itReturnsSameRememberToken(): void
    {
        $userStub = new UserModelStub();

        $rememberToken = new RememberTokenModelStub();
        $rememberToken->token = "Token";

        $userStub->setRememberToken($rememberToken);
        $this->assertSame($rememberToken, $userStub->getRememberToken());
    }

    /**
     * @test
     */
    public function itReturnsSameRememberTokenString(): void
    {
        $userStub = new UserModelStub();

        $rememberToken = new RememberTokenModelStub();
        $rememberToken->token = "Token";

        $userStub->setRememberToken($rememberToken);
        $this->assertEquals("Token", $userStub->getRememberToken()->getToken());
    }
}