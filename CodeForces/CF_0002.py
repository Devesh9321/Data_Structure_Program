
def solution(s):
    if s[0] == "#": return '1'
    elif s[1] == "#": return '2'
    elif s[2] == "#": return '3'
    return '4'
if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        rs = ''
        for _ in range(int(input())):
            rs = solution(input() ) + ' ' + rs
        print(rs)

