import urllib.request, urllib.parse, urllib.error
from twurl import argument
import ssl

print('Calling Twitter...')
url= argument('https://api.twitter.com/1.1/statuses/user_timeline.json', {'screen_name':'aayushjoshi2709', 'count':'2'})
print(url)

# ignore ssl certificates
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

connection = urllib.request.urlopen(url, context= ctx)
data = connection.read()

headers = dict(connection.getheaders())
print(headers)