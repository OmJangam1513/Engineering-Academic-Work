def find(parent, x):

    if parent[x] != x:
        parent[x] = find (parent , parent[x])

    return parent[x]

def union(parent, u, v):
    u_root = find(parent, u)
    v_root = find(parent, v)

    if u_root != v_root:

        parent[v_root] = u_root

        return True

    return False

def kruskal(edges, n):
    parent = list(range(n))

    edges.sort(key=lambda x:x[2])

    mst = []
    total_cost = 0

    for u,v,w in edges:

        if union(parent,u,v):
            mst.append((u,v,w))
            total_cost += w

    return mst, total_cost
    

edges = [
    (0,1,2),
    (1,3,8),
    (0,3,6),
    (1,2,3),
    (1,4,5),
    (2,4,7)
]

n = 5

mst, cost = kruskal(edges, n)

print("Total Cost of MST: ", cost)

for u,v,w in mst:
    print(f"{u} - {v} : {w}")