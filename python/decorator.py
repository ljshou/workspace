def add_log(func):
    def wrapper(*arg, **karg):
        print 'add log'
        func(*arg, **karg)
    return wrapper


@add_log
def func():
    print 'func called'

if __name__ == "__main__":
    func()
