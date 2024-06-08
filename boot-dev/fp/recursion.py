def sum(nums):
    if len(nums) == 0:
        return 0
    return nums[0] + sum(nums[1:])

print(sum([1, 2, 3, 4, 5]))
# 15

# Assignments

def factorial_r(x):
    if x == 0: return 1
    return x * factorial_r(x-1)

def zipmap(keys, values):
    if len(keys) == 0 or len(values) == 0:
        return {}
    res = zipmap(keys[1:], values[1:])
    res[keys[0]] = values[0]
    return res
