from __future__ import generators
import sys, re
from util import *

print '<html><head><title>...</title><body>'

title = 1
for block in blocks(sys.stdin):
    block = re.sub(r'\*(.+?)\*', r'<em>\1</em>', block)
    if title:
        print '<h1>'
        print block
        print '</h1>'
        title = 0
    else:
        print '<p>'
        print block
        print '</p>'

print '</body></html>'
