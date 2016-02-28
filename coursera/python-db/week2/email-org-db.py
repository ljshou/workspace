import sqlite3
import re

conn = sqlite3.connect('orgdb.sqlite')
cur = conn.cursor()

cur.execute('''
DROP TABLE IF EXISTS Counts''')

cur.execute('''
CREATE TABLE Counts (org TEXT, count INTEGER)''')

# fname = raw_input('Enter file name: ')
# if ( len(fname) < 1 ) : fname = 'mbox.txt'
fname = 'mbox.txt'

fh = open(fname)
for line in fh:
    # if not line.startswith('From: ') : continue
    orgs = re.findall(r'^From: [a-zA-Z0-9.]+@([a-zA-Z0-9.]+)', line)
    for org in orgs:
        cur.execute('SELECT count FROM Counts WHERE org = ? ', (org, ))
        row = cur.fetchone()
        if row is None:
            cur.execute('''INSERT INTO Counts (org, count) 
                    VALUES ( ?, 1 )''', ( org, ) )
        else : 
            cur.execute('UPDATE Counts SET count=count+1 WHERE org = ?', 
                (org, ))
    conn.commit()

# https://www.sqlite.org/lang_select.html
sqlstr = 'SELECT org, count FROM Counts ORDER BY count DESC LIMIT 10'

for row in cur.execute(sqlstr):
    print str(row[0]), row[1]

cur.close()

