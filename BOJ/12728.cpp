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
\*************  2022-09-21 13:16:58  *************/

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

ll idx, t;
ll n;
v2l mat;

// Matrix Multiply(행렬 곱)
v2l Mul(v2l& a, v2l& b) {
    int size = a.size();
    v2l ret(size, vl(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                ret[i][j] += a[i][k] * b[k][j];
            }
            ret[i][j] %= 1000;
        }
    }
    return ret;
}
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

// Matrix Power(행렬 거듭제곱)
v2l Pow(v2l a, int x) {
    if (x == 1) return a;
    v2l ret = { {1,0}, {0,1} };
    while (x) {
        if (x & 1) ret = Mul(ret, a);
        a = Mul(a, a);
        x >>= 1;
    }
    return ret;
}

void Solve(void) {
    v2l res = Pow(mat, n - 1);
    int ans = ((28 * res[1][0] + 6 * res[1][1] - 1) % 1000 + 1000) % 1000;
    string str_ans = to_string(ans);
    cout << "Case #" << t << ": ";
    while (str_ans.size() < 3)
        str_ans = "0" + str_ans;
    cout << str_ans << endl;
}

void Init(void) {
    cin >> n;
    mat = { {6,-4}, {1, 0} };
}

int main(void) {
    Boost;
    cin >> idx;
    for (t = 1; t <= idx; t++) {
        Init();
        Solve();
    }
    return 0;
}