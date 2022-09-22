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
\*************  2022-09-20 17:26:30  *************/

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

int n;
pll init;
vector<pll> pos;
vector<pll> hull;

using line = pair<pll, pll>;
/** CCW(counter-clock-wise)
 *  @return  ccw=>1, cw=>-1, pararell=>0
 */
int CCW(pll a, pll b, pll c) {
    ll op = (a.fi * b.se + b.fi * c.se + c.fi * a.se) -
        (a.se * b.fi + b.se * c.fi + c.se * a.fi);
    if (op > 0) return 1;
    else if (op < 0) return -1;
    else return 0;
}

int CCW(pll a, pll b, pll c, pll d) {
    d.fi -= (c.fi - b.fi);
    d.se -= (c.se - b.se);
    return CCW(a, b, d);
}

ll Dist(pll a, pll b) {
    return (a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se);
}

bool Cmp(pll a, pll b) {
    if (a.se * b.fi != b.se * a.fi) return a.se * b.fi < b.se* a.fi;
    return a.fi * a.fi + a.se * a.se < b.fi* b.fi + b.se * b.se;
}

void Solve(void) {
    hull.clear();
    vector<int> s;
    int next = 0;
    while (next < n) {
        while (s.size() >= 2) {
            int cur = s.back();
            s.pop_back();
            int prev = s.back();
            if (CCW(pos[prev], pos[cur], pos[next]) > 0) {
                s.emplace_back(cur);
                break;
            }
        }
        s.emplace_back(next++);
    }
    n = s.size();
    hull.reserve(n);
    for (auto e : s)
        hull.emplace_back(pos[e]);

    pll ans_1 = hull[0];
    pll ans_2 = hull[1];

    ll dist = Dist(hull[0], hull[1]);

    for (int i = 0, j = 1; i < n; i++) {
        while (CCW(hull[i], hull[i + 1], hull[j % n], hull[(j + 1) % n]) == 1) {
            if (dist < Dist(hull[i], hull[j % n])) {
                dist = Dist(hull[i], hull[j % n]);
                ans_1 = hull[i];
                ans_2 = hull[j];
            }
            j++;

        }
        if (dist < Dist(hull[i], hull[j % n])) {
            dist = Dist(hull[i], hull[j % n]);
            ans_1 = hull[i];
            ans_2 = hull[j];
        }
    }
    cout << ans_1.fi + init.fi << ' ' << ans_1.se + init.se << ' ' << ans_2.fi + init.fi << ' ' << ans_2.se + init.se << endl;
}

void Init(void) {
    cin >> n;
    pos.clear();
    pos.resize(n);
    cin >> pos;
    sort(pos);
    init = pos[0];
    for (auto& p : pos) {
        p.fi -= init.fi;
        p.se -= init.se;
    }
    sort(pos.begin(), pos.end(), Cmp);
}

int main(void) {
    Boost;
    int t; cin >> t;
    while (t--) {
        Init();
        Solve();
    }
    return 0;
}