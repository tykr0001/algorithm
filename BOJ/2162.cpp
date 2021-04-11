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
\*************  2021-04-04 13:28:54  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using vc = vector<char>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pair<int, int>>;
using vvpii = vector<vector<pair<int, int>>>;
using vpll = vector<pair<ll, ll>>;
using vvpll = vector<vector<pair<ll, ll>>>;
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fi first
#define se second
#define INF INT32_MAX
#define LINF INT64_MAX
#define endl '\n'
#define rep(i,beg,end) for(int i=beg; i<end; i++)
template<class T>
void sort(T& container) { sort(container.begin(), container.end()); }
template<class T, class U>
void sort(T& container, U cmp) { sort(container.begin(), container.end(), cmp); }
template<class T, class U>
istream& operator>>(istream& is, pair<T, U>& rhs) { is >> rhs.fi >> rhs.se; return is; }
template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& rhs) { os << rhs.fi << ' ' << rhs.se; return os; }
template<class T>
istream& operator>>(istream& is, vector<T>& rhs) { for (T& elem : rhs) is >> elem; return is; }
template<class T>
ostream& operator<<(ostream& os, const vector<T>& rhs) { for (T& elem : rhs) os << elem << ' '; os << endl; return os; }
/*************************************************/
using line = pair<pll, pll>;

int N;
int set_number;
int max_set_size;
vector<line> lines;
vi parent;
vi set_size;

int Find(int node) {
    if (parent[node] == node)
        return node;
    else
        return parent[node] = Find(parent[node]);
}

void Union(int a, int b) {
    parent[Find(b)] = Find(a);
}

int CCW(const pll& a, const pll& b, const pll& c) {
    ll op = (a.fi * b.se + b.fi * c.se + c.fi * a.se) -
        (a.se * b.fi + b.se * c.fi + c.se * a.fi);
    if (op > 0) return 1;
    else if (op < 0) return -1;
    else return 0;
}

bool IsIntersect(const line& x, const line& y) {
    pll a = x.fi;
    pll b = x.se;
    pll c = y.fi;
    pll d = y.se;
    int ab = CCW(a, b, c) * CCW(a, b, d);
    int cd = CCW(c, d, a) * CCW(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return a <= d && c <= b;
    }
    return ab <= 0 && cd <= 0;
}

void Solve(void) {
    rep(i, 0, N) {
        rep(j, i + 1, N) {
            if (IsIntersect(lines[i], lines[j])) {
                if (Find(i) == Find(j)) continue;
                set_size[Find(i)] += set_size[Find(j)];
                Union(i, j);
            }
        }
    }
    rep(i, 0, N) {
        if (Find(i) == i) {
            set_number++;
            max_set_size = max(max_set_size, set_size[Find(i)]);
        }
    }
    cout << set_number << endl << max_set_size << endl;
}

void Init(void) {
    cin >> N;
    lines.resize(N);
    cin >> lines;
    parent.resize(N);
    rep(i, 0, N)
        parent[i] = i;
    set_size.resize(N, 1);
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}