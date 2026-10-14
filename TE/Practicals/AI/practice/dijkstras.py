import heapq

def dijkstras(graph, start):
    dist = {}

    for node in graph:
        dist[node] = float('inf')
    
    dist[start] = 0

    pq = []

    heapq.heappush(pq,(0,start))

    while(pq):

        current_dist, u = heapq.heappop(pq)

        if current_dist > dist[u]:
            continue
        
        for v,w in graph[u]:

            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                heapq.heappush(pq,(dist[v],v))

    return dist

graph = {
    0:[(1,2),(3,6)],
    1:[(0,2),(3,8),(2,3),(4,5)],
    2:[(4,7),(1,3)],
    3:[(0,6),(1,8)],
    4:[(2,7),(1,5)]
}

print(dijkstras(graph,0))