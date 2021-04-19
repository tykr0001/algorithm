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
################ 2021-04-11 14:44:22 ################

################ PyPy3 Header Template  #############
#-*-coding:utf-8-*-
import sys
#####################################################

n = int(input())
arr = list(map(int, input().split()))
ans = [0 for _ in range(n)]

for i in range(0, n, 1):
    cnt = 0
    j = 0
    while arr[i] != cnt:
        if ans[j] == 0:
            cnt = cnt + 1
        j = j + 1
    while ans[j] != 0:
        j = j + 1
    ans[j] = i + 1

print(*ans)
