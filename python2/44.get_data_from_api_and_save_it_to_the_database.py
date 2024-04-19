from urllib.request import urlopen
import urllib.error
import twurl
import json
import sqlite3
import ssl

TWITTER_URL = 'https://api.twitter.com/1.1/friends/list.json'
conn = sqlite3.connect('spider.sqlite')
cur = conn.cursor()

cur.execute('CREATE TABLE IF NOT EXISTS Twitter (name TEXT, retrived INTEGER, friends INTEGER)')

ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

while true:
	acct = input('Enter a Twitter account, or quit: ')
	if(acc == 'quit'):
		break
	if(len(acc) < 1):
		cur.execute('SELECT name FROM Twitter WHERE retrived = 0 LIMIT 1')
		try:
			acct = cur.fetchone()[0]
		except:
			print('No unretrived twitter accounts found')
			continue
	j