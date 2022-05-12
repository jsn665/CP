def LIS(arr):
    n = len(arr)
    deck = []
    for i in range(n):
        indx = bisect.bisect_left(deck, arr[i])
        if indx == len(deck):
            deck.append(0)
        deck[indx] = arr[i]
    return len(deck)
