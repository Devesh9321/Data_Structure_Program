
# Problem Link
# https://codeforces.com/contest/2009/problem/F
from collections import deque

def Solution(n,q,arr):
    # using Maths
    ps = [0]
    for e in arr:
        ps.append( ps[-1] + e )
    for e in arr:
        ps.append( ps[-1] + e )
    
    for _ in range(q):
            l,r = map(int,input().split(' '))
            l,r = l-1,r-1
            i,j = l//n,r//n
            l,r = l%n,r%n
            print( ps[n] * (j-i+1) - (ps[i+l] - ps[i]) - ( ps[j+n] - ps[j+r+1]) )

    """
    # Using Brutforce
    que = deque(arr)
    b = []
    for _ in range((l%n)+(r%n)):
        b.extend(que)
        que.rotate(-1)
    print( sum(b[l-1:r]) ) 
    """

if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        n,q = map(int,input().split(' '))
        arr = list( map(int, input().split(' ') ) )
        Solution(n,q,arr)

"""
Input
1
3 1
1 2 3
1 9

Output
18
"""