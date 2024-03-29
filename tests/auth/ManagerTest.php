<?php

namespace Phalcon\Tests\Auth;

use Phalcon\Config\Config;
use Phalcon\Encryption\Security;
use Phalcon\Auth\Access\Auth;
use Phalcon\Auth\Access\Guest;
use Phalcon\Auth\Adapter\Memory;
use Phalcon\Auth\Adapter\Model;
use Phalcon\Auth\Adapter\Stream;
use Phalcon\Auth\Manager;
use Phalcon\Auth\ManagerInterface;

/**
 * Class ManagerTest
 * @package Phalcon\Tests\Auth
 */
class ManagerTest extends AbstractTestCase
{
    protected $manager;
    protected $security;
    protected $config;

    protected function setUp(): void
    {
        $this->config = new Config(require (__DIR__ . "/../config/auth.php"));
        $this->security = new Security();
        $this->manager = new Manager(
            $this->config->auth, $this->security
        );
    }

    /**
     * @test
     */
    public function implementFromManagerInterface(): void
    {
        $this->assertInstanceOf(ManagerInterface::class, $this->manager);
    }

    /** @test */
    public function itShouldReturnMatchingDefaultGuardFromConfig()
    {
        $this::assertEquals(
            $this->config->auth->defaults->guard, $this->manager->getDefaultDriver()
        );
    }

    /** @test */
    public function itShouldReturnMatchingModelAdapterProviderByConfig()
    {
        $this::assertEquals(
            new Model($this->security, $this->config->auth->providers->users), $this->manager->getAdapterProvider("users")
        );
    }

    /** @test */
    public function itShouldReturnMatchingStreamAdapterProviderByConfig()
    {
        $this->config->auth->providers->users->adapter = "stream";

        $this::assertEquals(
            new Stream($this->security, $this->config->auth->providers->users), $this->manager->getAdapterProvider("users")
        );
    }

    /** @test */
    public function itShouldReturnMatchingMemoryAdapterProviderByConfig()
    {
        $this->config->auth->providers->users->adapter = "memory";

        $this::assertEquals(
            new Memory($this->security, $this->config->auth->providers->users), $this->manager->getAdapterProvider("users")
        );
    }

    /** @test */
    public function itShouldReturnSetAuthAccess()
    {
        $authAccess = new Auth();
        $this->manager->setAccess($authAccess);

        $this::assertEquals(
            $authAccess, $this->manager->getAccess()
        );
    }

    /** @test */
    public function itShouldReturnSetGuestAccess()
    {
        $guestAccess = new Guest();
        $this->manager->setAccess($guestAccess);

        $this::assertEquals(
            $guestAccess, $this->manager->getAccess()
        );
    }

    /** @test */
    public function itShouldReturnAccess()
    {
        $this->manager->setAccessList(
            [
                'auth'  => Auth::class,
                'guest' => Guest::class,
            ]
        );

        $this::assertEquals(
            new Auth(), $this->manager->access("auth")
        );
        $this::assertEquals(
            new Guest(), $this->manager->access("guest")
        );
    }

    /** @test */
    public function itShouldReturnExceptionNotIncludeAccess()
    {
        $this::expectException(\InvalidArgumentException::class);

        $this->manager->setAccessList(
            [
                'auth'  => Auth::class,
                'guest' => Guest::class
            ]
        );

        $this->manager->access("admin");
    }
}
