#include <bits/stdc++.h>

using namespace std;

int dp[11];

int DP(int n) {
    if (dp[n]) {
        return dp[n];
    }
    if (n < 0) {
        return 0;
    }
    return dp[n] = DP(n - 1) + DP(n - 2) + DP(n - 3);
}

int main(void) {
    int T;
    cin >> T;
    dp[0] = dp[1] = 1;
    DP(10);
    while (T--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}