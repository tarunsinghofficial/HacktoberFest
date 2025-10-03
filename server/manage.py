import os
import unittest

from flask_migrate import Migrate, MigrateCommand
from flask_script import Manager
from app.main import create_app, db
from app.main.routes import add_resources, register_blueprints
from app.main import api, api_blueprint


app = create_app(os.getenv('FLASK_ENV') or 'dev')
app.app_context().push()
manager = Manager(app)
migrate = Migrate(app, db)
manager.add_command('db', MigrateCommand)


@manager.command
def run():
    """
    This method runs the flask app using manager command 
    after adding the routes using the methods in routes folder
    """
    add_resources(app)
    app.register_blueprint(api_blueprint)
    register_blueprints(app)
    app.run()


@manager.command
def test():
    """
    This method allows the flask app to be tested with the unit test cases specified in the test folder
    """
    tests = unittest.TestLoader().discover('app/test', pattern='test*.py')
    result = unittest.TextTestRunner(verbosity=2).run(tests)
    if result.wasSuccessful():
        return 0
    return 1


if __name__ == "__main__":
    manager.run()
