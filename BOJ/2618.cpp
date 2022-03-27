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
\*************  2022-03-26 09:06:18  *************/

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

int n, w;
vector<pii> arr;
v2i cache;
vi ans;

int dist(int a, int b) {
    return abs(arr[a].fi - arr[b].fi) + abs(arr[a].se - arr[b].se);
}


// bottom-up
int dp(int a, int b) {
    if (a == w + 2 || b == w + 2)
        return 0;
    int& ret = cache[a][b];
    if (ret != -1)
        return ret;

    int next = max(a, b) + 1;
    int d1 = dp(next, b) + dist(a, next);
    int d2 = dp(a, next) + dist(b, next);
    return ret = min(d1, d2);
}

void order(int a, int b) {
    if (a == w + 2 || b == w + 2)
        return;

    int next = max(a, b) + 1;
    int d1 = cache[next][b] + dist(a, next);
    int d2 = cache[a][next] + dist(b, next);

    if (d1 < d2) {
        ans.push_back(1);
        order(next, b);
    }
    else {
        ans.push_back(2);
        order(a, next);
    }
}

void Solve(void) {
    cout << dp(1, 2) << endl;
    order(1, 2);
    for (auto e : ans)
        cout << e << endl;
}

void Init(void) {
    cin >> n >> w;
    arr.resize(w + 3);
    cache = v2i(w + 3, vi(w + 3, -1));
    arr[1] = { 1, 1 };
    arr[2] = { n, n };
    for (int i = 3; i < w + 3; i++) {
        cin >> arr[i];
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}