from urllib import urlopen
import re
p = re.compile('<h4><a .*?><a .*? href="(.*?)">(.*?)</a>')
text = urlopen('http://python.org/Jobs.html').read()
for url, name in p.findall(text):
    print '%s (%s)' % (name, url)
