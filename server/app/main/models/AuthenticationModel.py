from .. import db


# user datbase model for authentication
class UserModel(db.Model):

    __tablename__ = "user"

    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(70), nullable=False)
    username = db.Column(db.String(255), nullable=True)
    email = db.Column(db.String(70), nullable=False)
    mobile = db.Column(db.String(255), nullable=True)
    password = db.Column(db.String(255), nullable=True)
    role = db.Column(db.String(70), nullable=False)


# OTP authentication databse model
class OtpModel(db.Model):

    __tablename__ = "otp"

    id = db.Column(db.Integer, primary_key=True)
    mobile = db.Column(db.String(255), nullable=False)
    otp = db.Column(db.String(255), nullable=False)


# verifacation database model for reset/forgot-password
class VerificationModel(db.Model):

    __tablename__ = "verification"

    id = db.Column(db.Integer, primary_key=True)
    token = db.Column(db.String(255), nullable=False)
    usage = db.Column(db.String(255), nullable=False)


# database model for OAuth user info
class OauthInfoModel(db.Model):

    __tablename__ = "oauth_info"

    id = db.Column(db.Integer, primary_key=True)
    user_id = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False)
    email = db.Column(db.String(70), nullable=False)
    provider = db.Column(db.String(255), nullable=True)
    access_token = db.Column(db.String(255), nullable=False)
    refresh_token = db.Column(db.String(255), nullable=True)


# database model for black listing tokens on logout
class BlacklistTokenModel(db.Model):

    __tablename__ = "backlist_token"

    id = db.Column(db.Integer, primary_key=True)
    token = db.Column(db.String(255), nullable=False)
