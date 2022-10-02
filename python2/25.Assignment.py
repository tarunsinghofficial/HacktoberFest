# http://data.pr4e.org/intro-short.txt
import socket

# intilise the socket
mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# create the socket connection on port 80
mysock.connect(('data.pr4e.org', 80))
# craft a get request
cmd = 'GET http://data.pr4e.org/intro-short.txt HTTP/1.0\r\n\r\n'.encode()
# send the http request
mysock.send(cmd)

while True:
	# recieve data 512 characters at a time
	data = mysock.recv(512)
	# check for no more characters
	if len(data) < 1:
		break
	print(data.decode())
mysock.close()