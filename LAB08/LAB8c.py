def make_grid_graph(grid: tuple[str, ...]) -> tuple[int, list[tuple[int, int]]]:
    r = len(grid)
    c = len(grid[0])
    
    n: int = 0
    intgrid: list[list[int]] = [[-1 for _c in range(c)] for _r in range(r)]
    for r_ in range(r):
        for c_ in range(c):
            if grid[r_][c_] != '!':
                intgrid[r_][c_] = n
                n += 1

    edges: list[tuple[int, int]] = []
    for r_ in range(r):
        for c_ in range(c):
            if intgrid[r_][c_] == -1:
                continue
            if 0 <= r_+1 < r and intgrid[r_+1][c_] >= 0:
                edges.append((intgrid[r_][c_], intgrid[r_+1][c_]))
            if 0 <= c_+1 < c and intgrid[r_][c_+1] >= 0:
                edges.append((intgrid[r_][c_], intgrid[r_][c_+1]))
    
    return (n, edges)