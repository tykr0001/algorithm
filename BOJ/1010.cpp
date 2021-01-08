#include<iostream>

using namespace std;

int T, N, M;
int dp[30][30];

int c(int n, int r) {
    if (n == r) {
        return 1;
    }
    if (r == 1) {
        return n;
    }
    if (r == 0) {
        return 1;
    }
    if (dp[n][r])
        return dp[n][r];
    return dp[n][r] = c(n - 1, r - 1) + c(n - 1, r);
}

int main(void) {
    cin >> T;
    while (T--) {
        cin >> N >> M;
        cout << c(M, N) << endl;
    }
    return 0;
}