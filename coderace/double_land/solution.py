import sys

# Init
n = int(input())
arr = sorted([int(sys.stdin.readline().strip('\n'))
                 for i in range(n)], reverse=True)
odd_sum = [0 for i in range(n)]
even_sum = [0 for i in range(n)]
dp = [[0, 0] for i in range(n)]

for i in range(n):
    if i % 2 != 0:
        odd_sum[i] += odd_sum[max(i - 1, 0)] + arr[i]
        odd_sum[min(i + 1, n - 1)] = odd_sum[i]
    else:
        even_sum[i] += even_sum[max(i - 1, 0)] + arr[i]
        even_sum[min(i + 1, n - 1)] = even_sum[i]\

# Solve
if n <= 3:
    print((arr[0]+arr[1])*2)
else:
    for i in range(n-2, -1, -1):
        tmp_A = 0
        tmp_B = 0
        for j in range(i+2, n-1, 2):
            if i % 2 == 0:
                tmp_A = (even_sum[i] + arr[i + 1]) * 2
                tmp_A += odd_sum[j] - odd_sum[i + 1] + \
                    even_sum[n - 1] - even_sum[j]
                tmp_B = (odd_sum[i] + even_sum[j] -
                         even_sum[i] + arr[j + 1]) * 2
                tmp_B += odd_sum[n - 1] - odd_sum[j + 1]

                if dp[i][1] <= tmp_B:
                    dp[i][1] = tmp_B
                    if dp[i][0] == 0:
                        dp[i][0] = tmp_A
                    else:
                        dp[i][0] = min(dp[i][0], tmp_A)

                if dp[i][0] <= dp[i + 1][0]:
                    dp[i][0] = dp[i + 1][0]
                    if dp[i][1] == 0:
                        dp[i][1] = dp[i + 1][1]
                    else:
                        dp[i][1] = min(dp[i + 1][1], dp[i][1])
            else:
                tmp_B = (odd_sum[i] + arr[i + 1]) * 2
                tmp_B += even_sum[j] - even_sum[i + 1] + \
                    odd_sum[n - 1] - odd_sum[j]
                tmp_A = (even_sum[i] + odd_sum[j] -
                         odd_sum[i] + arr[j + 1]) * 2
                tmp_A += even_sum[n - 1] - even_sum[j + 1]

                if dp[i][0] <= tmp_A:
                    dp[i][0] = tmp_A
                    if dp[i][1] == 0:
                        dp[i][1] = tmp_B
                    else:
                        dp[i][1] = min(dp[i][1], tmp_B)

                if dp[i][1] <= dp[i + 1][1]:
                    dp[i][1] = dp[i + 1][1]
                    if dp[i][0] == 0:
                        dp[i][0] = dp[i + 1][0]
                    else:
                        dp[i][0] = min(dp[i + 1][0], dp[i][0])
    print(dp[0][0])
