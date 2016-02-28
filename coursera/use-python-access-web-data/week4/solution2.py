# Note - this code must run in Python 2.x and you must download
# http://www.pythonlearn.com/code/BeautifulSoup.py
# Into the same folder as this program

import urllib
from BeautifulSoup import *

url = raw_input('Enter - ')
cnt = int(raw_input("Enter count:"))
pos = int(raw_input("Enter position:"))
# cnt, pos = 7, 18
# url = "https://pr4e.dr-chuck.com/tsugi/mod/python-data/data/known_by_Keavan.html"

for i in range(cnt):
	print "Retrieving:", url
	html = urllib.urlopen(url).read()
	soup = BeautifulSoup(html)

	# Retrieve all of the anchor tags
	tags = soup('a')
	if pos <= len(tags):
		url = tags[pos-1].get('href', None)
print "Last Url:", url