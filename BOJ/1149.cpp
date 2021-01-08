#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;   // [i]번째 집을 [j]색으로 칠했을 때 [0,i]까지 칠하는 최소 비용
vector<vector<int>> cost; // [i]번째 집을 [j]색으로 칠하는 비용

int DP(int idx, int color) {
    if (dp[idx][color] != INT32_MAX) {
        return dp[idx][color];
    }
    if (idx == 0) {
        return 0;
    }
    switch (color) {
    case 0:
        return dp[idx][color] = min(DP(idx - 1, 1), DP(idx - 1, 2)) + cost[idx][0];
        break;
    case 1:
        return dp[idx][color] = min(DP(idx - 1, 0), DP(idx - 1, 2)) + cost[idx][1];
        break;
    case 2:
        return dp[idx][color] = min(DP(idx - 1, 0), DP(idx - 1, 1)) + cost[idx][2];
        break;
    default:
        return INT32_MAX;
        break;
    }
}

int main(void) {
    int N;
    cin >> N;
    dp.resize(N + 1, vector<int>(3, INT32_MAX));
    cost.resize(N + 1, vector<int>(3));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }
    cout << min(min(DP(N, 0), DP(N, 1)), DP(N, 2)) << endl;
    return 0;
}