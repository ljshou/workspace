from htmlFunctions import *
import sys

speakers = ['PALIN', 'BIDEN', 'IFILL']
punctions = '.,;-"'
def remove_punctions(word):
    res = ''
    for ch in word:
        if not ch in punctions: res += ch
    return res

stop_word = set([])
with open('stop2.txt') as f:
    for line in f.readlines():
        line = line.strip()
        if not line: continue
        for word in line.split():
            stop_word.add(word.lower())

# count words
pairs = [{}, {}]
tag = 2
with open('debate.txt') as f:
    for line in f.readlines():
        line = line.strip()
        if not line: continue

        #find who's the speaker
        word = line.split()[0].lower()
        print 'word:', word
        if word[-1] == ':':
            if word[:-1] == speakers[0].lower(): 
                tag = 0
            elif word[:-1] == speakers[1].lower(): 
                tag = 1
            elif word[:-1] == speakers[2].lower(): 
                tag = 2

        if tag == 2: continue
        for word in line.split():
            if word[-1] == ':': continue
            word = remove_punctions(word).lower()
            if word and not word in stop_word:
                if pairs[tag].has_key(word): 
                    pairs[tag][word] = pairs[tag][word] + 1
                else:
                    pairs[tag][word] = 1

for i in range(2):
    # find the largest 40 words
    pairs[i] = sorted(pairs[i].items(), key = lambda d: d[1], reverse=True)
    if len(pairs[i]) > 40: pairs[i] = pairs[i][:40]
    print pairs[i]

    high_count = pairs[i][0][1]
    low_count = pairs[i][-1][1]

    pairs[i] = sorted(pairs[i])

    body = ''
    for word, cnt in pairs[i]:
        body = body + makeHTMLword(word, cnt, high_count, low_count)
    box = makeHTMLbox(body)
    printHTMLfile(box, speakers[i].lower())
