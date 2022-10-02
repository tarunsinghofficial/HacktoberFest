import socket
# initiliase a socket object
mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# create a socket connection on port 80
mysock.connect(('data.pr4e.org', 80))
# make a get request
# encode() converts data form unicode to utf-8
cmd = 'GET http://data.pr4e.org/romeo.txt HTTP/1.0\r\n\r\n'.encode()
# send the get request through the socket
mysock.send(cmd)

while True:
	# recive 512 characters at a time
	data = mysock.recv(512)
	# check for no nore data
	if(len(data) < 1):
		break
	# decode() converts data from utf-8 to unicode
	print(data.decode())
mysock.close()