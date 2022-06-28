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
\*************  2022-06-24 11:27:54  *************/

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

const ll MOD = 1e9 + 7;

int n;
vs str;
vi nc; // 1:n 2:c 3:nc 4:cn
vi cnt;
vl facto;

ll Pow(ll x, ll n) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

ll Inv(ll a) {
    return Pow(a, MOD - 2);
}

ll nPr(ll n, ll r) {
    return facto[n] * Inv(facto[n - r]) % MOD;
}

void Solve(void) {
    ll all = 0;
    for (int i = 1; i <= n; i++) {
        all += nPr(n, i);
        all %= MOD;
    }
    ll c_perm = 0;
    for (int i = 0; i <= cnt[2]; i++) {
        c_perm += nPr(cnt[2], i);
        c_perm %= MOD;
    }
    ll n_perm = 0;
    for (int i = 0; i <= cnt[1]; i++) {
        n_perm += nPr(cnt[1], i);
        n_perm %= MOD;
    }
    ll ans = all - (c_perm * (cnt[4] + 1) % MOD * n_perm % MOD - 1);
    while (ans < 0) ans += MOD;
    // cout << all << ' ' << c_perm << ' ' << cnt[4] + 1 << ' ' << n_perm << endl;
    cout << ans % MOD;
}

void Init(void) {
    cin >> n;
    resize(str, n);
    resize(nc, n);
    resize(cnt, 5);
    for (int i = 0; i < n; i++) {
        string inp; cin >> inp;
        for (int j = 0; j < inp.size(); j++) {
            // 1:n 2:c 3:nc 4:cn
            if (inp[j] == 'N' && (nc[i] == 2 || nc[i] == 4)) nc[i] = 4;
            else if (inp[j] == 'N' && nc[i] == 3) nc[i] = 3;
            else if (inp[j] == 'N') nc[i] = 1;
            else if (inp[j] == 'C' && (nc[i] == 1 || nc[i] == 3 || nc[i] == 4)) nc[i] = 3;
            else if (inp[j] == 'C') nc[i] = 2;
        }
        cnt[nc[i]]++;
    }
    resize(facto, n + 1);
    facto[0] = 1;
    facto[1] = 1;
    for (int i = 1; i < n; i++) {
        facto[i + 1] = facto[i] * (i + 1) % MOD;
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}