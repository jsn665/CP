# Use for x dimensional arrays
# bisect left
def bsl(a, t, L=0, R=None):
    if R is None:
        R = len(a)
    while L < R:
        mid = (L + R) // 2
        if a[mid] < t:
            L = mid + 1
        else:
            R = mid
    return L
