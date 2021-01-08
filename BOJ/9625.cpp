#include <iostream>
#include <vector>
using namespace std;

int K;
vector<vector<int>> dp; // dp[i][0] -> i번 눌렀을 때 A갯수
                        // dp[i][1] -> i번 눌렀을 때 B갯수

int main(void) {
    cin >> K;
    dp.resize(K + 1, vector<int>(2));
    dp[0][0] = 1;
    dp[0][1] = 0;

    for (int i = 1; i <= K; ++i) {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
    }

    cout << dp[K][0] << " " << dp[K][1] << endl;
}