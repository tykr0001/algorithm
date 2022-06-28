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
\*************  2022-06-22 11:30:14  *************/

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
using line = pair<pll, pll>;

int n, m, k;
int ans = 0;

vector<pll> a, b, query;


/** CCW(counter-clock-wise)
 *  @return  ccw=>1, cw=>-1, pararell=>0
 */
int CCW(const pll& a, const pll& b, const pll& c) {
    ll op = (a.fi * b.se + b.fi * c.se + c.fi * a.se) -
        (a.se * b.fi + b.se * c.fi + c.se * a.fi);
    if (op > 0) return 1;
    else if (op < 0) return -1;
    else return 0;
}

bool IsIn(vector<pll>& outer, pll p) {
    int size = outer.size();
    if (CCW(outer[0], outer[1], p) == -1 || CCW(outer[0], outer[size - 1], p) == 1) {
        return false;
    }

    int lo = 1;
    int hi = size - 1;
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        if (CCW(outer[0], outer[mid], p) == 1)
            lo = mid;
        else
            hi = mid;
    }
    return CCW(outer[lo], outer[lo + 1], p) == 1;
}

void Solve(void) {
    for (int i = 0; i < k; i++) {
        if (!IsIn(a, query[i]) || IsIn(b, query[i]))
            ans++;
    }
    if (ans == 0) cout << "YES";
    else cout << ans;
}

void Init(void) {
    cin >> n >> m >> k;
    resize(a, n);
    resize(b, m);
    resize(query, k);
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        a[i] = pll { x,y };
    }
    for (int i = 0; i < m; i++) {
        ll x, y; cin >> x >> y;
        b[i] = pll { x,y };
    }
    for (int i = 0; i < k; i++) {
        ll x, y; cin >> x >> y;
        query[i] = pll { x,y };
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}