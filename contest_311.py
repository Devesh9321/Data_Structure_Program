import time

def returnmax(nums:list,k:int)-> list:
    n = len(nums)
    if n < k : return [-1]
    res = [-1 for _ in range(n - k + 1) ]
    def issorted(subarr:list)->bool:
        if subarr[-1]-subarr[0] != k-1: return False
        for i in range(k-1):
            if subarr[i] > subarr[i+1]: return False
        return True
    
    for i in range(n-k+1):
        if issorted(nums[i:i+k]):
                res[i] = nums[i+k-1]
    
    return res

def maxPoints(points: list[list[int]]) -> int:
        m,n = len(points), len(points[0])

        for i in range(m):
            for j in range(n):
                print(points[i][j],end=' ')
            print()

        res,np = 0,0
        c = 0
        for i in points:
            p,c1 = 0,0
            for j in range(n):
                if p < i[j] : p = i[j]; c1 = j
            res += p
            np = abs(c - c1)
            c = c1
            print(res,np)
        return res - np

if __name__ == "__main__":
    # nums = [1,2,3,4,3,2,5]
    # k = 3
    points = [[1,2,3],[1,5,1],[3,1,1]]
    # res = returnmax(nums,k)
    res = maxPoints(points)
    print(res)