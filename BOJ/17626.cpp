#include <bits/stdc++.h>

using namespace std;

int N;
int dp[50001];

int DP(int n) {
    if (dp[n]) {
        return dp[n];
    }
    if (n <= 0) {
        return 0;
    }
    int ret = INT32_MAX;
    for (int i = sqrt(n); i>=1; i--) {
        ret = min(ret, DP(n - i * i) + 1);
    }
    return dp[n] = ret;
};

int main(void) {
    cin >> N;
    dp[1] = 1;
    cout << DP(N) << endl;
}