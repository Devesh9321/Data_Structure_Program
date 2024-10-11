
# Problem Link
# https://codeforces.com/contest/2009/problem/F


def Solution(n,k,q,arr):
    answer = [0]*n
    for i in range(n):
        arr[i] -= i
    print(arr)
    
    for _ in range(q):
            l,r = map(int,input().split(' '))
            # print(  findlongestConstSequence(arr[l-1:r]))

if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        n,k,q = map(int,input().split(' '))
        arr = list( map(int, input().split(' ') ) )
        Solution(n,k,q,arr)

"""
Input
1
7 5 3
1 2 3 2 1 2 3
1 5
2 6
3 7

Output
2
3
2
"""