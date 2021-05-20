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
\*************  2021-05-13 16:46:10  *************/

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
using vvs = vector<vector<string>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
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

int N, M, Q;
vi cut;
vpii adj;
vi parent;
vl A;
stack<int> s;

int Find(int n) {
    if (parent[n] == n) return n;
    else return parent[n] = Find(parent[n]);
}

void Union(int p, int c) {
    parent[Find(c)] = Find(p);
}

void Solve(void) {
    ll ans = 0;
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        if (Find(adj[top].fi) != Find(adj[top].se)) {
            ans += A[Find(adj[top].fi)] * A[Find(adj[top].se)];
            A[Find(adj[top].fi)] += A[Find(adj[top].se)];
            A[Find(adj[top].se)] = 0;
            Union(adj[top].fi, adj[top].se);
        }
    }
    cout << ans;
}

void Init(void) {
    cin >> N >> M >> Q;
    cut.resize(M + 1);
    adj.resize(M + 1);
    parent.resize(N + 1);
    A.resize(N + 1, 1);
    for (int i = 1; i <= M; i++) {
        int X, Y;
        cin >> X >> Y;
        adj[i] = pii(X, Y);
    }

    while (Q--) {
        int inp; cin >> inp;
        cut[inp] = true;
        s.emplace(inp);
    }

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 1; i <= M; i++) {
        if (!cut[i] && Find(adj[i].fi) != Find(adj[i].se)) {
            A[Find(adj[i].fi)] += A[Find(adj[i].se)];
            A[Find(adj[i].se)] = 0;
            Union(adj[i].fi, adj[i].se);
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}