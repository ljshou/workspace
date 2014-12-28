import os

print "curent process's id %s" % os.getpid()

pid = os.fork()

if pid == 0:
    print "I'm child process, and my id is %s, my parent id is %s" % (os.getpid(), os.getppid())
else:
    print "I forked a child process %s" % pid

