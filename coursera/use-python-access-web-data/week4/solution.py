# Note - this code must run in Python 2.x and you must download
# http://www.pythonlearn.com/code/BeautifulSoup.py
# Into the same folder as this program

import urllib
from BeautifulSoup import *

url = raw_input('Enter - ')
html = urllib.urlopen(url).read()

# html = open("actual.html").read()

soup = BeautifulSoup(html)

# Retrieve all of the anchor tags
tags = soup('span')

print "Count {0}".format(len(tags))
print "Sum", sum(int(tag.contents[0]) for tag in tags)