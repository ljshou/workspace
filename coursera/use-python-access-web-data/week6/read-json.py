#!/usr/bin/env python

import json
import urllib

# url = raw_input("Enter location:")
url = "http://python-data.dr-chuck.net/comments_205686.json"
print "Retrieving", url
text = urllib.urlopen(url).read()
print "Retrieved {0} characters".format(len(text))

info = json.loads(text)
cnts = [comment["count"] for comment in info["comments"]]

print "Count:", len(cnts)
print "Sum:", sum(cnts)