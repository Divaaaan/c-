from collections import deque

n = int(input())
s = list(map(int, input().split()))
dq = deque()
ans = [-1] * n
dq.append(n - 1)
for i in range(n - 2, -1, -1):
    while len(dq) != 0 and s[dq[-1]] > s[i]:
        ans[dq[-1]] = i
        dq.pop()
    dq.append(i)
for i in range(n):
    print(s[ans[i]] if ans[i] != -1 else "net", end=' ')
