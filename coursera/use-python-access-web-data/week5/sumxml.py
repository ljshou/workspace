#!/usr/bin/env python

import urllib
import xml.etree.ElementTree as ET

url = raw_input("Enter location:")
# url = "http://python-data.dr-chuck.net/comments_205682.xml"
print "Retrieving", url
data = urllib.urlopen(url).read()
print "Retrieved {0} characters".format(len(data))
tree = ET.fromstring(data)

comments = tree.find("comments").findall("comment")
digits = [int(comment.find("count").text) for comment in comments]
print "Count:", len(digits)
print "Sum:", sum(digits)
