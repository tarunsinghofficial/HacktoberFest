# Django URL Shortener API

A simple Postgres backed URL Shortener API made using Django REST Framework.

[![DeepSource](https://deepsource.io/gh/infinity-plus/django-url-shortener-api.svg/?label=active+issues&token=_l-MfykM4kr2fFPN2lVV8afr)](https://deepsource.io/gh/infinity-plus/django-url-shortener-api/?ref=repository-badge)
[![DeepSource](https://deepsource.io/gh/infinity-plus/django-url-shortener-api.svg/?label=resolved+issues&token=_l-MfykM4kr2fFPN2lVV8afr)](https://deepsource.io/gh/infinity-plus/django-url-shortener-api/?ref=repository-badge)

## `shortenedURL` Object

A single `shortenedURL` in JSON looks as:

```json
{
    "created": "2021-07-14T20:06:35.314848+05:30",
    "long_url": "https://yaifoundation.org",
    "short_url": "site",
    "times_visited": 32
}
```

## Endpoints

|     Endpoint    | Request |               Response                 |
| :-------------: | :-----: | :------------------------------------- |
| `/` |   GET   | Status of API.                         |
| `/urls/` |   GET   | Array of shortenedURL Objects          |
|                 |   POST  | Create a shortened URL                 |
| `/v/<ShortURL>` |   GET   | Get particular shortenedURL object     |
|                 |   PUT   | Update an existing shortenedURL object |
|                 | DELETE  | Delete an existing shortenedURL object |

## Environment Variables

|       Variable        | Required | Default | Description |
| :-------------------: | :------: | ------- | ----------- |
|      SECRET_KEY       | &#9745; | None | This value is the key to securing signed data – it is vital you keep this secure, or attackers could use it to generate their own signed values. |
|     DATABASE_URL      | &#9745; | None | The valid Postgres Connection URI |
|         HOSTS         | &#9744; | None | A space-separated list of hosts supported by the Django App. |
| DISABLE_COLLECTSTATIC | &#9744; | None | Set to 1 to disable collectstatic. |
