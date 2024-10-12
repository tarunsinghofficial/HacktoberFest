## Read input as specified in the question.
## Print output as specified in the question.
from itertools import combinations

def special_string(s, p, alpha, ix):
    alpha_ix=alpha.index(s[ix])
    if alpha_ix+1<p:
        s=[i for i in s]
        s[ix]=alpha[alpha_ix+1]
        s=''.join(s)
        substr_s=[s[x:y] for x,y in combinations(range(len(s)+1), r=2) if len(s[x:y])>1]
        for i in substr_s:
            if i==i[::-1]:
                return 'NO'
        return s
    s=[i for i in s]
    s[ix]='a'
    s=''.join(s)
    s=special_string(s, p, alpha, ix-1)
    return s

inp = input().split()
n, p = int(inp[0]), int(inp[1])
s=input()

alpha='abcdefghijklmnopqrstuvwxyz'
print(special_string(s,p,alpha, len(s)-1))
