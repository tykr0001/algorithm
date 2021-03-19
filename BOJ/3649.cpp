#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long int ll;

int x, n;
vector<int> l;

void Solve() {
    int lo = 0;
    int hi = n - 1;
    while (lo < hi) {
        int sum = l[lo] + l[hi];
        if (sum < x) {
            lo++;
        }
        else if (sum > x) {
            hi--;
        }
        else {
            cout << "yes" << ' ' << l[lo] << ' ' << l[hi] << endl;
            return;
        }
    }
    cout << "danger" << endl;
}

void Init() {
    cin >> n;
    x *= 1e7;
    l.clear();
    l.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    sort(l.begin(), l.end());
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (cin >> x) {
        Init();
        Solve();
    }
    return 0;
}