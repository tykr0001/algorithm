#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<LL> a(n1);
    vector<LL> b(n2);
    vector<LL> c(n3);
    vector<LL> sum(3, 0);

    for (int i = 0; i < n1; i++) {
        int inp;
        cin >> inp;
        a[i] = inp;
        sum[0] += inp;
    }
    for (int i = 0; i < n2; i++) {
        int inp;
        cin >> inp;
        b[i] = inp;
        sum[1] += inp;
    }
    for (int i = 0; i < n3; i++) {
        int inp;
        cin >> inp;
        c[i] = inp;
        sum[2] += inp;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    LL tmp;
    if (a[0] >= b[0] && a[0] >= c[0])
        tmp = sum[0] + sum[1] + sum[2] - 2 * b[0] - 2 * c[0];
    else if (b[0] >= a[0] && b[0] >= c[0])
        tmp = sum[0] + sum[1] + sum[2] - 2 * a[0] - 2 * c[0];
    else if (c[0] >= a[0] && c[0] >= b[0])
        tmp = sum[0] + sum[1] + sum[2] - 2 * a[0] - 2 * b[0];

    tmp = max(tmp, sum[0] + sum[1] - sum[2]);
    tmp = max(tmp, sum[0] - sum[1] + sum[2]);
    tmp = max(tmp, -sum[0] + sum[1] + sum[2]);
    cout << tmp << endl;
    return 0;
}