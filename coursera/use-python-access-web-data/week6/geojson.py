#!/usr/bin/env python

import json
import urllib

loc = raw_input("Enter location:")
# loc = "UC Berkeley"
url = "http://python-data.dr-chuck.net/geojson?" + urllib.urlencode({"sensor":"false", "address":loc})

data = urllib.urlopen(url).read()
print "Retrieving", url
print "Retrieved {0} characters".format(len(data))

info = json.loads(data)
print "Place id", info["results"][0]["place_id"]