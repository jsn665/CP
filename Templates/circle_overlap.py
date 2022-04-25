def sq(x):
    return x * x

def overlap(x1, y1, r1, x2, y2, r2):
    dist = sq(x1 - x2) + sq(y1 - y2)
    return dist < sq(r1 + r2)

# dist < sq(r1 + r2) -> overlap
# dist == sq(r1 + r2) -> touches
# dist > sq(r1 + r2) -> no overlap or touch
# dist <= sq(rx) point lies on the circle with radius rx

