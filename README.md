<p align="center">    
    <img width="150px" src="https://github.com/sinbadxiii/images/blob/master/cphalcon-auth/logo.png?raw=true">
</p>

# Phalcon Auth

PHP Extension Phalcon Auth for Phalcon framework by Zephir lang

[Based by Phalcon Auth PHP](https://github.com/sinbadxiii/phalcon-auth)

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

### 5. Users

Implement your model Users fom `Phalcon\Auth\AuthenticatableInterface` and `Phalcon\Auth\RememberToken\RememberingInterface`, example:

```php 
<?php 

namespace Models;

use Phalcon\Di\Di;
use Phalcon\Auth\RememberToken\RememberTokenModel;
use Phalcon\Auth\AuthenticatableInterface;
use Phalcon\Auth\RememberToken\RememberingInterface;
use Phalcon\Auth\RememberToken\RememberTokenInterface;

class Users extends BaseModel implements AuthenticatableInterface, RememberingInterface
{  
    public function initialize()
    {
        $this->setSource('users');

        $this->hasOne(
            'id',
            RememberTokenModel::class,
            'user_id',
            [
                'alias' => "remember_token"
            ]
        );
        $this->keepSnapshots(true);
    }
    
    public function setPassword(string $password)
    {
        $this->password = Di::getDefault()->getShared("security")->hash($password);
        return $this;
    }

    public function getAuthIdentifier()
    {
        return $this->id;
    }

    public function getAuthPassword()
    {
        return $this->password;
    }

    /**
    * @param string|null $token
    * @return RememberTokenInterface|null|false
    */
    public function getRememberToken(string $token = null): ?RememberTokenInterface
    {
        return $this->getRelated('remember_token', [
            'token=:token:',
            'bind' => ['token' => $token]
        ]);
    }

    public function setRememberToken(RememberTokenInterface $value)
    {
        $this->remember_token = $value;
    }
}
```

## Authenticated and Guest Controllers

Controllers can have an `$authAccess` property or an `authAccess()` method that, depending on the value, will restrict access.

For example, in these cases, access to the controllers will be possible even for non-authenticated users:

```php 
<?php

namespace App\Controllers;

use Phalcon\Mvc\Controller;

//Guest Controller
class PostsController extends Controller
{
    public $authAccess = false;
    
    ...
}
```

or method `authAccess()`:

```php 
<?php

namespace App\Controllers;

use Phalcon\Mvc\Controller;

class ProfileController extends Controller
{
    public function authAccess(): bool
    {
        return true;
    }
}
```

By default `$authAccess` = `true`.

## Methods

### Checking the authentication of the current user
To determine if the user making the incoming HTTP request is authenticated, you can use the `check()` method. This method will return `true` if the user is authenticated:

```php
$this->auth->check(); 
//check authentication
```

for example, you can check on the login form page that if the user is logged in, then do not show him the input form:

```php
public function loginFormAction()
{
    if ($this->auth->check()) { 
        //redirect to profile page 
        return $this->response->redirect(
            "/profile", true
        );
    }
}
```

### Getting the authenticated user

When processing an incoming request, you can access the authenticated user through the `user()` method. The result will be the provider specified in the auth.php config, according to the Phalcon\Model Users standard of the users table.

You can also request a user identifier (ID) using the `id()` method:

```php 
$this->auth->user(); //get the user

$this->auth->id(); //get user id
```

### Authentication attempt

The `attempt()` method is used to handle authentication attempts from your application's login form:

```php 
$username = $this->request->getPost("username");
$password = $this->request->getPost("password");

//attempt login with credentials
if ($this->auth->attempt(['username' => $username, 'password' => $password])) {

 //success attempt
 ...
}

//fail attempt
```

The `attempt()` method takes an array of key/value pairs as its first argument. The values in the array will be used to look up the user in the users database table. So, in the example above, the user will be retrieved by the value of the username column. If the user is found, the hashed password stored in the database will be compared against the password value passed to the method. You should not hash the value of the incoming password request, as the password is already automatically hashed to compare it with the hashed password in the database. An authenticated session will be started for the user if the hashed passwords match.

Remember that users from your database will be queried based on the "provider" configuration. The default auth configuration specifies the user provider = "model" (Phalcon\Model) and is instructed to use the \Models\User model to get users. You can change these values in the configuration file depending on the needs of your application.

The `attempt()` method will return `true` if the authentication was successful. Otherwise, `false` will be returned.

### Specifying additional conditions

You can also add additional query conditions in addition to the user's email/username and password. To do this, simply add the request conditions to the array passed to the `attempt()` method. For example, we can check if a user is marked as "is_published":
```php 
$username = $this->request->getPost("username");
$password = $this->request->getPost("password");

//attempt login with additional credentials
if ($this->auth->attempt(['username' => $username, 'password' => $password, 'is_published' => 1])) {

 //success attempt
 ...
}

//fail attempt
```

### "Remember me"

If you want to provide "remember me" functionality in your application, you can pass a boolean value as the second argument to the attempt method.

When this value is true, the user will be authenticated indefinitely or until the user logs out manually by logout. The `users_remember_tokens` table contains a token string column that will be used to store the "remember me" token:

```php 
$username = $this->request->getPost("username");
$password = $this->request->getPost("password");
$remember = this->request->getPost('remember') ? true : false;

//attempt login with credentials and remember
if ($this->auth->attempt(['username' => $username, 'password' => $password], $remember)) {

 //success attempt
 ...
}

//fail attempt
```

Use the `viaRemember()` method to check if the user is authenticated with the "remember me" cookie:

```php
//use method viaRemember to check the user was authenticated using the remember me cookie
$this->auth->viaRemember();
```

### Authenticate user instance

If you need to set an existing user instance as the currently authenticated user, you can pass the user instance to the `login()` method. This user instance must be an implementation of Phalcon\Auth\AuthenticatableInterface. 

This authentication method is useful when you already have a valid user instance, such as right after the user has registered with your application:

```php

$userId = 1;

$user = Users::findFirst($userId);
// Login and Remember the given user
$this->auth->login($user, $remember = true);
```
### Authenticate user by ID

To authenticate a user using the primary key of a database entry, you can use the `loginById()` method. This method accepts the primary key of the user you wish to authenticate:

```php

$userId = 1;

//and force login user by id 
$this->auth->loginById($userId, true);
```

### Authenticate user once

Using the `once()` method you can authenticate a user in an application for a single request. Calling this method will not use sessions or cookies:

```php
//once auth without saving session and cookies
$username = $this->request->getPost("username");
$password = $this->request->getPost("password");

$this->auth->once(['username' => $username, 'password' => $password]);
```

## Log out

To manually log out a user from your application, you can use the `logout()` method. This will remove all authentication information from the user's session, so that subsequent requests will no longer be authenticated:

```php

$this->auth->logout();
//log out user 
```

## HTTP Basic Authentication

[HTTP Basic Authentication](https://en.wikipedia.org/wiki/Basic_access_authentication) provides a quick way to authenticate users of your application without setting up a special "login" page. It is enough to pass in the `Authorization` header, the value `Basic` and a pair of email (or other user field) and password, separated by a colon and encoded `base64_encode()`

First, create an AuthBasic middleware with the `$this->auth->basic("email")` method and attach a dispatcher to the service provider as described above.

The `email` argument specifies that the user will be searched for the email and password fields. By specifying another field, such as `username`, the search will be performed on the username and password pair.

```php 
<?php

declare(strict_types=1);

namespace App\Security;

use Phalcon\Auth\Middlewares\Authenticate as AuthMiddleware;

/**
 * Class AuthenticateWithBasic
 * @package App\Security
 */
class AuthenticateWithBasic extends AuthMiddleware
{
    /**
     * @var
     */
    protected $message;

    /**
     * @return bool
     */
    protected function authenticate()
    {
        try {
            if ($this->auth->basic("email") || $this->isGuest()) {
                return true;
            }
        } catch (\Throwable $e) {
            $this->message = $e->getMessage();
        } 
        $this->unauthenticated();
    }

    /**
     * @return \Phalcon\Http\ResponseInterface|void
     */
    protected function redirectTo()
    {
        if (isset($this->response)) {
            $this->response->setJsonContent(
                [
                    'message' => $this->message ?? "Unauthorized Error"
                ]
            )->setStatusCode(401)->send();
        }
    }
}

```

```php
$di->setShared("dispatcher", function () use ($di) {
    $dispatcher = new Dispatcher();

    $eventsManager = $di->getShared('eventsManager');
    $eventsManager->attach('dispatch', new AuthenticateWithBasic());
    $dispatcher->setEventsManager($eventsManager);

    return $dispatcher;
});
```

After the request, a user is logged into the session, and subsequent requests may no longer contain user data in the `Authorization` header, until the session "dies out".

### Basic HTTP stateless authentication

You can use HTTP basic authentication without keeping the user in session. This is primarily useful if you decide to use HTTP authentication to authenticate requests to your application's API. To do this, define a middleware that calls the `onceBasic()` method, for example:

```php 
<?php

declare(strict_types=1);

namespace App\Security;

use Phalcon\Auth\Middlewares\Authenticate as AuthMiddleware;

/**
 * Class AuthenticateWithOnceBasic
 * @package App\Security
 */
class AuthenticateWithOnceBasic extends AuthMiddleware
{
    /**
     * @var
     */
    protected $message;

    /**
     * @return bool
     */
    protected function authenticate()
    {
        try {
            if ($this->auth->onceBasic("email") || $this->isGuest()) {
                return true;
            }
        } catch (\Throwable $e) {
            $this->message = $e->getMessage();
        }
        $this->unauthenticated();
    }

    /**
     * @return \Phalcon\Http\ResponseInterface|void
     */
    protected function redirectTo()
    {
        if (isset($this->response)) {
            $this->response->setJsonContent(
                [
                    'message' => $this->message ?? "Unauthorized Error"
                ]
            )->setStatusCode(401)->send();
        }
    }
}
```

After the request, neither the cookie nor the session will contain user data, and the next request must also contain the user's `Authorization` header data, otherwise a `Phalcon\Auth\Exceptions\UnauthorizedHttpException;`















