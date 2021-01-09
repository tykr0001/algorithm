#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

LL t;
LL n;

vector<LL> card;
vector<LL> dp;

LL DP(int idx) {
    if (dp[idx]) {
        return dp[idx];
    }
    else {
        LL tmp = card[idx];
        if (idx + card[idx] < n) {
            tmp += DP(idx + card[idx]);
        }
        return dp[idx] = tmp;
    }
}

int main(void) {
    cin >> t;
    while (t--) {
        cin >> n;
        card.resize(n);
        dp.resize(n, 0);

        for (LL i = 0; i < n; i++) {
            cin >> card[i];
        }
        for (LL i = n - 1; i >= 0; i--) {
            DP(i);
        }
        LL score = 0;
        for (LL i = 0; i < n; i++) {
            score = max(DP(i), score);
        }

        card.clear();
        dp.clear();
        cout << score << endl;
    }
}