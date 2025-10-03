# import resprctive blueprints and flask REstful resources
# from .blueprint_test import bp
from app.main import api
from .Authentication import Register, LoginOtpGenerate, UserLogin, LoginOtpVerify, OauthLogin, UserLogout
from .Listing import HotelListing


def add_resources(app):
    """
    Method to add resources to app context

    Args:
        app (object): object of Flask representing the app in context
    """
    api.add_resource(Register, '/register')
    api.add_resource(UserLogin, '/login')
    api.add_resource(LoginOtpGenerate, '/login/otp_generate')
    api.add_resource(LoginOtpVerify, '/login/otp_verify')
    api.add_resource(OauthLogin, '/login/oauth')
    api.add_resource(UserLogout, '/logout')
    api.add_resource(HotelListing, '/hotel_listing')


def register_blueprints(app):
    """
    Method to add blueprints to app context

    Args:
        app (object): object of Flask representing the app in context
    """
    # app.register_blueprint(bp)
