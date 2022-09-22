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
\*************  2022-09-22 16:32:45  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using v2i = vector<vi>;
using v3i = vector<v2i>;
using vb = vector<bool>;
using v2b = vector<vb>;
using vs = vector<string>;
using v2s = vector<vs>;
using vc = vector<char>;
using v2c = vector<vc>;
using vl = vector<ll>;
using v2l = vector<vl>;
using v3l = vector<v2l>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define rep(i,beg,end) for(int i=beg; i<end; i++)
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
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

int n;
ll ans;

struct Data {
    ll lmax;
    ll rmax;
    ll mmax;
    ll sum;
};

vector<pair<pll, ll>> arr;
vector<Data> tree;

void Update(int idx, ll val, int node, int start, int end) {
    if (idx < start || end < idx) return;
    if (start == end) {
        tree[node].sum += val;
        tree[node].lmax = tree[node].rmax = tree[node].mmax = tree[node].sum;
        return;
    }
    int mid = (start + end) / 2;
    Update(idx, val, node * 2, start, mid);
    Update(idx, val, node * 2 + 1, mid + 1, end);

    tree[node].lmax = max(tree[node * 2].lmax, tree[node * 2].sum + tree[node * 2 + 1].lmax);
    tree[node].rmax = max(tree[node * 2 + 1].rmax, tree[node * 2].rmax + tree[node * 2 + 1].sum);
    tree[node].mmax = max({ tree[node * 2].mmax,tree[node * 2 + 1].mmax, tree[node * 2].rmax + tree[node * 2 + 1].lmax });
    tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
}

void Solve(void) {
    tree.resize(4 * n + 4);
    for (int i = 0; i < n; i++) {
        if (i && arr[i - 1].fi.fi == arr[i].fi.fi) continue;
        for (int j = 0; j < 4 * n + 4; j++)
            tree[j] = { 0,0,0,0 };
        for (int j = i; j < n; j++) {
            Update(arr[j].fi.se, arr[j].se, 1, 0, n - 1);
            if (j == n - 1 || arr[j].fi.fi != arr[j + 1].fi.fi)
                ans = max(ans, tree[1].mmax);
        }
    }
    cout << ans << endl;
}

void Init(void) {
    cin >> n;
    arr.resize(n);
    cin >> arr;
    sort(arr.begin(), arr.end(), [ ](auto& a, auto& b) {return a.fi.fi < b.fi.fi; });
    ll prev = arr[0].fi.fi;
    int cnt = 0;
    arr[0].fi.fi = 0;
    for (int i = 1; i < n; i++) {
        ll cur = arr[i].fi.fi;
        if (prev == cur) arr[i].fi.fi = cnt;
        else arr[i].fi.fi = ++cnt;
        prev = cur;
    }

    sort(arr.begin(), arr.end(), [ ](auto& a, auto& b) {return a.fi.se < b.fi.se; });
    prev = arr[0].fi.se;
    cnt = 0;
    arr[0].fi.se = 0;
    for (int i = 1; i < n; i++) {
        ll cur = arr[i].fi.se;
        if (prev == cur) arr[i].fi.se = cnt;
        else arr[i].fi.se = ++cnt;
        prev = cur;
    }

    sort(arr);
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}