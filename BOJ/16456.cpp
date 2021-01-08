#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp; // i번째 섬까지 가는 방법, j : 마지막 탐색지점 j==0 : i-1, j==1 : i
int n;

int main(void) {
    cin >> n;
    dp.resize(n + 1, vector<int>(2, 0));

    if (n == 1 || n == 2) {
        cout << 1 << endl;
        return 0;
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = 1;
    dp[1][1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000009;
        dp[i][1] = dp[i - 2][0];
    }
    cout << (dp[n][1] + dp[n][0]) % 1000000009 << endl;

    return 0;
}