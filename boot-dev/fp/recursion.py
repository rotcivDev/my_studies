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

def sum_nested_list(lst):
    size = 0
    for item in lst:
        if not isinstance(item, list): size += item
        else: size += sum_nested_list(item)
    return size

def list_files(current_filetree, current_path=""):
    file_paths = list()

    for node in current_filetree:
        nested = current_filetree[node]
        if nested == None: file_paths.append(f"{current_path}/{node}")
        else: 
            file_paths.extend(list_files(nested, f"{current_path}/{node}"))

    return file_paths

def count_nested_levels(nested_documents, target_document_id, level=1):
    for document_id in nested_documents:
        if document_id == target_document_id:
            return level
        found_level = count_nested_levels(
            nested_documents[document_id], target_document_id, level + 1
        )
        if found_level != -1:
            return found_level
    return -1

def reverse_string(s):
    if len(s) == 0:
        return s
    return reverse_string(s[1:]) + s[0]
