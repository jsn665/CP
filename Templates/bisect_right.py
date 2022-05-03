# Use for x dimensional arrays
# bisect right
def bsr(a, t, L=0, R=None):
    if R is None:
        R = len(a)
    while L < R:
        mid = (L + R) // 2
        if a[mid] > t:
            R = mid
        else:
            L = mid + 1
    return L
