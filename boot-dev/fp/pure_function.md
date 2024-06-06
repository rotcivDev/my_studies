Pure Function Review

Pure functions have a lot of benefits. Whenever possible, good developers try to use pure functions instead of impure functions. Remember, pure functions:

    Return the same result if given the same arguments. They are deterministic.
    Do not change the external state of the program. For example, they do not change any variables outside of their scope.
    Do not perform any I/O operations (like reading from disk, accessing the internet, or writing from the console)
    Do not call any functions that do any of the above

These properties result in pure functions being easier to test, debug, and think about.

Refer to the following examples and answer the questions.

pure example

def multiply_by2(nums):
    products = []
    for num in nums:
        products.append(num*2)
    return products


impure examples

balance = 1000
cars = []

def buy_car(new_car):
    cars.append(new_car)
    balance -= 69

import random

def roll_die(num_sides):
    return random.randint(1, num_sides)
