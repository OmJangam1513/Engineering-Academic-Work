import heapq

def prim_mst(graph, start):
    visited = set()
    pq = [(0, start, -1)]  # (weight, node, parent)
    
    total_cost = 0
    mst_edges = []

    while pq:
        weight, u, parent = heapq.heappop(pq)

        if u in visited:
            continue

        visited.add(u)
        total_cost += weight

        if parent != -1:
            mst_edges.append((parent, u, weight))

        for v, w in graph[u]:
            if v not in visited:
                heapq.heappush(pq, (w, v, u))

    return total_cost, mst_edges


# Same graph
graph = {
    0: [(1,2),(3,6)],
    1: [(0,2),(2,3),(3,8),(4,5)],
    2: [(1,3),(4,7)],
    3: [(0,6),(1,8)],
    4: [(1,5),(2,7)]
}

cost, mst = prim_mst(graph, 0)

print("MST Cost:", cost)
print("Edges in MST:")
for u, v, w in mst:
    print(f"{u} - {v} : {w}")