from itertools import combinations

def nonDivisibleSubset(k, s):
    # Write your code here
    res=[]
    for pair in list(combinations(s, 2)):
        if sum(pair)%k != 0:
            # print(res, pair)
            res+=list(pair)

    print(set(res))
    return len(set(res))

if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()
    n = int(first_multiple_input[0])
    k = int(first_multiple_input[1])
    s = list(map(int, input().rstrip().split()))
    result = nonDivisibleSubset(k, s)
    print(result)
