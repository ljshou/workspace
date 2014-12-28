#!/usr/bin/python

def count(filename):
    fout = open("match_count.txt", "w")
    with open(filename, "r") as f:
        while True:
            line = f.readline().strip()
            if not line: break
            i,j = 0,0
            MCount, DCount, ICount = 0,0,0
            while j < len(line):
                if line[j] == 'M':
                    MCount += int(line[i:j])
                    i = j+1
                elif line[j] == 'D':
                    DCount += int(line[i:j])
                    i = j+1
                elif line[j] == 'I':
                    ICount += int(line[i:j])
                    i = j+1
                j += 1
            fout.write("%25s" % line + "\t" + str(MCount) + "\t" + str(DCount) + "\t" 
                    + str(ICount) + "\n")
    fout.close()

if __name__ == "__main__":
    count("Match_Insertion_deletion.txt")
