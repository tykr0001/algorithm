########### github.com/tykr0001/algorithm ###########
#*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*#
#*$*                                             *$*#
#*$*    ||||||||  ||    ||  ||   |||  |||||||    *$*#
#*$*       ||      ||  ||   || |||    ||    ||   *$*#
#*$*       ||        ||     |||       |||||||    *$*#
#*$*       ||        ||     || |||    ||  ||     *$*#
#*$*       ||        ||     ||   |||  ||   |||   *$*#
#*$*                                             *$*#
#*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*#
################ 2021-04-12 03:55:15 ################

################ PyPy3 Header Template  #############
#-*-coding:utf-8-*-
import sys
#####################################################

n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
cache = [[0 for _ in range(n)] for _ in range(n)]


def CanGo(i, j):
    global n
    return 0 <= i < n and 0 <= j < n


cache[0][0] = 1
for i in range(n):
    for j in range(n):
        if not (i == n-1 and j == n-1):
            if CanGo(i+a[i][j], j):
                cache[i+a[i][j]][j] = cache[i+a[i][j]][j] + cache[i][j]
            if CanGo(i, j+a[i][j]):
                cache[i][j+a[i][j]] = cache[i][j+a[i][j]] + cache[i][j]

print(cache[n-1][n-1])
