import validators
valid=validators.url('https://www.codespeedy.com/')
if valid==True:
    print("Url is valid")
else:
    print("Invalid url")
