from django.urls import path
from . import views

urlpatterns = [
    path(route='', view=views.home, name='HOME'),
    path(route=r'urls/', view=views.shortenedURL_list, name='URL List'),
    path(route='v/<str:short_url>',
         view=views.shortenedURL_detail,
         name='URL Detail'),
    path(route='<str:short_url>',
         view=views.redirect_view,
         name='URL Redirect')
]
