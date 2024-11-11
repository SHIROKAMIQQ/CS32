def make_adj_matrix(n: int, e: tuple[tuple[int, int]]) -> list[list[bool]]:
    adj_matrix: list[list[bool]] = [[False for _j in range(n)] for _i in range(n)]
    for edge in e:
        i = edge[0]
        j = edge[1]
        adj_matrix[i][j] = True
    return adj_matrix