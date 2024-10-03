
# Problem Link
# https://codeforces.com/contest/2009/problem/E

from collections import Counter

"""
Arithmetic Sequence Formulas
Sum of N = n*(n+1)/2 = (n/2)*(n+1)
Sum of First n Terms :	Sn = n/2 * (first term + last term)

Where,
    an = nth term that has to be found
    a1 = 1st term in the sequence
    n  = Number of terms
    d  = Common difference
    Sn = Sum of n terms
"""

def val(mid):
    val1 = (mid+k-1+k)*mid//2
    val2 = (k+n-1+k)*n//2 - val1
    return val1,val2

def Solution(n,k):
    lo = 1
    hi = n
    curr = 1
    while lo <= hi:
        mid = (lo+hi)//2
        a,b = val(mid)
        if b>a:
            curr = mid
            lo = mid+1
        else:
            hi = mid-1
    a1,b1 = val(curr)
    a2,b2 = val(curr+1)
    print(min(b1-a1,a2-b2))

if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        n,k = map(int,input().split(' '))
        Solution(n,k)