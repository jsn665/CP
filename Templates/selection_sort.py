# Minimum number of non-adjacent swaps

def select(a):
    n = len(a)
    for i in range(n):
        min_,pos = a[i], i
        for j in range(i + 1, n):
            if a[j] < min_:
                min_ = a[j]
                pos = j
        
        a[i], a[pos] = a[pos], a[i]




