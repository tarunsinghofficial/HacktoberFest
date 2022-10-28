def main():
    print("Welcome to email slicer. This program will slice your email address into username, domain and extension respectively.")
    print("-----------------------------------")

    email_input = input("Enter your email address please : ")

    (username, domain) = email_input.split("@")
    (domain, extension) = domain.split(".")

    print('Username : ',username)
    print('Domain : ', domain)
    print('Extension : ', extension)

while True:
    main()
