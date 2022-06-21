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
\*************  2022-06-21 14:29:51  *************/

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
vl cache;
vl tmp;

typedef complex<double> base;
void FFT(vector<base>& a, bool inv = false) {
    int size = a.size(), j = 0;
    for (int i = 1; i < size; i++) {
        int bit = (size >> 1);
        while (j >= bit) {
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int i = 2; i <= size; i <<= 1) {
        double ang = 2 * acos(-1) / i * (inv ? -1 : 1);
        base wlen(cos(ang), sin(ang));
        for (int j = 0; j < size; j += i) {
            base w(1);
            for (int k = 0; k < i / 2; k++) {
                base u = a[j + k], v = a[j + k + i / 2] * w;
                a[j + k] = u + v;
                a[j + k + i / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (inv) for (int i = 0; i < size; i++) a[i] /= size;
}

void Multiply(vl& v, vl& w, vl& ret) {
    vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
    int size = 2; while (size < v.size() + w.size()) size <<= 1;
    fv.resize(size); fw.resize(size);
    FFT(fv, 0); FFT(fw, 0);
    for (int i = 0; i < size; i++) fv[i] *= fw[i];
    FFT(fv, 1);
    resize(ret, size);
    for (int i = 0; i < size; i++) ret[i] = (ll)round(fv[i].real());
    return;
}

void Solve(void) {
    vl ret;
    Multiply(cache, tmp, ret);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cache[i] * ret[i + n];
        ans += cache[i] * cache[(2 * i) % n]; // a==b
    }
    cout << ans / 2;
}

void Init(void) {
    cin >> n;
    resize(cache, 2 * n);
    resize(tmp, n);
    for (ll i = 1; i < n; i++) {
        cache[i * i % n]++;
        cache[i * i % n + n]++;
        tmp[i * i % n]++;
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}