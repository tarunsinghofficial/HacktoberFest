import sqlite3
import xml.etree.ElementTree as ET

conn = sqlite3.connect("assignment47.sqlite")
cur = conn.cursor()

cur.executescript('''
DROP TABLE IF EXISTS Artist;
DROP TABLE IF EXISTS Genre;
DROP TABLE IF EXISTS Album;
DROP TABLE IF EXISTS Track;

CREATE TABLE Artist (
	id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	name TEXT UNIQUE
);

CREATE TABLE Genre (
    id  INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
    name TEXT UNIQUE
);

CREATE TABLE Album (
    id  INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
    artist_id  INTEGER,
    title   TEXT UNIQUE
);

CREATE TABLE Track (
    id  INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
    title TEXT  UNIQUE,
    album_id  INTEGER,
    genre_id  INTEGER,
    len INTEGER, rating INTEGER, count INTEGER
);
''')

fname = input('Enter file name: ')
if(len(fname) < 1):
	fname = 'Library.xml'

def lookup(d, key):
	found = False
	for child in d:
		if found:
			return child.text
		if child.tag == 'key' and child.text == key:
			found = True
	return None

stuff = ET.parse(fname)
all = stuff.findall('dict/dict/dict')
print('Dict count:', len(all))

for entry in all:
	if(lookup(entry, 'Track ID') is None):
		continue
	name = lookup(entry, 'Name')
	artist = lookup(entry, 'Artist')
	album = lookup(entry, 'Album')
	count = lookup(entry, 'Play Count')
	rating = lookup(entry, 'Rating')
	length = lookup(entry, 'Total Time')
	genre = lookup(entry, 'Genre')

	if name is None or artist is None or album is None or genre is None:
		continue
	print(name, artist, album, genre, count, rating, length)
	cur.execute('INSERT OR IGNORE INTO Artist (name) VALUES (?)', (artist,))
	cur.execute('SELECT id FROM Artist WHERE name = ?', (artist, ))
	artist_id = cur.fetchone()[0]

	cur.execute('INSERT OR IGNORE INTO Genre (name) VALUES (?)', (genre,))
	cur.execute('SELECT id FROM Genre WHERE name = ?', (genre, ))
	genre_id = cur.fetchone()[0]

	cur.execute('INSERT OR IGNORE INTO Album (title, artist_id) VALUES (?, ?)', (album, artist_id))
	cur.execute('SELECT ID FROM Album WHERE title = ?', (album, ))
	album_id = cur.fetchone()[0]
	
	cur.execute('INSERT OR REPLACE INTO Track(title, album_id, genre_id, len, rating, count) VALUES(?, ?, ?, ?, ?, ?)', (name, album_id,genre_id, length, rating, count))
	conn.commit()

sqlstr = 'SELECT Track.title, Artist.name, Album.title, Genre.name FROM Track JOIN Genre JOIN Album JOIN Artist ON Track.genre_id = Genre.ID and Track.album_id = Album.id AND Album.artist_id = Artist.id ORDER BY Artist.name LIMIT 3'
print()
for row in cur.execute(sqlstr) :
    print(str(row[0]),str(row[1]),str(row[2]),str(row[3]))

cur.close()