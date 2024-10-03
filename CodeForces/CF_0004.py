
# Problem Link
# https://codeforces.com/contest/2009/problem/D

def Solution(Points):
    pass

if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        n = map(int,input())
        Points = []
        for _ in range(n):
            x,y = map(int, input().split(' '))
            Points.append( [x,y] )
        print( Solution(Points) )
