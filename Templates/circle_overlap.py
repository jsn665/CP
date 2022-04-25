def sq(x):
    return x * x

def overlap(x1, y1, r1, x2, y2, r2):
    dist = sq(x1 - x2) + sq(y1 - y2)
    return dist < r1 + r2

