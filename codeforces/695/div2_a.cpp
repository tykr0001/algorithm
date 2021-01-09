#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        LL n;
        int counter = 9;
        int flag = 1;
        cin >> n;
        if (n == 1) {
            cout << 9 << '\n';
            continue;
        }
        if (n == 2) {
            cout << 98 << '\n';
            continue;
        }
        if (n >= 3) {
            cout << 989;
            for (LL i = 0; i < n - 3; i++) {
                cout << i % 10;
            }
        }
        cout << '\n';
    }

    return 0;
}