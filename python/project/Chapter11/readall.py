f = open(filename)
for char in f.read():
    process(char)

f = open(filename)
for line in f.readlines():
    process(line)

