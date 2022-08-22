<?php

namespace Phalcon\Tests\Auth;

use PHPUnit\Framework\TestCase;

/**
 * Class AbstractTestCase
 * @package Phalcon\Tests\Auth
 */
abstract class AbstractTestCase extends TestCase
{
    public function flushAll()
    {
        $_SERVER  = [];
        $_REQUEST = [];
        $_POST    = [];
        $_GET     = [];
    }
}