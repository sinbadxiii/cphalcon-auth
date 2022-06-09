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

### 1. Config

Your application's authentication configuration file will either need to be located in your config folder, such as config/auth.php or global config.php file with access by "auth" key (`$this->config->auth`).

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

#### 1.1. Config Session

With the default auth configuration - `defaults => guard => 'web'` and `driver => 'session'`, the user enters their username and password using the login form. 

If these credentials are correct, the application will store information about the authenticated user in the user's session. 

The cookie sent to the browser contains the session ID so that subsequent requests to the application can associate the user with the correct session. After receiving the session cookie, the application will retrieve the session data based on the session id, note that the authentication information will be stored in the session, and will consider the user to be "authenticated".

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
                'driver' => 'session',
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

#### 1.2. Config Token

If the auth configuration is set to `defaults => guard => 'api'` and `driver => 'token'`, this setting will allow authentication to access your API application, cookies are usually not used for authentication due to lack of web -browser. Instead, the remote service sends an API token on every request. The application can validate the incoming token against a table of valid API tokens and "authenticate" the request as being made by the user associated with that API token.

```php
<?php

...
    'auth' => [
        'defaults' => [
            'guard' => 'api',
            'passwords' => 'users',
        ],
        'guards' => [
            'api' => [
                'driver' => 'token',
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

By default, the name of the parameter in the request and the field in the database is equal to `auth_token`, 

for example GET request:

```
//GET
https://yourapidomain/api/v2/users?auth_token=fGa$gdGPSfEgT41r3F4fg#^33
```

or POST:

```
//POST
//params POST request 
[
    "auth_token": "fGa$gdGPSfEgT41r3F4fg#^33"
]

https://yourapidomain/api/v2/users
```

or `Authorization` header:

```

Authorization: Bearer fGa$gdGPSfEgT41r3F4fg#^33

https://yourapidomain/api/v2/users
```

### 2. Database

Import files to create tables in the database `db/users.sql`, `db/users_remember_tokens.sql` and `db/create_auth_token_users.sql` if the auth_token field is needed

### 3. Register a service provider 

By default `Phalcon\Auth\Manager` will use auth config from `$this->config->auth`.
```php 
$di->setShared('auth', function () {
    return new Phalcon\Auth\Manager();
});
```

Or explicitly pass your auth config:

```php 
$di->setShared('auth', function () {
    $authConfig = $this->getConfig()->get("auth");
    
    return new \Phalcon\Auth\Manager($authConfig);
});
```

### 5. Middleware

Create middleware extends from `Phalcon\Auth\Middlewares\Authenticate`

example:

```php
declare(strict_types=1);

namespace App\Security;

use Phalcon\Auth\Middlewares\Authenticate as AuthMiddleware;

/**
 * Class Authenticate
 * @package App\Security
 */
class Authenticate extends AuthMiddleware
{
    /**
     * @return \Phalcon\Http\ResponseInterface|void
     */
    protected function redirectTo()
    {
        if (isset($this->response)) {
            $this->response->redirect("/login")->send();
        }
    }
}
```

and attach it in your service dispatcher:

```php
$di->setShared("dispatcher", function () use ($di) {
    $dispatcher = new Dispatcher();

    $eventsManager = $di->getShared('eventsManager');
    $eventsManager->attach('dispatch', new Authenticate());
    $dispatcher->setEventsManager($eventsManager);

    return $dispatcher;
});
```

When the middleware detects an unauthenticated user, it executes the `redirectTo()` method, by default the redirect goes to the url you need (the same login form, for example), you can change this behavior, for example, return a json response if an ajax request is used for authentication:

```php

protected function redirectTo()
{
    $this->response->setJsonContent(
                    [
                        'success' => false,
                        'message' => 'Authentication failure'
                    ], JSON_UNESCAPED_UNICODE
                );

    if (!$this->response->isSent()) {
        $this->response->send();
    } 
}
```