#!/usr/bin/env python

import json  
 
print "DEBUG"
s = '[{"name":"niaochao","point":{"lat":"39.990","lng":"116.397"},"desc":"aoyunhuizhuchangdi"},{"name":"beidapingpangqiuguan","point":{"lat":"39.988","lng":"116.315"},"desc":"pingpangqiubisaichangdi"},{"name":"beijinggongrentiyuchang","point":{"lat":"39.930","lng":"116.446"},"desc":"zuqiubisaichangdi"}]'  
locations = json.loads(s)