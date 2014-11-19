f = open('output.txt', 'r')
for line in f.readlines():
    line = line.strip()
    x = line.split('\t', 1)
    print x[0] + '\t' +  x[1] 
