#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

struct Fenwick {
    vector<ll> arr;
    vector<ll> tree;

    Fenwick() { }
    Fenwick(int n) : arr(n + 1), tree(n + 1) { }

    ll Sum(int idx) {
        ll ret = 0;
        while (idx > 0) {
            ret += tree[idx];
            idx -= (idx & -idx);
        }
        return ret;
    }

    void Update(int idx, ll diff) {
        while (idx < tree.size()) {
            tree[idx] += diff;
            idx += (idx & -idx);
        }
    }
} fen;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        fen = Fenwick(n + m);
        for (int i = 1; i <= n; i++) {
            fen.Update(i + m, 1);
            fen.arr[i] = i + m;
        }
        int top = m + 1;
        for (int i = 0; i < m; i++) {
            int idx;
            cin >> idx;
            cout << fen.Sum(fen.arr[idx] - 1) << ' ';
            fen.Update(fen.arr[idx], -1);
            fen.arr[idx] = --top;
            fen.Update(fen.arr[idx], 1);
        }
        cout << endl;
    }
    return 0;
}