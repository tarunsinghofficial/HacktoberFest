from django.http.response import Http404, HttpResponseRedirect
from django.http import HttpResponse, JsonResponse
from django.views.decorators.csrf import csrf_exempt
from rest_framework.parsers import JSONParser
from .models import ShortenedURL
from .serializers import ShortenedURLSerializer


def home(request):
    """Get Status of the API"""
    response_status = {'text': "API is up"}
    return JsonResponse(response_status, status=200)




@csrf_exempt
def shortenedURL_list(request):
    """List all shortenedURLs, or create a new shortenedURL."""
    if request.method == 'GET':
        shortenedURLs = ShortenedURL.objects.all()
        serializer = ShortenedURLSerializer(shortenedURLs, many=True)
        return JsonResponse(serializer.data, safe=False)

    if request.method == 'POST':
        data = JSONParser().parse(request)
        serializer = ShortenedURLSerializer(data=data)
        if serializer.is_valid():
            serializer.save()
            return JsonResponse(serializer.data, status=201)
        return JsonResponse(serializer.errors, status=400)
    return HttpResponse(status=400)


@csrf_exempt
def shortenedURL_detail(request, short_url):
    """Retrieve, update or delete a code shortenedURL."""
    try:
        shortenedURL = ShortenedURL.objects.get(short_url=short_url)
        if request.method == 'GET':
            serializer = ShortenedURLSerializer(shortenedURL)
            return JsonResponse(serializer.data)

        if request.method == 'PUT':
            data = JSONParser().parse(request)
            serializer = ShortenedURLSerializer(shortenedURL, data=data)
            if serializer.is_valid():
                serializer.save()
                return JsonResponse(serializer.data)
            return JsonResponse(serializer.errors, status=400)

        if request.method == 'DELETE':
            shortenedURL.delete()
            return HttpResponse(status=204)
    except ShortenedURL.DoesNotExist:
        return HttpResponse(status=404)


def redirect_view(request, short_url):
    """Redirect the short URL to link URL"""
    try:
        if request.method == 'GET':
            shortener = ShortenedURL.objects.get(short_url=short_url)
            shortener.times_visited += 1
            shortener.save()
            return HttpResponseRedirect(shortener.long_url)
    except ShortenedURL.DoesNotExist:
        return HttpResponse(status=404)
