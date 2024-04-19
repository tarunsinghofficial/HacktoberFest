import urllib.request, urllib.error, urllib.parse
from bs4 import BeautifulSoup
import ssl

ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE


url = "http://py4e-data.dr-chuck.net/comments_1106064.html"
html = urllib.request.urlopen(url, context = ctx)
soup = BeautifulSoup(html, 'html.parser')

tags = soup('span')

sum = 0
for tag in tags:
	sum += int(tag.contents[0])
print(sum)