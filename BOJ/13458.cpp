#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int b, c;
    cin >> b >> c;

    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum++;
        a[i] -= b;
        if (a[i] > 0) {
            sum += a[i] / c;
            if (a[i] % c != 0) {
                sum++;
            }
        }
    }

    cout << sum;
}