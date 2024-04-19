from django.apps import AppConfig


class ApiConfig(AppConfig):
    """Declare default_auto_field and App name."""

    default_auto_field = 'django.db.models.BigAutoField'
    name = 'api'
