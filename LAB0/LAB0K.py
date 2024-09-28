def competitive_catherine(s: list[int]) -> int:
    odds: list[int] = []
    evens: list[int] = []
    for x in s:
        if x % 2 == 0:
            evens.append(x)
        else:
            odds.append(x)
    odds_total: int = sum(odds)
    odds_total_temp = odds_total
    odds_len: int = len(odds)
    evens_total: int = sum(evens)
    evens_total_temp = evens_total
    evens_len: int = len(evens)
    evens_len_temp = evens_len
    
    competitive_total: int = 0
    print("ODDS")
    for odd in odds:
        odds_total_temp -= odd
        competitive_total = (competitive_total+(odd*(odds_total_temp))) % (10**9)
        print(competitive_total)
    print("EVENS")
    for even in evens:
        competitive_total = (competitive_total + ((even+1)*(odds_total+odds_len))) % (10**9)
        print(competitive_total)
        evens_total_temp -= even
        evens_len_temp -= 1
        competitive_total = (competitive_total + ((even+1)*(evens_total_temp+evens_len_temp))) % (10**9)
        print(competitive_total)
    return competitive_total

t: int = int(input())
for _ in range(t):
    n: int = int(input())
    s: list[int] = [int(x) for x in input().split()]
    print(competitive_catherine(s))