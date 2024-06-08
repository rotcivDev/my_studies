def filename_getter(name_extension_tuples):
    map_extension_type = {}
    for type_extensions in name_extension_tuples:
        for extension in type_extensions[1]: map_extension_type[extension] = type_extensions[0]
    return lambda extension: map_extension_type.get(extension, "Unknown")
