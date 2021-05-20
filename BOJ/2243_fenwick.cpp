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

    const int MAX = 1000000;
    fen = Fenwick(MAX);
    int n;
    cin >> n;
    while (n--) {
        int A;
        cin >> A;
        if (A == 1) {
            int priority;
            cin >> priority;
            int lo = 1;
            int hi = MAX;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                int mid_priority = fen.Sum(mid);
                if (mid_priority < priority)
                    lo = mid + 1;
                else
                    hi = mid;
            }
            fen.Update(lo, -1);
            cout << lo << endl;
        }
        else {
            int tasty, num;
            cin >> tasty >> num;
            fen.Update(tasty, num);
        }
    }
    return 0;
}