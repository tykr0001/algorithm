import sys


def my_mul(A, B):
    M = [[0 for col in range(N)] for row in range(N)]
    for i in range(N):
        for j in range(N):
            for k in range(N):
                M[i][j] = M[i][j] + A[i][k] * B[k][j]
                M[i][j] = M[i][j] % 1000
    return M


def f(matrix, exp):
    global N
    # basis condition
    if exp == 1:
        return matrix

    if exp == 2:
        return my_mul(matrix, matrix)

    if exp % 2 == 0:
        return f(f(matrix, exp/2), 2)
    else:
        return my_mul(f(f(matrix, (exp-1)/2), 2), matrix)


N, B = map(int, sys.stdin.readline().rstrip().split())

M = [0 for col in range(N)]

for i in range(N):
    M[i] = list(map(int, sys.stdin.readline().rstrip().split()))

ans = f(M, B)

for i in range(N):
    for j in range(N):
        print(ans[i][j], end=' ')
    print()
