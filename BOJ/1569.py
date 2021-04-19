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
################ 2021-04-12 05:04:39 ################

################ PyPy3 Header Template  #############
#-*-coding:utf-8-*-
import sys
#####################################################

n = int(input())
p = [list(map(int, input().split())) for _ in range(n)]
min_i, min_j, max_i, max_j, = [1000, 1000, -1000, -1000]
flag = True

for k in range(n):
    i, j = p[k]
    min_i = min(min_i, i)
    min_j = min(min_j, j)
    max_i = max(max_i, i)
    max_j = max(max_j, j)

for k in range(n):
    i, j = p[k]
    if (i == min_i and j == min_j) or (i == min_i and j == max_j) or \
            (i == max_i and j == min_j) or (i == max_i and j == max_j):
        pass
    else:
        flag = False

if flag:
    print(max(max_i-min_i, max_j-min_j))
else:
    print(-1)
