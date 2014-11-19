class A(object):
    def __init__(self):
        self.flag = True
    def hello(self):
        print 'hello A'

class B(A):
    def __init__(self):
        super(B, self).__init__()
        pass
    def hello(self):
        print 'hello B'

if __name__ == "__main__":
    a = A()
    a.hello()
    print a.flag
    b = B()
    b.hello()
    print b.flag
