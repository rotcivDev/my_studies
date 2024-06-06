def square(x):
    return x * x

nums = [1, 2, 3, 4, 5]
squared_nums = map(square, nums)
print(list(squared_nums)) 
# [1, 4, 9, 16, 25]
print(squared_nums)
# <map object at 0x73c8bcc57ee0>

# Assignment

def change_bullet_style(document):
    return "\n".join(map(convert_line, document.split("\n")))


# Don't edit below this line


def convert_line(line):
    old_bullet = "-"
    new_bullet = "*"
    if len(line) > 0 and line[0] == old_bullet:
        return new_bullet + line[1:]
    return line
