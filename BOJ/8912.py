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
################ 2021-04-11 14:28:55 ################

################ PyPy3 Header Template  #############
#-*-coding:utf-8-*-
import sys
#####################################################

t = int(input())
while t!=0:
    t = t-1
    answer = 0
    n = int(input())
    arr = list(map(int, input().split()))
    for a in range(1,n,1):
        for b in range(0,a,1):
            if arr[b] <= arr[a]:
                answer = answer + 1
    print(answer)