def find(parent, x):

    if parent[x] != x:
        parent[x] = find(parent, parent[x])

    return parent[x]


def union(parent, u, v):

    root_u = find(parent, u)
    root_v = find(parent, v)

    if root_u != root_v:
        parent[root_v] = root_u
        return True

    return False


def kruskal(n, edges):

    parent = list(range(n))

    edges.sort(key=lambda x: x[2])

    mst = []
    total_cost = 0

    for u, v, w in edges:

        if union(parent, u, v): # If roots of two vertices are same, adding that edge may create a cycle.
            mst.append((u, v, w))
            total_cost += w

    return mst, total_cost

edges = [
    (0, 1, 2),
    (0, 3, 6),
    (1, 2, 3),
    (1, 3, 8),
    (1, 4, 5),
    (2, 4, 7)
]

n = 5

mst, cost = kruskal(n, edges)

print("Minimum Spanning Tree:")

for u, v, w in mst:
    print(f"{u} - {v} : {w}")

print("Total Cost:", cost)