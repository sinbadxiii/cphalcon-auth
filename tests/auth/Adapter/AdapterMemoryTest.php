<?php

namespace Phalcon\Tests\Auth\Adapter;

use Phalcon\Config\Config;
use Phalcon\Encryption\Security;
use Phalcon\Auth\Adapter\User;
use Phalcon\Auth\Manager;
use Phalcon\Tests\Auth\AbstractTestCase;

/**
 * Class AdapterTest
 * @package Phalcon\Tests\Auth
 */
class AdapterMemoryTest extends AbstractTestCase
{
    protected $manager;
    protected $security;
    protected $config;

    /** @test */
    public function itShouldReturnFromAdapterMemoryUser()
    {
        $this->config = new Config(require (__DIR__ . "/../../config/auth.php"));

        $this->config->auth->providers->users->adapter = "memory";

        $data = [
            0 => ["id" => 1, "name" => "user", "password" => "54325"],
            1 => ["id" => 2, "name" => "user2", "password" => "54225"],
            2 => ["id" => 3, "name" => "user3", "password" => "34225"],
        ];

        $this->config->auth->providers->users->data = $data;

        $this->security = new Security();
        $this->manager = new Manager(
            $this->config->auth, $this->security
        );
        $providerAdapterMemory = $this->manager->getAdapterProvider("users");

        $this->assertEquals(new User($data[0]), $providerAdapterMemory->retrieveById(0));
        $this->assertEquals(new User($data[1]), $providerAdapterMemory->retrieveByCredentials(["name" => "user2"]));
        $this->assertEquals((new User($data[2]))->getId(), 3);
    }
}
