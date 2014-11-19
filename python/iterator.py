class Fibs:
    def __init__(self):
        self.a = 0
        self.b = 1
    def next(self):
        self.a, self.b = self.b, self.a+self.b
        return self.a
    def __iter__(self):
        return self

fibs = Fibs()
for i in range(10):
    print fibs.next()
    
print iter(fibs)
for f in fibs:
    print type(f)
    if f > 1000: 
        print f
        break
