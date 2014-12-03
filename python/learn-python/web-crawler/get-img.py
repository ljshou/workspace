#!/usr/bin/python
#!coding=utf8

import os, re, urllib

def getHTML(url):
    page = urllib.urlopen(url)
    html = page.read()
    print "page sucessfully loaded"
    with open("page.html", "w") as f:
        f.write(html)
    return html

def getImg(html):
    img_re = r'src="(.+\.png)"'
    img_src = re.findall(img_re, html)
    x = 1
    for img in img_src:
        urllib.urlretrieve(img, "%s.png" % x)
        x += 1

if __name__ == '__main__':
    url = "http://ljshou.gitcafe.com/2014/10/30/STL%E6%BA%90%E7%A0%81%E5%88%86%E6%9E%90-list%E7%9A%84sort%E5%87%BD%E6%95%B0/"
    getImg(getHTML(url))
