import sys

count_array=[]
array=[]
column_move=[0,1,0,-1]
row_move=[-1,0,1,0]
N,M=(0,0)
Max,Count=0,0


def put_board(n,m):
    global count_array
    global N
    global M
    if count_array[n][m]==-1:
        return False
    for i in range(0,4):
        if 0<=n+row_move[i]<N and 0<=m+column_move[i]<M:
            if count_array[n+row_move[i]][m+column_move[i]]==-1:
                return False
    count_array[n][m]=-1
    for i in range(0,4):
        if 0<=n+row_move[i]<N and 0<=m+column_move[i]<M:
            count_array[n+row_move[i]][m+column_move[i]]+=1
    return True


def return_board(n,m):
    global N
    global M
    count_array[n][m]=0
    for i in range(0,4):
        if 0<=n+row_move[i]<N and 0<=m+column_move[i]<M:
            count_array[n+row_move[i]][m+column_move[i]]-=1


def start(k,i_,j_):
    global Max
    global Count
    global M
    global N
    if k==0:
        Max=max(Max,Count)
        return
    else:
        for t in range(j_,M):
            if put_board(i_,t)==True:
                Count+=array[i_][t]
                start(k-1,i_,t)
                Count-=array[i_][t]
                return_board(i_,t)
            else:
                continue
        for i in range(i_+1,N):
            for j in range(M):
                if put_board(i,j)==True:
                    Count+=array[i][j]
                    start(k-1,i,j)
                    Count-=array[i][j]
                    return_board(i,j)
                else:
                    continue

                
lst=list(map(int,sys.stdin.readline().split()))
N=lst[0]
M=lst[1]
for i in range(N):
    array.append(list(map(int,sys.stdin.readline().split())))

count_array=[[]]*N
for i in range(N):
    count_array[i]=[0]*M

start(lst[2],0,0)
print(Max)