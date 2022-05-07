def djssp(src, trg, graph, n):
    dist = [float('-inf')] * n
    dist[src] = 0
    heap = [(0, src)]
    heapify(heap)
    while heap:
        top = heappop(heap)
        curr = top[1]
        min_dist = top[0]
        if min_dist > dist[curr]:
            continue
        for neighbor, weight in graph[curr]:
            dist_to = dist[curr] + weight
            if dist_to > dist[neighbor]:
                dist[neighbor] = dist_to
                heappush(heap, (dist_to, neighbor))
    return dist
