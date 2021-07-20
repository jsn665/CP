from typing import List

def condition(value) -> bool: # Condition to fulfill
    pass

def search(A: List[int]):
    low = 0 # Minimum search range
    high = 10e9 # Max search range
    while low < high:
        if condition(1):
            high = mid # Include 
        else:
            low = mid + 1 # Exclude
    return low