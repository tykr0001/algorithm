#include <bits/stdc++.h>

using namespace std;

int dp[1001];

int DP(int n) {
    if (dp[n]) {
        return dp[n];
    }
    if (n < 0) {
        return 0;
    }
    return dp[n] = (DP(n - 1) + DP(n - 2) * 2) % 10007;
}

int main(void) {
    int n;
    cin >> n;
    dp[0] = dp[1] = 1;
    cout << DP(n) << endl;
}