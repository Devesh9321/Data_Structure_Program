import sys

def solution(a,b):
    a,b = int(a),int(b)
    r = float("inf")
    for i in range(a,b+1):
        r = min(r, (i-a)+(b-i))
    return r

if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        a,b = input().split(' ')
        print(solution(a,b))

