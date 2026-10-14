import heapq

def prims_mst(graph,start):

    visited = set()

    pq = []
    heapq.heappush(pq,(0,start, -1))

    mst = []
    total_cost = 0

    while(pq):

        weight, u, parent = heapq.heappop(pq)

        if u in visited:
            continue

        visited.add(u)
        total_cost += weight

        if parent != -1: 
            mst.append((parent, u, w))

        for v,w in graph[u]:
            if v not in visited:
                heapq.heappush(pq,(w,v,u))

    return mst, total_cost

graph = {
    0:[(1,2),(3,6)],
    1:[(0,2),(3,8),(2,3),(4,5)],
    2:[(4,7),(1,3)],
    3:[(0,6),(1,8)],
    4:[(2,7),(1,5)]
}

mst, cost = prims_mst(graph,0)

print("Total Cost of MST: ", cost)

for u,v,w in mst:
    print(f"{u} - {v} : {w}")