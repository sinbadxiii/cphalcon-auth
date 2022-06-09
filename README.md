<p align="center">    
    <img width="150px" src="https://github.com/sinbadxiii/images/blob/master/cphalcon-auth/logo.png?raw=true">
</p>

# Phalcon Auth

PHP Extension Phalcon Auth for Phalcon framework by Zephir lang

[Based by Phalcon Auth](https://github.com/sinbadxiii/phalcon-auth)

## Installation

| Phalcon v3 | Phalcon v4 | Phalcon v5         | Phalcon v6
:-----------|:-----------|:-------------------| :----------
| :x:        | :x:        | :heavy_check_mark: | :question:

PHP ^7.4-8.1.

`git clone https://github.com/sinbadxiii/cphalcon-auth.git`

`cd cphalcon-auth/ext`

`sudo ./install`

and check that the extension is loaded in php

`php -m`

```
...
PDO
pdo_mysql
pdo_sqlite
phalcon
phalcon_auth
Phar
posix
...
```

Phalcon Auth will allow you to create an authentication system in your web application.

The general essence of an authentication system is to have "Guards" (Guard) and "Providers" (Provider) at hand, the guards determine how users will be authenticated, for example using standard Sessions, Session storage and Cookies.

Providers determine where users will be retrieved from. By default, this is, of course, `Phalcon\Model` and the database query builder.

![Banner](https://github.com/sinbadxiii/images/blob/master/phalcon-auth/auth-scheme.webp?raw=true)

## How use

### Config

1. Your application's authentication configuration file will either need to be located in your config folder, such as config/auth.php or global config.php file with access by "auth" key (`$this->config->auth`).

```php
<?php

...
    'auth' => [
        'defaults' => [
            'guard' => 'web',
            'passwords' => 'users',
        ],
        'guards' => [
            'web' => [
                'driver' => 'session', //session || token
                'provider' => 'users',
            ],
        ],
        'providers' => [
            'users' => [
                'driver' => 'model',
                'model'  => \Models\Users::class,
            ]
        ]
    ],
...
```