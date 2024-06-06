a = {1, 2, 3, 4}
b = {3, 4, 5, 6}
c = a.intersection(b)
print(c)
# {3, 4}

# Assignment

def get_common_formats(formats1, formats2):
    return set(formats1).intersection(set(formats2))
