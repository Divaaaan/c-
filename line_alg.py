n = int(input())
s = list(map(int, input().split()))
dp = [0] * (n + 1)
for i in range(n):
    dp[i + 1] = dp[i] + s[i]

mn = 0
mn_for_ans = 0
mx = 1
dif = dp[1]

for i in range(1, n + 1):
    if dp[i] - dp[mn] > dif:
        dif = dp[i] - dp[mn]
        mx = i
        mn_for_ans = mn
    if dp[mn] > dp[i]:
        mn = i
print(dp[mx] - dp[mn_for_ans], mn_for_ans + 1, mx)
