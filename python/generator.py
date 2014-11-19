#def flatten(nested):
#    for sublist in nested:
#        for elem in sublist:
#            yield elem

# recursive
def flatten(nested):
    try:
        # do not iterate strings
        try: nested + ''
        except TypeError: pass
        else: raise TypeError
        for sublist in nested:
            for elem in flatten(sublist):
                yield elem
    except TypeError:
        yield nested


if __name__ == "__main__":
    a = [['abc',[2]], [3,4], [5]]
    for x in flatten(a):
        print x
