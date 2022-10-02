import urllib.request, urllib.error, urllib.parse
import xml.etree.ElementTree as ET
import ssl

ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input()
html = urllib.request.urlopen(url, context = ctx).read()

tree = ET.fromstring(html)
count = 0
comments = tree.find('comments')
for comment in comments:
	count += int(comment.find('count').text)
print(count)