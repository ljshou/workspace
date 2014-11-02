#!/usr/bin/python
import socket
import sys
from thread import *

HOST = '' #symbolic name meaning all available interfaces
PORT = 8888 # Arbitrary non-privileged port

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print 'Socket created'

try:
  s.bind((HOST, PORT))
except socket.error, msg:
  print 'Bind faild. Error code : ' + str(msg[0])\
  + ' Message ' + msg[1]
  sys.exit()

print 'Socket bind complete'

s.listen(10)
print 'Socket now listenning'

#Function for handling connections. This will be used to create threads
def clientthread(conn):
  #Sending message to connected client
  conn.send('Welcome to the server. Type sth and hit enter\n')
#send only takes string
  #infinite loop so that function do not terminate and thread do not end.
  while True:
    #Receiving from client
	data = conn.recv(1024)
	reply = 'Ok...' + data
	if not data:
	  break
	conn.sendall(reply)

  #out of loop
  conn.close()

#now keep taling with the client
while 1:
  #wait to accept a connection - blocking call
  conn, addr = s.accept()
  print 'Connected with ' + addr[0] + ':' + str(addr[1])
  
  #start new thread takes 1st argument as a function
  start_new_thread(clientthread, (conn,))

s.close()
