#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

typedef long long LL;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N, D;
        cin >> N >> D;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (a.back() <= D) {
            cout << "YES" << '\n';
        }
        else if (a[0] + a[1] <= D) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}