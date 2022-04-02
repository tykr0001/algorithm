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
\*************  2022-04-02 22:04:09  *************/

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

ll n, l;
vl arr;
ull ans;
ull MOD = 998244353;

ull Exp(int x, int y) {
    if (x == 0) return 0;
    if (y == 0) return 1;
    ll ret = Exp(x, y / 2);
    if (y % 2) return ret * ret % MOD * x % MOD;
    return ret * ret % MOD;
}

void Solve(void) {
    ll ans_flag = 0;
    for (int i = 0; i < n; i++) {
        ll include = arr[i] & ans_flag;
        ll not_include = include ^ arr[i];
        ans_flag |= arr[i];

        ll ni_cnt = 0;
        ll i_cnt = 0;

        while (not_include) {
            if (not_include & 1) ni_cnt++;
            not_include = not_include >> 1;
        }
        while (include) {
            if (include & 1) i_cnt++;
            include = include >> 1;
        }
        ans += MOD + Exp(ni_cnt + i_cnt, l) - Exp(i_cnt, l);
        ans = ans % MOD;
    }
    cout << ans % MOD;
}

void Init(void) {
    cin >> n >> l;
    resize(arr, n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (auto c : s) {
            arr[i] |= 1 << (c - 'a');
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}