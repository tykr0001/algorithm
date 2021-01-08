#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL dp[51];

LL Ex(LL i) {
    if (dp[i]) {
        return dp[i];
    }
    if (i == 1) {
        return 31;
    }
    if (i == 0) {
        return 1;
    }
    LL tmp = Ex(i / 2);
    if (i % 2) {
        return dp[i] = tmp * tmp % 1234567891 * 31 % 1234567891;
    }
    else {
        return dp[i] = tmp * tmp % 1234567891;
    }
}

LL Calc(char c, LL i) {
    return (c - 'a' + 1) * Ex(i);
}

int main(void) {
    LL L;
    string str;
    cin >> L;
    cin >> str;

    LL answer = 0;
    for (int i = 0; i < L; i++) {
        answer += Calc(str[i], i);
        answer %= 1234567891;
    }
    cout << answer;
    return 0;
}