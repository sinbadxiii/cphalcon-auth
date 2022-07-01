<?php

namespace Phalcon\Tests\Auth;

use Phalcon\Auth\Manager;
use Phalcon\Config\Config;
use Phalcon\Encryption\Security;

class AuthTest extends AbstractTestCase
{
    /** @test */
    public function itShouldReturnMatchingDefaultGuardFromConfig()
    {
        $configAuth = new Config([
            'auth' => [
                'defaults' => [
                    'guard' => 'web',
                    'passwords' => 'users',
                ],
                'guards' => [
                    'web' => [
                        'driver' => 'session',
                        'provider' => 'users',
                    ],
                ],
                'providers' => [
                    'users' => [
                        'driver' => 'model',
                        'model'  => \Users::class,
                    ]
                ]
            ],
        ]);

        $auth = new Manager(
            $configAuth->auth, new Security()
        );

        $this::assertEquals(
            $configAuth->auth->defaults->guard, $auth->getDefaultDriver()
        );
    }
}
