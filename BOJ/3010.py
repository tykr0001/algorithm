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
################ 2021-04-12 03:20:33 ################

################ PyPy3 Header Template  #############
#-*-coding:utf-8-*-
import sys
#####################################################


def CanGo(i, j):
    return 0 <= i < 7 and 0 <= j < 7


a = [list(sys.stdin.readline().rstrip('\n')) for _ in range(7)]

di = [0, 0, -1, 1]
dj = [-1, 1, 0, 0]

ans = 0
for i in range(7):
    for j in range(7):
        for k in range(4):
            if CanGo(i+di[k], j+dj[k]) and CanGo(i+2*di[k], j+2*dj[k]):
                if a[i][j] == 'o' and a[i+di[k]][j+dj[k]] == 'o'\
                        and a[i+2*di[k]][j+2*dj[k]] == '.':
                    ans = ans+1
print(ans)
