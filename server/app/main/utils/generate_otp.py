from twilio.rest import Client
import math
import random


def generate_random():
    digits = "0123456789"
    OTP = ""
    for i in range(4):
        OTP += digits[int(math.floor(random.random() * 10))]

    return OTP


def generate_otp(number):
    account_sid = ''
    auth_token = ''

    client = Client(account_sid, auth_token)
    otp = generate_random()

    message = client.messages.create(
        from_='+12029723786',
        body="EYO login OTP: "+otp,
        to='+91'+number
    )

    return True, otp
