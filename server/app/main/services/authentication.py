from ..models.AuthenticationModel import UserModel, OtpModel, OauthInfoModel
from app.main import db
from app.main.settings import key
import jwt
import datetime
from ..models.AuthenticationModel import BlacklistTokenModel
from ..utils.db_save import db_save
from ..utils.generate_otp import generate_otp
import json


# register user if email is not present in the users table
def user_register(data):

    data_raw = UserModel().query.filter(UserModel.email == data.get("email")).first()

    if data_raw:
        return False
    else:
        try:
            new_user = UserModel(name=data.get('name', "name"),
                                 username=data.get('username', "username"),
                                 email=data.get('email', "email"),
                                 mobile=data.get('mobile', "mobile"),
                                 password=data.get('password', "password"),
                                 role=data.get('role', 'user')
                                 )

            db_save(new_user)

            return True

        except Exception as e:
            return False


# Function for login of user
def user_login(data):
    if data.get("username"):
        data_raw = UserModel().query.filter(
            UserModel.username == data.get("username")).first()
    elif data.get("mobile"):
        data_raw = UserModel().query.filter(
            UserModel.mobile == data.get("mobile")).first()
    else:
        data_raw = UserModel().query.filter(
            UserModel.email == data.get("email")).first()

    print(data_raw)

    # check if data_raw is not NoneType
    if data_raw:

        if data["password"] == data_raw.password:
            flag = True

        # As flag is true,generating token
        if flag:
            if data.get("email"):
                payload = {
                    "email": data["email"],
                    "created_at": str(datetime.datetime.utcnow()),
                    "exp_datetime": str(datetime.datetime.utcnow() + datetime.timedelta(days=1))
                }
            elif data.get("username"):
                payload = {
                    "username": data["username"],
                    "created_at": str(datetime.datetime.utcnow()),
                    "exp_datetime": str(datetime.datetime.utcnow() + datetime.timedelta(days=1))
                }
            elif data.get("mobile"):
                payload = {
                    "mobile": data["mobile"],
                    "created_at": str(datetime.datetime.utcnow()),
                    "exp_datetime": str(datetime.datetime.utcnow() + datetime.timedelta(days=1))
                }

            token = jwt.encode(payload, key)
            return flag, token.decode(), {"email": str(data_raw.email), "name": str(data_raw.name)}

        else:
            return flag, "", ""
    else:
        return flag, "", ""

# generate otp to regisetred mobile


def otp_generate(data):
    data_raw = UserModel.query.filter(
        UserModel.mobile == data['mobile']).first()

    print(data_raw)
    if data_raw:
        print("enter")
        flag, otp = generate_otp(data['mobile'])
        if flag:
            otp_data = OtpModel.query.filter(
                OtpModel.mobile == data['mobile']).first()

            if otp_data:
                db.session.query(OtpModel).filter(OtpModel.mobile == data.get('mobile')).update(
                    {OtpModel.otp: otp})
                db.session.commit()
            else:
                new_entry = OtpModel(mobile=data['mobile'], otp=otp)
                db_save(new_entry)

            return True

    else:
        return False

# verify input otp with saved otp in db


def otp_verify(data):
    data_raw = OtpModel.query.filter(
        OtpModel.mobile == data['mobile']).first()
    data_user = UserModel.query.filter(
        UserModel.mobile == data['mobile']).first()

    if data_raw:
        flag = False
        if data["otp"] == data_raw.otp:
            flag = True

        # As flag is true,generating token
        if flag:
            payload = {
                "mobile": data["mobile"],
                "created_at": str(datetime.datetime.utcnow()),
                "exp_datetime": str(datetime.datetime.utcnow() + datetime.timedelta(days=1))
            }
            token = jwt.encode(payload, key)

            return flag, token.decode(), {"email": str(data_user.email), "name": str(data_user.name)}

        else:
            return flag, "", ""
    else:
        return flag, "", ""

# check user table if present post OAuth data to db ,if not register the user and post OAuth data to db


def oauth_login(data):
    data_raw = UserModel().query.filter(UserModel.email == data.get("email")).first()

    # if user present in the users table,save OAuth to db and send Jwt token
    if data_raw:
        flag = False
        data_oauth = OauthInfoModel().query.filter(
            OauthInfoModel.email == data.get("email")).first()

        if data_oauth:
            flag = True
        else:
            new_oauth_entry = OauthInfoModel(
                user_id=data_raw.id,
                provider=data['provider'],
                access_token=data['access_token']
            )

            db_save(new_oauth_entry)
            flag = True

        if flag:
            payload = {
                "mobile": data["email"],
                "created_at": str(datetime.datetime.utcnow()),
                "exp_datetime": str(datetime.datetime.utcnow() + datetime.timedelta(days=1))
            }
            token = jwt.encode(payload, key)

            return flag, token.decode(), {"email": str(data_raw.email), "name": str(data_raw.name)}

        else:
            return flag, "", ""
    else:
        # if user not present in users table ,register new user and send jwt token  for login
        flag_regsiter = user_register(data)

        if flag_regsiter:
            data_registered = UserModel().query.filter(
                UserModel.email == data.get("email")).first()

            new_oauth_entry = OauthInfoModel(
                user_id=data_registered.id,
                provider=data['provider'],
                access_token=data['access_token']
            )

            db_save(new_oauth_entry)

            payload = {
                "mobile": data["email"],
                "created_at": str(datetime.datetime.utcnow()),
                "exp_datetime": str(datetime.datetime.utcnow() + datetime.timedelta(days=1))
            }
            token = jwt.encode(payload, key)

            return True, token.decode(), {"email": str(data_registered.email), "name": str(data_registered.name)}
        else:
            return False, "", ""


# logout user and add jwt token to blacklistmodel
def user_logout(token):
    query = BlacklistTokenModel.query.filter(
        BlacklistTokenModel.token == token).first()

    if query == None:
        new_entity = BlacklistTokenModel(token=token)
        db_save(new_entity)

    return True
