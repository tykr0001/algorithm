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
\*************  2021-11-06 00:54:03  *************/

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

int n;
int m;
vl ten_pow;
v2l cache;
vector<string> arr;

ll Mod(const string& str) {
    ll ret = 0;
    if (str.length() <= 18) return stoll(str) % m;
    return ((stoll(str.substr(0, str.length() - 18)) % m) *
        (ll(1e18) % m) +
        Mod(str.substr(str.length() - 18))) % m;
}

ll DP(int i, int j) {
    if (i == (1 << n) - 1) return j == 0;
    if (cache[i][j] != -1) return cache[i][j];
    int ret = 0;
    for (int k = 0; k < n; k++) {
        if (i & (1 << k)) continue;
        ret += DP(i | (1 << k), Mod(to_string(j) + arr[k]));
    }
    return cache[i][j] = ret;
}

void Solve(void) {
    ll p, q;

    ten_pow = vl(51);
    ten_pow[0] = 1 % m;
    for (int i = 1; i < 51; i++) {
        ten_pow[i] = (ten_pow[i - 1] * 10) % m;
    }

    cache = v2l(1 << n, vl(m, -1));
    p = DP(0, 0);
    q = 1;
    for (int i = 1; i <= n; i++) {
        q *= i;
    }
    ll gcd = __gcd(p, q);
    p /= gcd;
    q /= gcd;
    cout << p << '/' << q;
}

void Init(void) {
    cin >> n;
    resize(arr, n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> m;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}