import urllib.request, urllib.parse, urllib.error
import http
import sqlite3
import json
import time
import ssl
import sys

serviceurl = "http://py4e-data.dr-chuck.net/geojson?"

conn = sqlite3.connect('geodata.sqlite')
cur = conn.cursor()
cursor.execute('CREATE TABLE IF NOT EXISTS Locations(address TEXT, geodata TEXT)')


ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

fh = open('where.data')
count = 0
for line in fh:
	if count > 200:
		print('Retrived 200 locations, restart to retrive more')
		break
	address = line.strip()
	print("")
	cur.execute('SELECT geodata FROM Locations WHERE address = ?', (memoryview(address.encode()),))
	try:
		data = cur.fetchone()[0]
		print('Found in database', address)
		continue
	except:
		pass
	parms = dict()
	parms['query'] = address
	parms['key'] = api_key
	url = serviceurl + urllib.parse.urlencode(params)

	print('Retriving', url)
	uh = urllib.request.urlopen(url, context=ctx)
	data = uh.read().decode()
	print('Retrived', len(data), 'characters', data[:20].replace('\n', ' '))
	count += 1

	try:
		js = json.loads(data)
	except:
		print(data)
		continue

	if 'status' not in js or (js['status'] != 'OK' and js['status'] != 'ZERO_RESULTS'):
		print('========Failure to retrive==========')
		print(data)
		break

	cur.execute('INSERT INTO Locations (address, geodata) VALUES (?, ?)', (memoryview(address.encode()), memoryview(data.encode())))
	conn.commit()
	if count % 10 == 0:
		print('Pausing for a bit')
		time.sleep(5)

print('Run geodump.py to read the data from the database so you can vizualize it')













	