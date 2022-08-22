<?php

namespace Phalcon\Tests\Auth;

use Phalcon\Di\Injectable;
use Phalcon\Auth\Access\Authenticate;
use Phalcon\Auth\Access\AuthenticatesRequestInterface;
use Phalcon\Tests\Auth\AbstractTestCase;

/**
 * Class AuthenticateTest
 * @package Sinbadxiii\PhalconAuth\Tests\Access
 */
class AuthenticateTest extends AbstractTestCase
{
    /**
     * @test
     */
    public function implementFromAuthenticatesRequest(): void
    {
        $this->assertInstanceOf(AuthenticatesRequestInterface::class, new Authenticate());
        $this->assertInstanceOf(Injectable::class, new Authenticate());
    }
}