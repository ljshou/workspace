def fibs(num):
    result = [0, 1]
    for i in range(num-2):
        result.append(result[-2] + result[-1])
    return result
num = input('How many Fibonacci numbers do you want? ')
print fibs(num)
