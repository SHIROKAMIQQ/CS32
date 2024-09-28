def get_heights(n: int) -> list[int]:
    arr: list[int] = [int(x) for x in input().split()]
    return arr[:n]

def get_total(h: list[int], w: int, i: int, j: int) -> int:
    total: int = 0
    total += sum(h[i: j+1])
    total += (j-i+1)*w*2
    return total

t: int = int(input())
for _ in range(t):
    h: list[int] = get_heights(int(input()))
    q: int = int(input())
    waters: int = 0
    for __ in range(q):
        command: list[str] = input().split()
        if command[0] == 'water':
            waters += 1
        elif command[0] == 'total':
            print(get_total(h, waters, int(command[1])-1, int(command[2])-1))

"""
3 1 4 1 5 9
14
total 2 4

"""