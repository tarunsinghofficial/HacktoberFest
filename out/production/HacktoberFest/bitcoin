import requests
from datetime import datetime
import sys

def get_current_btn_value():
	res = requests.get('https://blockchain.info/ticker')
	inr_value = res.json()['INR']

	symbol = inr_value['symbol']
	current_inr_value = inr_value['last']

	now = datetime.now()
	current_time = now.strftime("%d/%m/%Y %H:%M:%S")

	print(f'Price of Bitcoin in INR: {symbol} {current_inr_value}\nTime of price: {current_time}\n')	

try:
	while True:
		get_current_btn_value()

except KeyboardInterrupt:
	sys.exit()			
