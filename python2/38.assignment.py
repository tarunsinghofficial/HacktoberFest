import urllib.request, urllib.parse, urllib.error
import json
import ssl

url = 'http://py4e-data.dr-chuck.net/json?'

ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

address = input('Enter location:')
params = dict()
params['address'] = address
params['key'] = 42
url += urllib.parse.urlencode(params)
html = urllib.request.urlopen(url, context=ctx).read().decode()
data = json.loads(html)
print("Place id",data['results'][0]['place_id'])
