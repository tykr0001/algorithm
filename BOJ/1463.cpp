#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;

int DP(int i) {
    if (v[i] != INT32_MAX) {
        return v[i];
    }
    if (i % 3 == 0 && i % 2 == 0)
        v[i] = min(v[i], min(DP(i / 3), min(DP(i / 2), DP(i - 1))) + 1);
    if (i % 3 == 0 && i % 2 != 0)
        v[i] = min(v[i], min(DP(i / 3), DP(i - 1)) + 1);
    if (i % 3 != 0 && i % 2 == 0)
        v[i] = min(v[i], min(DP(i / 2), DP(i - 1)) + 1);
    if (i % 3 != 0 && i % 2 != 0)
        v[i] = min(v[i], DP(i - 1) + 1);
    return v[i];
}

int main(void) {
    cin >> N;
    v.resize(N + 1, INT32_MAX);
    v[1] = 0;
    cout << DP(N) << endl;
}