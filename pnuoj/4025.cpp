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
\*************  2022-03-29 05:02:34  *************/

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

ll MOD = 1e9 + 7;

int n, m;
vl a;
vl b;
vl p;
vl q;

vector<ull> a_exp(100001);
vector<ull> b_exp(100001);

vb is_prime;
vl prime;

ll Exp(ll x, ll e) {
    if (e == 0) return 1;
    if (e == 1) return x;
    ll ret = Exp(x, e / 2);
    if (e % 2)
        return ret * ret % MOD * x % MOD;
    else
        return ret * ret % MOD;
}

void Eratos() {
    is_prime = vb(100001, true);
    for (int i = 2; i <= sqrt(100000); i++) {
        if (is_prime[i]) {
            prime.emplace_back(i);
            for (int j = i * 2; j <= 100000; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void Solve(void) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; prime[j] <= a[i]; j++) {
            while (a[i] % prime[j] == 0) {
                a[i] /= prime[j];
                a_exp[prime[j]] += p[i];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; prime[j] <= b[i]; j++) {
            while (b[i] % prime[j] == 0) {
                b[i] /= prime[j];
                b_exp[prime[j]] += q[i];
            }
        }
    }

    ull ans = 1;
    for (int i = 0; i < prime.size(); i++) {
        ans = ans * Exp(prime[i], max(b_exp[prime[i]], a_exp[prime[i]])) % MOD;
    }
    cout << ans;
}

void Init(void) {
    Eratos();
    cin >> n >> m;
    resize(a, n);
    resize(p, n);
    resize(b, m);
    resize(q, m);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> p[i];
    for (int i = 0; i < m; i++)
        cin >> b[i] >> q[i];
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}