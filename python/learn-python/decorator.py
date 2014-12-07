#!/usr/bin/python

'''
def sum(x, y):
    print "x+y:", x+y

def wrapper1(x, y):
    print "calling %s" % sum.__name__
    return sum(x, y)

wrapper1(1, 2)

func = sum 
def wrapper2(*args, **kw):
    print "calling %s" % func.__name__
    return func(*args, **kw)


def wrapper3(func, *args, **kw):
    print "calling %s" % func.__name__
    return func(*args, **kw)
wrapper3(sum, 1, 2)
'''


def log(func):
    def wrapper(*args, **kw):
        print "calling %s" % func.__name__
        return func(*args, **kw)
    return wrapper

def log2(func):
    def wrapper(*args, **kw):
        print "begin call"
        res = func(*args, **kw)
        print "end call"
        return res
    return wrapper


@log2
@log
def sum(x, y):
    print "x+y:", x+y

sum(1, 2)
