import requests
from bs4 import BeautifulSoup

search = "weather in e.g - mumbai"
url = f"https://www.google.com/search?&q={search}"

r = requests.get(url)

s = BeautifulSoup(r.txt, "html.parser")

update = s.find("div", class_="Bleawe").text
print(update)
