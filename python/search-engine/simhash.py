def simhash(features, hashbits=32):
    if hashbits == 32:
        hashfn = hash
    else:
        hashfn = lambda s: _hash(s, hashbits)

    vs = [0] * hashbits
    for feature, weight in features:
        h = hashfn(feature)
        for i in xrange(hashbits):
            if h & (1 << i):
                vs[i] += weight
            else:
                vs[i] -= weight

    out = 0
    print vs
    for i, v in enumerate(vs):
        if v > 0:
            out |= 1 << i
    return out

def _hash(s, hashbits):
    # A variable-length version of Python's builtin hash
    if s == "":
        return 0
    else:
        x = ord(s[0]) << 7
        m = 1000003
        mask = 2 ** hashbits - 1
        for c in s:
            x = ((x * m) ^ ord(c)) & mask
        x ^= len(s)
        if x == -1:
            x = -2
        return x

def hamming_distance(first_hash, other_hash, hashbits=32):
    x = (first_hash ^ other_hash) & ((1 << hashbits) - 1)
    tot = 0
    while x:
        tot += 1
        x &= x - 1
    return tot

f1 = {
        'a': 10,
        'b': 3,
        'c': 7,
        'd': 4,
        }
f2 = {
        'a': 10,
        'p': 3,
        'c': 7,
        'd': 4,
        }
sh1 = simhash(f1.items())
sh2 = simhash(f2.items())
dist = hamming_distance(sh1, sh2)
print bin(sh1),bin(sh2),dist