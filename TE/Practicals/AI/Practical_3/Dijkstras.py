import heapq

def dijkstra(graph, start):
    dist = {}

    for node in graph:
    dista[node] = float('inf')

    dist[start] = 0

    pq = [(0, start)]

    while pq:
        current_dist, u = heapq.heappop(pq)

        if current_dist > dist[u]:
            continue

        for v, weight in graph[u]:
            if dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight
                heapq.heappush(pq, (dist[v], v))

    return dist

graph = {
    0: [(1,2),(3,6)],
    1: [(0,2),(2,3),(3,8),(4,5)],
    2: [(1,3),(4,7)],
    3: [(0,6),(1,8)],
    4: [(1,5),(2,7)]
}

print(dijkstra(graph, 0))