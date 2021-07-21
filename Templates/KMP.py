from typing import List

# KMP Algorithm 
def constructLPS(pat: str) -> List[int]:
    m = len(pat)
    lps = [0] * m
    i = 0
    j = 1
    while j < m:
        if pat[i] == pat[j]:
            lps[j] = i + 1
            i += 1
            j += 1
        else:
            if i != 0:
                i = lps[i - 1]
            else:
                lps[j] = 0
                j += 1
    return lps


def KMP(a: str, pat: str):
    lps = constructLPS(pat)
    i = 0
    j = 0
    while j < len(pat) and i < len(a):
        if a[i] == pat[j]:
            j += 1
            i += 1
        else:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
    return j == len(pat)

