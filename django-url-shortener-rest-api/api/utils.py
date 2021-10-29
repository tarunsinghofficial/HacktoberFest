"""Utilities for Shortener"""
from django.conf import settings
from random import choice
from string import ascii_letters, digits

# Try to get the value from the settings module
SIZE = getattr(settings, "MAXIMUM_URL_CHARS", 7)

AVAIABLE_CHARS = ascii_letters + digits


def create_random_code(chars=AVAIABLE_CHARS):
    """Creates a random string with the predetermined size"""
    return "".join([choice(chars) for _ in range(SIZE)])


def create_shortened_url(model_instance):
    """Create a UNIQUE shortened URL."""
    random_code = create_random_code()
    # Gets the model class
    model_class = model_instance.__class__

    if model_class.objects.filter(short_url=random_code).exists():
        # Run the function again
        return create_shortened_url(model_instance)

    return random_code
