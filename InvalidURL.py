import validators
valid=validators.url('gist.github.com/dperini/729294')
print(valid)
if valid==True:
    print("Url is valid")
else:
    print("Invalid url")
