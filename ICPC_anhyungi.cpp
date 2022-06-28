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
using vd = vector<double>;
using v2d = vector<vd>;
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

// Fenwick-Tree(펜윅트리)  
struct Fenwick {
    ll n;
    vl arr;
    vl tree;

    Fenwick() { }
    Fenwick(int n) : n(n), arr(n + 1), tree(n + 1) { }

    ll Sum(int idx) {
        ll ret = 0;
        while (idx > 0) {
            ret += tree[idx];
            idx -= (idx & -idx);
        }
        return ret;
    }

    void Update(int idx, ll diff) {
        while (idx < n + 1) {
            tree[idx] += diff;
            idx += (idx & -idx);
        }
    }
} fen;

// 2D Fenwick-Tree(2차원 펜윅트리)
struct Fenwick2D {
    ll n;
    v2l arr;
    v2l tree;

    Fenwick2D() { }
    Fenwick2D(int n) : n(n), arr(n + 1, vl(n + 1)), tree(n + 1, vl(n + 1)) { }

    void Update(int x, int y, ll diff) {
        while (x < n + 1) {
            int tmp_y = y;
            while (tmp_y < n + 1) {
                tree[x][tmp_y] = tree[x][tmp_y] + diff;
                tmp_y = tmp_y + (tmp_y & -tmp_y);
            }
            x = x + (x & -x);
        }
    }

    // default Query is Sum
    ll Query(int x, int y) {
        ll ret = 0;
        while (x > 0) {
            int tmp_y = y;
            while (tmp_y < n + 1) {
                ret = ret + tree[x][tmp_y];
                tmp_y = tmp_y - (tmp_y & -tmp_y);
            }
            x = x - (x & -x);
        }
        return ret;
    }

} fen;

// FFT(Fast-Fourier-Transform, 고속 푸리에 변환)
typedef complex<double> base;
void FFT(vector<base>& a, bool inv = false) {
    int size = a.size();
    for (int i = 1, j = 0; i < size; i++) {
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

vl Multiply(vl& v, vl& w) {
    vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
    int size = 2; while (size < v.size() + w.size()) size <<= 1;
    fv.resize(size); fw.resize(size);
    FFT(fv, 0); FFT(fw, 0);
    for (int i = 0; i < size; i++) fv[i] *= fw[i];
    FFT(fv, 1);
    vl ret(size);
    for (int i = 0; i < size; i++) ret[i] = (ll)round(fv[i].real());
    return ret;
}

vl Multiply(vl& v, vl& w, ll mod) {
    int size = 2;
    while (size < v.size() + w.size()) size <<= 1;
    vector<base> v1(size), v2(size), r1(size), r2(size);
    for (int i = 0; i < v.size(); i++) {
        v1[i] = base(v[i] >> 15, v[i] & 32767);
    }
    for (int i = 0; i < w.size(); i++) {
        v2[i] = base(w[i] >> 15, v[i] & 32767);
    }
    FFT(v1, 0); FFT(v2, 0);
    for (int i = 0; i < size; i++) {
        int j = (i ? size - 1 : i);
        base ans1 = (v1[i] + conj(v1[j])) * base(0.5, 0);
        base ans2 = (v1[i] + conj(v1[j])) * base(0, -0.5);
        base ans3 = (v2[i] + conj(v2[j])) * base(0.5, 0);
        base ans4 = (v2[i] + conj(v2[j])) * base(0, -0.5);
        r1[i] = (ans1 * ans3) + (ans1 * ans4) * base(0, 1);
        r2[i] = (ans2 * ans3) + (ans2 * ans4) * base(0, 1);
    }
    FFT(r1, 1); FFT(r2, 1);
    vl ret(size);
    for (int i = 0; i < size; i++) {
        ll av = (ll)round(r1[i].real());
        ll bv = (ll)round(r1[i].imag()) + (ll)round(r2[i].real());
        ll cv = (ll)round(r2[i].imag());
        av %= mod; bv %= mod; cv %= mod;
        ret[i] = (av << 30) + (bv << 15) + cv;
        ret[i] = (ret[i] % mod + mod) % mod;
    }
    return ret;
}

// Miller-Rabin(밀러 라빈 소수 판별법)
// int범위와 long long범위에 따라 base prime 다르게 사용
ull Pow(ull x, ull y, ull mod = 1) { // return (x ^ y) % mod
    ull ret = 1;
    x %= mod;
    while (y) {
        if (y & 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ret;
}

bool isPrime_MillerRabin(ull p) {
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

// Pollard's-rho(폴라드로)
// 곱셈연산중 ull 범위를 벗어날 경우 __int128 사용 
// return smallest divisor
ull FindDiv(ll n) {
    if (n % 2 == 0) return 2;
    if (isPrime_MillerRabin(n)) return n;

    ll x = rand() % (n - 2) + 2, y = x, c = rand() % 10 + 1, g = 1;
    while (g == 1) {
        x = (x * x % n + c) % n;
        y = (y * y % n + c) % n;
        y = (y * y % n + c) % n;
        g = __gcd(abs(ll(x - y)), n);
        if (g == n) return FindDiv(n);
    }
    if (isPrime_MillerRabin(g)) return g;
    else return FindDiv(g);
}

// EEA(Extended-Euclidean-Algorithm, 확장 유클리드 알고리즘)
// a * s + b * t = gcd(a, b)
// return multiplicative inverse of b (modulo a) if it exists, else 0
ll EEA(ll a, ll b) {
	ll r1 = a, r2 = b, s1 = 1, s2 = 0, t1 = 0, t2 = 1;
	ll r, s, t, q;
	while (r2) {
		q = r1 / r2;
		// gcd 계산
		r = r1 % r2;
		r1 = r2, r2 = r;

		// s 계산
		s = s1 - q * s2;
		s1 = s2, s2 = s;

		// t 계산
		t = t1 - q * t2;
		t1 = t2, t2 = t;
	}
	r = r1, s = s1, t = t1;

	if (r == 1) 
		return (t + a) % a;
	else 
        return 0;
}

// CRT(Chinese-Remainder-Theorem, 중국인 나머지 정리)
// return smallest solution
ll Inv(ll x, ll mod) {
    return Pow(x, mod-2);
}

ll MinCRT(vl& m, vl& a) {
    int size = a.size();
    ll M = 1;
    ll ret = 0;
    for(int i=0; i<size; i++)
        M *= m[i];
    for(int i=0; i<size; i++) {
        ll M_i = M / m[i];
        ret += a[i] * M_i * Inv(M_i, m[i]);
    }

    return ret & M;
}

// Gauss-Jordan Elimination(가우스 소거법)
// return inverse matrix
v2d GaussElimination(v2d mat) {
    int size = mat.size();
    v2d ret(size, vd(size));
    for (int i = 0; i < size; i++)
        ret[i][i] = 1;

    for (int i = 0; i < size; i++) {
        double tmp = mat[i][i];
        for (int j = 0; j < size; j++) {
            mat[i][j] /= tmp;
            ret[i][j] /= tmp;
        }

        for (int j = 1; j < size; j++) {
            double a = -mat[(i + j) % size][i] / mat[i][i];

            for (int k = 0; k < size; k++) {
                mat[(i + j) % size][k] += a * mat[i][k];
                ret[(i + j) % size][k] += a * ret[i][k];
            }
        }
    }

    return ret;
}