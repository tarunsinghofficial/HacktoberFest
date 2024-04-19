from rest_framework import fields, serializers
from api.models import ShortenedURL


class ShortenedURLSerializer(serializers.ModelSerializer):
    """ShortenedURL Serializer Class"""


    class Meta:
        """Declare fields and Model"""

        model = ShortenedURL
        fields = ['created', 'long_url', 'short_url', 'times_visited']
