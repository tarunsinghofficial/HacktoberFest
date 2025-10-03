# api-guide

## /register

### Request Body

```
{
    "name":"",
    "email":"",
    "username":"",
    "password":"",
    "mobile":"",
}
```

### Response Body

```
{
   'status': True,
   'msg': "Registration Successfull"
}
```

```
{
   "status":"false",
   "msg":"User exists or incorrect details"
}
```

## /login

### Request Body

```
{
    "email/username/mobile":"",
    "password":"",
}
```

### Response Body

```
{
    "msg": "Login Successful",
    "status": true,
    "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9",
    "user_data": {
        "email": "satish.b.s.kumar@gmail.com",
        "name": "satish"
    }
}
```

```
{
   "status":"false",
   "msg":"incorrect credentials"
}
```

## /login/otp_generate

### Request Body

```
{
	"mobile":"<ten digit mobile number>"
}
```

### Response Body

```
{
    "msg": "OTP generated",
    "status": true
}
```

```
{
    "msg": "mobile number not registered",
    "status": false
}
```

## /login/otp_verify

### Request Body

```
{
	"mobile":"<ten digit mobile number",
	"otp":"XXXX"
}
```

### Response Body

```
{
    "msg": "Login Successful",
    "status": true,
    "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9",
    "user_data": {
        "email": "satish.b.s.kumar@gmail.com",
        "name": "satish"
    }
}
```

```
{
    "msg": "Incorrrect OTP",
    "status": false
}
```

## /login/oauth

### Request Body

```
{
  "name":"xxxx",
  "email":"email@gmail.com",
  "provider":"google",
  "access_token":"dcsfdgfhgfjdfghsdgsdfg"
}
```

### Response Body

```
{
    "msg": "Login Successful",
    "status": true,
    "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9",
    "user_data": {
        "email": "satish.b.s.kumar@gmail.com",
        "name": "satish"
    }
}
```

```
{
    "msg": "Incorrrect Credentials",
    "status": false
}
```

## /logout

### Request Header

```
{
  "auth_token":"dcsfdgfhgfjdfghsdgsdfg"
}
```

### Response Body

```
{
    "msg": "Logout Successful",
    "status": true
}
```
