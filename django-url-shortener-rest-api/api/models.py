from django.db import models
from api.utils import create_shortened_url


class ShortenedURL(models.Model):
    """
    A class representing shortened URL.
        created: The time of creation of object.
        long_url: The long URL of the object.
        short_url: The Short URL of the object.
        times_visited: The number of times short_url is visited.
    """

    created = models.DateTimeField(auto_now_add=True)
    long_url = models.URLField()
    short_url = models.CharField(max_length=15, unique=True, blank=True)
    times_visited = models.PositiveIntegerField(default=0)

    class Meta:
        """Define ordering"""

        ordering = ['created']

    def save(self,
             force_insert=False,
             force_update=False,
             using=None,
             update_fields=None):
        """Override default `save` method to shorten URL if not provided explictly"""
        # If the short url wasn't specified
        if not self.short_url:
            # We pass the model instance that is being saved
            self.short_url = create_shortened_url(self)

        super().save(force_insert, force_update, using, update_fields)
