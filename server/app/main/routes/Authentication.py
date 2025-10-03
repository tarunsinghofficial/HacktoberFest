from flask import request
from flask_restful import Resource, reqparse
from app.main import db
from ..services.authentication import user_register, user_login, otp_generate, otp_verify, oauth_login, user_logout
import jwt
import datetime
from ..utils.token_validate import token_validate


# POST route to register
class Register(Resource):
    parser = reqparse.RequestParser()
    parser.add_argument("name", type=str, required=True)
    parser.add_argument("email", type=str, required=True)
    parser.add_argument("username", type=str, required=False)
    parser.add_argument("password", type=str, required=False)
    parser.add_argument("mobile", type=str, required=False)

    @classmethod
    def post(self):
        payload = Register.parser.parse_args()
        flag_request = user_register(payload)

        if flag_request:
            return {'status': True, 'msg': "Registration Successfull"}
        else:
            return {'status': False, 'msg': "User exists or incorrect details"}


# Route for User login
class UserLogin(Resource):
    parser = reqparse.RequestParser()
    parser.add_argument('password', type=str, required=True)
    parser.add_argument('email', type=str, required=False)
    parser.add_argument('username', type=str, required=False)
    parser.add_argument('mobile', type=str, required=False)

    @classmethod
    def post(self):
        data = UserLogin.parser.parse_args()

        flag_request, token, user_data = user_login(data)

        if flag_request:
            return {'status': flag_request, 'token': token, 'msg': 'Login Successful', 'user_data': user_data}
        else:
            return {'status': flag_request, 'msg': 'Incorrrect Credentials'}


# POST route to generate and send OTP to registered mobile number
class LoginOtpGenerate(Resource):
    parser = reqparse.RequestParser()
    parser.add_argument("mobile", type=str, required=True)

    @classmethod
    def post(self):
        data = LoginOtpGenerate.parser.parse_args()

        flag_request = otp_generate(data)

        if flag_request:
            return {'status': flag_request, 'msg': 'OTP generated'}
        else:
            return {'status': flag_request, 'msg': 'mobile number not registered'}


# POST route to verify OTP for login
class LoginOtpVerify(Resource):
    parser = reqparse.RequestParser()
    parser.add_argument("mobile", type=str, required=True)
    parser.add_argument("otp", type=str, required=True)

    @classmethod
    def post(self):
        data = LoginOtpVerify.parser.parse_args()

        flag_request, token, user_data = otp_verify(data)

        if flag_request:
            return {'status': flag_request, 'token': token, 'msg': 'Login Successful', 'user_data': user_data}
        else:
            return {'status': flag_request, 'msg': 'Incorrrect OTP'}


# POST route for OAuth login
class OauthLogin(Resource):
    parser = reqparse.RequestParser()
    parser.add_argument("name", type=str, required=True)
    parser.add_argument("email", type=str, required=True)
    parser.add_argument("provider", type=str, required=False)
    parser.add_argument("access_token", type=str, required=False)

    @classmethod
    def post(self):
        data = OauthLogin.parser.parse_args()

        flag_request, token, user_data = oauth_login(data)

        if flag_request:
            return {'status': flag_request, 'token': token, 'msg': 'Login Successful', 'user_data': user_data}
        else:
            return {'status': flag_request, 'msg': 'Incorrrect Credentials'}


# GET route for logout
class UserLogout(Resource):

    @classmethod
    def get(self):
        auth_token = request.headers.get('auth_token')

        flag = user_logout(auth_token)

        if flag:
            return {'status': True, 'msg': 'Logout Successful'}
        else:
            return {'status': False, "msg": 'Logout Unsucessful'}
