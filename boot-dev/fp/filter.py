def is_even(x):
    return x % 2 == 0

numbers = [1, 2, 3, 4, 5, 6]
evens = list(filter(is_even, numbers))
print(evens)
# [2, 4, 6]

# Assignment
def remove_invalid_lines(document):
    return "\n".join(filter( lambda line : not line.startswith("-") ,document.split("\n")))

# Tips

#.join
#"\n".join(["a", "b", "c"])
# a
# b
# c

#.startswith
#s = "hello"
#s.startswith("h")
# True
#s.startswith("o")
# False

#.split
#s = """hello
#world"""
#lines = s.split("\n")
# ['hello', 'world']

