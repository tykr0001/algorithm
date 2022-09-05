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
\*************  2022-07-27 17:07:34  *************/

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

ull t, n, m;
vector<ull> arr;

vector<bool> is_prime;
vector<ull> prime;
void Eratos(int m) {
    is_prime = vector<bool>(1000001, true);
    for (int i = 2; i * i < is_prime.size(); i++) {
        if (is_prime[i]) {
            prime.emplace_back(i);
            for (int j = i * 2; j < is_prime.size(); j += i) {
                is_prime[j] = false;
            }
        }
    }
}

ull Phi(ll a) {
    ull ret = a;
    ull i = 0;
    while (i < prime.size() && prime[i] * prime[i] <= a) {
        if (!(a % prime[i])) ret = ret / prime[i] * (prime[i] - 1);
        while (!(a % prime[i])) a /= prime[i];
        i++;
    }
    if (a > 1) ret = ret / a * (a - 1);

    return ret;
}

ull Pow(ull x, ull y, ull mod) { // return (x ^ y) % mod
    ull ret = 1;
    x %= mod;
    while (y) {
        if (y & 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }

    return ret;
}

ull Pow(ull x, ull y) { // return (x ^ y)
    ull ret = 1;
    while (y) {
        if (y & 1) ret = (ret * x);
        x = (x * x);
        y >>= 1;
    }

    return ret;
}

ull PowWithCap(ull x, ull y) {
    if (x == 1 || y == 0) return 1;
    if (x >= 2 && y >= 7) return 100;
    if (x >= 3 && y >= 5) return 100;
    if (x >= 4 && y >= 4) return 100;
    if (x >= 5 && y >= 3) return 100;
    if (x >= 10 && y >= 2) return 100;
    if (x >= 100 && y >= 1) return 100;
    return Pow(x, y);
}

ull CheckBig(ull idx) {
    if (n - idx >= 4) return 100;
    if (idx == n - 1) return arr[idx];
    ull ret = PowWithCap(arr[n - 2], arr[n - 1]);
    for (int i = n - 3; i >= idx; i--)
        ret = PowWithCap(arr[i], ret);
    return ret;
}

ull f(ull idx, ull m) {
    if (m == 1) return 0;
    if (idx == n - 1) return arr[n - 1] % m;

    ull div = __gcd(arr[idx], m);
    ull phi = Phi(m);
    ull tmp = f(idx + 1, phi);
    ull val = CheckBig(idx + 1);
    if (div == 1) return Pow(arr[idx], tmp, m);
    if (val >= 100)
        return Pow(arr[idx], tmp % phi + phi, m);
    else
        return Pow(arr[idx], val, m);
}

void Solve(void) {
    cout << f(0, m) << endl;
}

void Init(void) {
    cin >> n;
    arr.clear();
    arr.resize(n);
    cin >> arr;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 1) {
            n = i;
            break;
        }
    }
}

int main(void) {
    Boost;
    cin >> t >> m;
    Eratos(m);
    while (t--) {
        Init();
        Solve();
    }
    return 0;
}