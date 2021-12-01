n = int(input())
s = int(input())
a = len(str(n))
dp = [[[0 for i in range(2)] for j in range(s + 1)] for t in range(a + 1)]
dig = list(map(int, list(str(n))))
dp[0][0][1] = 1
for i in range(1, a + 1):
    for j in range(s + 1):
        if dig[i - 1] <= s:
            dp[i][j][1] = dp[i - 1][s - dig[i - 1]][1]
        for d in range(10):
            if j - d >= 0:
                dp[i][j][0] += dp[i - 1][j - d][0]
                if j < dig[i - 1]:
                    dp[i][j][0] += dp[i - 1][j - d][1]
print(dp[a][s][0] + dp[a][s][1])

