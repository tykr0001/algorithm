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
\*************  2021-12-02 18:20:37  *************/

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

vi parent;
vector<pii> dot;
vector<pair<double, pii>> graph;
int n, m;

int Find(int c) {
    if (parent[c] == 0 || parent[c] == c) return parent[c] = c;
    return parent[c] = Find(parent[c]);
}

void Union(int p, int c) {
    parent[Find(c)] = Find(p);
}

double Dist(pii& a, pii& b) {
    return sqrt(pow(a.fi - b.fi, 2) + pow(a.se - b.se, 2));
}

void Solve(void) {
    double ans = 0.0;
    graph.reserve(n * n);
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            graph.emplace_back(Dist(dot[i], dot[j]), pii { i, j });
        }
    }
    sort(graph);
    for (auto& edge : graph) {
        double dist = edge.fi;
        auto [a, b] = edge.se;
        if (Find(a) != Find(b)) {
            Union(a, b);
            ans += dist;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
}

void Init(void) {
    cin >> n >> m;
    dot.resize(n + 1);
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        dot[i] = { x, y };
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (Find(a) != Find(b)) {
            Union(a, b);
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}