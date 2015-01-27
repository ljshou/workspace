#!/usr/bin/python

def cant_reach(can_op, start, target):
    for i in xrange(0, can_op):
        start = start * 2
    if start < target:
        return True
    return False

def search_division(seq, op, max_op, N):
    if seq[op] == N:
        return True
    if op + 1 >= max_op:
        return False
    if cant_reach(max_op - op - 1, seq[op], N):
        return False
    for i in range(op, -1, -1):
        for j in range(i, -1, -1):
            if seq[i] * 2 < seq[op]: break
            if seq[i] + seq[j] <= seq[op]: break
            if seq[i] + seq[j] > N:
                pass
            else:
                seq[op + 1] = seq[i] + seq[j]
                find = search_division(seq, op + 1, max_op, N)
                if find: return True
    return False

def hit_the_number(N):
    max_length = 30
    for i in range(1, max_length + 1):
        seq = [0] * i
        seq[0] = 1
        possible = search_division(seq, 0, i, N)
        if possible: return seq
    seq = [-1] * 1
    return seq

if __name__ == "__main__":
    seq = hit_the_number(15)
    print seq
