# anchor extraction from html document
from bs4 import BeautifulSoup
import urllib2

webpage = urllib2.urlopen('https://en.wikipedia.org/wiki/Beautiful_Soup')
soup = BeautifulSoup(webpage)
for anchor in soup.find_all('a'):
    print(anchor.get('href', '/'))