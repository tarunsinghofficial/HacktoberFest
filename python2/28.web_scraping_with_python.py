from bs4 import BeautifulSoup
import urllib.request, urllib.parse, urllib.error
url = input('Enter url')
html = urllib.request.urlopen(url).read()
soup = beautifulSoup(html, 'html.parser')

# retrive all the anchor tags form the file
tags = soup('a')
for tag in tags:
	print(tag.get('http', None))