n = int(input())
k = int(input())
s = list(map(int, input().split()))
sm = s[0]
l = 0
r = 0

while r < n - 1 or sm > k:
    if sm > k:
        sm -= s[l]
        l += 1
    elif sm < k:
        r += 1
        sm += s[r]
    if sm == k:
        print(l, r)
        exit(0)
print('None')
