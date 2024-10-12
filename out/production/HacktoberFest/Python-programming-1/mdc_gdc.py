def gcd(a,b):
    if a == 0: return b
    if b == 0: return a
    return gcd(b, a%b)

def mmc(a,b):
    return (a/gcd(a,b))*b

