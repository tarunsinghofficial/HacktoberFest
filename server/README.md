# Backend Guide

After cloning follow the steps to setup

1. Create virtual environment with Pyenv/virtualenv for python
2. pip install -r requirements.txt

### To start the server

`python manage.py run`

### To migrate the databsae

1. python manage.py db init
2. python manage.py db migrate
3. python manage.py db upgrade

### To add the models

1. Create {model}.py files in the models folder
2. import the same file in the models/init.py
3. run the db migrate and upgrade command again

### To create the routes

1. Create the {route}.py file in the route folder
2. import the file into routes/init.py
3. if the routes are blueprint then register the blueprint under 'register_blueprints' function in the init.py files
4. If the routes are flask RESTful, api.add_resource({RESTful_name}, '{route}')

### To create the services

Add any interaction with data and models into the services folder

### To create the utils functionality

Add the utility functions in the 'utils' folder.

### To change the DB settings

1. Open the settings.py in the root folder
2. Change the database URI in SQLALCHEMY_DATABASE_URI based on the development env
