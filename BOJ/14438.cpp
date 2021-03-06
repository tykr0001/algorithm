/********* github.com/tykr0001/algorithm *********\
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*
*$*                                             *$*
*$*    ||||||||  ||    ||  ||   |||  |||||||    *$*
*$*       ||      ||  ||   || |||    ||    ||   *$*
*$*       ||        ||     |||       |||||||    *$*
*$*       ||        ||     || |||    ||  ||     *$*
*$*       ||        ||     ||   |||  ||   |||   *$*
*$*                                             *$*
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*
\*************  2021-05-19 02:06:18  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pair<int, int>>;
using vvpii = vector<vector<pair<int, int>>>;
using vpll = vector<pair<ll, ll>>;
using vvpll = vector<vector<pair<ll, ll>>>;
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fi first
#define se second
#define INF INT32_MAX
#define LINF INT64_MAX
#define endl '\n'
#define rep(i,beg,end) for(int i=beg; i<end; i++)
template<class T>
void sort(T& container) { sort(container.begin(), container.end()); }
template<class T1, typename T2>
void sort(T1& container, T2 cmp) { sort(container.begin(), container.end(), cmp); }
template<class T1, class T2>
istream& operator>>(istream& is, pair<T1, T2>& rhs) { is >> rhs.fi >> rhs.se; return is; }
template<class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& rhs) { os << rhs.fi << ' ' << rhs.se; return os; }
template<class T>
istream& operator>>(istream& is, vector<T>& rhs) { for (T& elem : rhs) is >> elem; return is; }
template<class T>
ostream& operator<<(ostream& os, const vector<T>& rhs) { for (const T& elem : rhs) os << elem << ' '; os << endl; return os; }
template<class T>
void resize(T& container, int _size) { container.resize(_size); }
template<class T, typename... Size>
void resize(T& container, int _size, Size... _sizes) { container.resize(_size); for (auto& elem : container) resize(elem, _sizes...); }
/*************************************************/

int N, M;

struct Fenwick {
    ll n;
    vl arr;
    vl tree;
    vl bit1;
    vl bit2;

    Fenwick() { }
    Fenwick(int n) : n(n), arr(n + 1), tree(n + 1), bit1(n + 1), bit2(n + 1) { }

    ll Min(int a, int b) {
        ll ret = LINF;
        ll idx = a;
        while (idx + (idx & -idx) <= b) {
            ret = min(ret, bit2[idx]);
            idx += (idx & -idx);
        }
        if (idx <= b) ret = min(ret, arr[idx]);

        idx = b;
        while (idx - (idx & -idx) >= a) {
            ret = min(ret, bit1[idx]);
            idx -= (idx & -idx);
        }
        if (idx >= a) ret = min(ret, arr[idx]);
        return ret;
    };

    void MinUpdate(int idx, ll val) {
        if (arr[idx] == val) return;

        ll l, r;
        ll li, ri;
        ll lmin, rmin;

        #define SIDES_INIT {        \
            li = idx - 1;        \
            lmin = INT64_MAX;         \
            ri = idx + 1;        \
            rmin = INT64_MAX;         \
        }

        #define SIDES_UPDATE {                  \
            while (li > 0 && li - (li & -li) + 1 >= l) {    \
                lmin = min(lmin, bit1[li]);     \
                li -= (li & -li);                        \
            }                                   \
            if (li >= l) lmin = min(lmin, arr[li]);        \
            while (ri <= n && ri + (ri & - ri) - 1 <= r) {    \
                rmin = min(rmin, bit2[ri]);     \
                ri += (ri & - ri);                        \
            }                                   \
            if (ri <= min(n, r)) rmin = min(rmin, arr[ri]);        \
        }

        r = idx;
        l = r - (r & -r) + 1;
        SIDES_INIT;
        while (r <= n) {
            if (val <= bit1[r]) {
                bit1[r] = val;
            }
            else if (bit1[r] == arr[idx]) {
                SIDES_UPDATE;
                bit1[r] = min(val, min(lmin, rmin));
            }
            r = r + (r & -r);
            l = r - (r & -r) + 1;
        }
        l = idx;
        r = l + (l & -l) - 1;
        SIDES_INIT;
        while (l > 0) {
            if (val <= bit2[l]) {
                bit2[l] = val;
            }
            else if (bit2[l] == arr[idx]) {
                SIDES_UPDATE;
                bit2[l] = min(val, min(lmin, rmin));
            }
            l = l - (l & -l);
            r = l + (l & -l) - 1;
        }
        arr[idx] = val;
    }
} fen;

void Solve(void) {
    while (M--) {
        ll n, i, j;
        cin >> n >> i >> j;
        if (n == 1) {
            fen.MinUpdate(i, j);
        }
        else {
            cout << fen.Min(i, j) << endl;
        }
    }
}

void Init(void) {
    cin >> N;
    fen = Fenwick(N);
    for (int i = 1; i <= N; i++) {
        int inp; cin >> inp;
        fen.MinUpdate(i, inp);
    }
    cin >> M;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}