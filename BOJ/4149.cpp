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
\*************  2022-06-28 10:54:24  *************/

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

ull n;
vector<ull> ans;

//miller-rabin(밀러라빈)
ull Pow(__int128  x, __int128  y, __int128  mod) { // ret = (x^y)%mod
    __int128  ret = 1;
    x %= mod;
    while (y) {
        if (y & 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ret;
}

ull isPrime_MillerRabin(ull p) {
    ull a[] = { 2,3,61,LLONG_MAX,2,3,5,7,11,13,17,19,23,29,31,37,LLONG_MAX };	//LLONG_MAX is composite number
    ull i = p <= UINT_MAX ? 0 : 4;
    while (a[i] < p) {
        ull s = p - 1;
        while (true) {
            ull r = Pow(a[i], s, p);
            if (r == p - 1) break;	// p is probably a prime.
            if (s & 1) {	//if s is odd number
                if (r == 1) break;	// p is probably a prime.
                else return 0;	// s is composite
            }
            s >>= 1;
        }
        i++;
    }
    return p < 2 ? 0 : p != LLONG_MAX;
}


ull GCD(ull a, ull b) {
    if (a < b) swap(a, b);
    while (b != 0) {
        ull r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Pollard's-rho(폴라드로)
ull FindDiv(__int128  n) {
    if (n % 2 == 0) return 2;
    if (isPrime_MillerRabin(n)) return n;

    __int128  x = rand() % (n - 2) + 2, y = x, c = rand() % 10 + 1, g = 1;
    while (g == 1) {
        x = (x * x % n + c) % n;
        y = (y * y % n + c) % n;
        y = (y * y % n + c) % n;
        g = __gcd(abs(__int128(x - y)), n);
        if (g == n) return FindDiv(n);
    }
    if (isPrime_MillerRabin(g)) return g;
    else return FindDiv(g);
}

void Solve(void) {
    while (n > 1) {
        ull div = FindDiv(n);
        ans.emplace_back(div);
        n /= div;
    }
    sort(ans);
    for (auto e : ans) {
        cout << e << ' ';
    }
}

void Init(void) {
    cin >> n;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}