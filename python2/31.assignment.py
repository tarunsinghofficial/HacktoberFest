import urllib.request, urllib.error, urllib.parse
from bs4 import BeautifulSoup
import ssl

ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = " http://py4e-data.dr-chuck.net/known_by_Xanthia.html"

for i in range(6):
	html = urllib.request.urlopen(url, context = ctx)
	soup = BeautifulSoup(html, 'html.parser')
	tags = soup('a')
	tag = tags[17]
	url = tag.get('href', None)

html = urllib.request.urlopen(url, context = ctx)
soup = BeautifulSoup(html, 'html.parser')
tags = soup('a')
tag = tags[17]
print(tag.contents[0])