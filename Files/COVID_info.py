import requests 
from bs4 import BeautifulSoup
from plyer import notification
import time


def notifyMe(title, message):
    notification.notify(
        title = title,
        message = message,
        timeout = 5
    )


result = requests.get('https://www.worldometers.info/coronavirus/').text
soup = BeautifulSoup(result, 'html.parser')
soup.encode('utf-8')
cases = soup.find("div", {"class":"maincounter-number"}).get_text().strip()
    

while True:
	print(cases)
	time.sleep(10)
    #notifyMe('Total number', cases)
    
