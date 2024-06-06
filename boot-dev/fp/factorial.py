import functools

def imperative_factorial(n):
    # a procedure that continuously multiplies
    # the current result by the next number
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result

def factorial(n):
    return functools.reduce(lambda x, y: x * y, range(1, n + 1))
