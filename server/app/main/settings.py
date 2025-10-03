import os
#from environs import Env, EnvError

# uncomment the line below for postgres database url from environment variable
# postgres_local_base = os.environ['DATABASE_URL']

#env = Env()
# env.read_env()

basedir = os.path.abspath(os.path.dirname(__file__))


class Config:
    SECRET_KEY = os.getenv('SECRET_KEY', 'my_fullStack_project_eyo_rooms')
    DEBUG = False


class DevelopmentConfig(Config):
    # uncomment the line below to use postgres
    # SQLALCHEMY_DATABASE_URI = postgres_local_base
    # uncomment the line below to use mysql
    # SQLALCHEMY_DATABASE_URI = 'mysql+pymysql://<user>:<password>@<host>:<port>/<database_name>'

    DEBUG = True
    SQLALCHEMY_DATABASE_URI = 'mysql://root:satish@localhost/eyo_rooms'
    SQLALCHEMY_TRACK_MODIFICATIONS = False
    ENV = 'development'


class TestingConfig(Config):
    DEBUG = True
    TESTING = True
    SQLALCHEMY_DATABASE_URI = 'mysql://root:satish@localhost/eyo_rooms'
    PRESERVE_CONTEXT_ON_EXCEPTION = False
    SQLALCHEMY_TRACK_MODIFICATIONS = False


class ProductionConfig(Config):
    DEBUG = False

    # uncomment the line below to use postgres
    # SQLALCHEMY_DATABASE_URI = postgres_local_base


config_by_name = dict(
    dev=DevelopmentConfig,
    test=TestingConfig,
    prod=ProductionConfig
)

key = Config.SECRET_KEY
