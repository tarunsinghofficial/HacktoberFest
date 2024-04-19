import urllib.request, urllib.parse, urllib.error
import json
import ssl 

url = input('Enter the url:')
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

html = urllib.request.urlopen(url, context=ctx).read()
data = json.loads(html)
comments = data['comments']
count = 0
for comment in comments:
	count += comment['count']
print(count)