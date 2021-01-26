#include <bits/stdc++.h>

using namespace std;

int cache[11];

int DP(int n) {
    if (cache[n]) {
        return cache[n];
    }
    if (n < 0) {
        return 0;
    }
    return cache[n] = DP(n - 1) + DP(n - 2) + DP(n - 3);
}

int main(void) {
    int T;
    cin >> T;
    cache[0] = cache[1] = 1;
    DP(10);
    while (T--) {
        int n;
        cin >> n;
        cout << cache[n] << endl;
    }
}