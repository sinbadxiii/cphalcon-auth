<?php

namespace Phalcon\Tests\Auth;

use PHPUnit\Framework\TestCase;

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