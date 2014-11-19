from xmlrpclib import ServerProxy
server = ServerProxy('http://coversproject.com/RPC.php')
covers = server.covers.Covered('Monty Python')
for cover in covers:
    if cover['song'] == 'Brave Sir Robin':
        print cover['artist']
