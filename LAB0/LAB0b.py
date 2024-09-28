def to_palindrome(phrase: str) -> int:
    
    if phrase == " ":
        return 0

    left: int = 0
    right: int = len(phrase) - 1
    operations: int = 0

    #print(phrase)
    while left <= right:
        #print(phrase[left] if phrase[left] != " " else "space", phrase[right] if phrase[right] != " " else "space")
        if phrase[left] == " ":
            left += 1
        elif phrase[right] == " ":
            right -= 1
        else:
            if phrase[left] != phrase[right]:
                operations += 1
            left += 1
            right -= 1
    return operations

t: int = int(input())
for t_ in range(t):
    phrase: str = str(input())
    print(to_palindrome(phrase.lower()))