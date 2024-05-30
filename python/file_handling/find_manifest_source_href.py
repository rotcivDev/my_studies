import fileinput
import readline

source = None

for line in fileinput.input(files=["./xmlmanifest.xml"], encoding="utf-8"):
    if 'href' in line:
        source = line

print(type(source))
print(source.split('"'))
href = source.split('"')[1]
print(href)
