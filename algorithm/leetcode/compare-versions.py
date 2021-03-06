#!/usr/bin/python
__author__ = "ljshou"

def CompareVersions(string1, string2):
    list1 = string1.strip().split('.')
    list2 = string2.strip().split('.')
    n = min(len(list1), len(list2))
    for i in range(n):
        if int(list1[i]) > int(list2[i]):
            return 1
        elif int(list1[i]) < int(list2[i]):
            return -1
    if len(list1) > len(list2):
        if int(list1[n]) > 0:
            return 1
        else:
            return 0
    elif len(list1) < len(list2):
        if int(list2[n]) > 0:
            return -1 
        else:
            return 0
    else:
        return 0

if __name__ == "__main__":
    print "hello world"
    assert 0 == CompareVersions("0.1", "0.1")
    assert 1 == CompareVersions("1.1", "0.1")
    assert -1 == CompareVersions("1.1", "1.12")
    assert 0 == CompareVersions("1.0", "1")
    assert -1 == CompareVersions("1", "1.1")
