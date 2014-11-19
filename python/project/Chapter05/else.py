broke_out = 0
for x in seq:
    do_something(x)
    if condition(x):
        broke_out = 1
        break
    do_something_else(x)
if not broke_out:
    print "I didn't break out!"
