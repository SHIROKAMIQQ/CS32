def make_adj_list(n: int, edges: tuple[tuple[int,int], ...]) -> tuple[list[list[int]], list[int]]:
    adj_list: list[list[int]] = [[] for _ in range(n)]
    degree: list[int] = [0 for _ in range(n)]
    for edge in edges:
        i = edge[0]
        j = edge[1]
        adj_list[i].append(j)
        adj_list[j].append(i)
        degree[i] += 1
        degree[j] += 1
    return (adj_list, degree)

def dfs(graph: list[list[int]], degree: list[int], distance: list[int], x: int, prev: int) -> bool: #return true to indicate cyclic with same parity
    if distance[x] != 0:
        return True if distance[x] == distance[prev] else False
    
    distance[x] = 2 if distance[prev] == 1 else 1

    parity_cyclic: bool = False
    for d in range(degree[x]):
        if dfs(graph, degree, distance, graph[x][d], x): 
            parity_cyclic = True
    return parity_cyclic

def categorize(n: int, nodes: tuple[int, ...], distance: list[int]) -> tuple[int, int, int]:
    sums: list[int] = [0, 0, 0, 0]
    for i in range(n):
        sums[distance[i]] += nodes[i]
    return (sums[1], sums[2], sums[3])

def combinations(flea1: int, flea2: int, flea3: int) -> int:
    return flea1 * flea2 * flea3

def flea_sum(nodes: tuple[int, ...], edges: tuple[tuple[int,int], ...], x: tuple[int, int, int]) -> int:
    n: int = len(nodes)
    graph, degree = make_adj_list(n, edges)
    
    #Distance from x: 0 = not yet discorvered, 1 = odd, 2 = even, 3 = all 
    d0: list[int] = [0 for _ in range(n)]
    d1: list[int] = [0 for _ in range(n)]
    d2: list[int] = [0 for _ in range(n)]
    if dfs(graph, degree, d0, x[0], 0):
        for i in range(n): d0[i] = 3 if d0[i] != 0 else 0
    if dfs(graph, degree, d1, x[1], 0):
        for i in range(n): d1[i] = 3 if d1[i] != 0 else 0
    if dfs(graph, degree, d2, x[2], 0):
        for i in range(n): d2[i] = 3 if d2[i] != 0 else 0

    flea1_odds, flea1_evens, flea1_alls = categorize(n, nodes, d0)
    flea2_odds, flea2_evens, flea2_alls = categorize(n, nodes, d1)
    flea3_odds, flea3_evens, flea3_alls = categorize(n, nodes, d2)

    sum_states: int = 0
    sum_states += combinations(flea1_odds, flea2_odds, flea3_odds)
    sum_states += combinations(flea1_odds, flea2_odds, flea3_alls)
    sum_states += combinations(flea1_odds, flea2_alls, flea3_odds)
    sum_states += combinations(flea1_odds, flea2_alls, flea3_alls)
    sum_states += combinations(flea1_alls, flea2_odds, flea3_odds)
    sum_states += combinations(flea1_alls, flea2_odds, flea3_alls)
    sum_states += combinations(flea1_alls, flea2_alls, flea3_odds)
    sum_states += combinations(flea1_alls, flea2_alls, flea3_alls)
    
    sum_states += combinations(flea1_evens, flea2_evens, flea3_evens)
    sum_states += combinations(flea1_evens, flea2_evens, flea3_alls)
    sum_states += combinations(flea1_evens, flea2_alls, flea3_evens)
    sum_states += combinations(flea1_evens, flea2_alls, flea3_alls)
    sum_states += combinations(flea1_alls, flea2_evens, flea3_evens)
    sum_states += combinations(flea1_alls, flea2_evens, flea3_alls)
    sum_states += combinations(flea1_alls, flea2_alls, flea3_evens)

    return sum_states

print(flea_sum((3, 1, 4), (
    (0, 2),
    (1, 1),
), (0, 1, 0)))
print(flea_sum((3, 1, 4), (
    (0, 2),
    (1, 1),
), (0, 1, 2)))
print(flea_sum((3, 1, 4), (
    (0, 2),
    (0, 1),
    (1, 2),
), (0, 1, 2)))
print(flea_sum((3, 1, 4, 2), (
    (0, 1),
    (1, 2),
    (2, 3),
    (3, 0),
), (0, 1, 2)))
