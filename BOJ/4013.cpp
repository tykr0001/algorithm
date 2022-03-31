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
\*************  2022-03-31 18:59:51  *************/

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

int n, m;
int init, p;
int id;
vi node_id;
stack<int> s;
v2i edge;
vb searched;
v2i scc;
vi scc_idx;
v2i scc_edge;
vi cash;
vi scc_cash;
vi restaurant;
vi in_degree;
vi cache;
queue<int> q;

int DFS(int cur) {
    node_id[cur] = ++id;
    int parent = node_id[cur];
    s.push(cur);

    for (auto next : edge[cur]) {
        if (node_id[next] == 0)
            parent = min(parent, DFS(next));
        else if (!searched[next])
            parent = min(parent, node_id[next]);
    }

    if (parent == node_id[cur]) {
        vi cycle;
        while (1) {
            int top = s.top();
            s.pop();
            cycle.push_back(top);
            searched[top] = true;
            scc_idx[top] = scc.size();
            if (top == cur) break;
        }

        scc.push_back(cycle);
    }
    return parent;
}

void SCC(void) {
    for (int i = 1; i <= n; i++) {
        if (node_id[i] == 0)
            DFS(i);
    }
}

void TopologySort() {
    for (int i = 0; i < scc.size(); i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        scc_cash[scc_idx[i]] += cash[i];
    }

    cache[scc_idx[init]] = scc_cash[scc_idx[init]];

    bool flag = false;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == scc_idx[init]) {
            flag = true;
        }

        for (auto next : scc_edge[cur]) {
            in_degree[next]--;
            if (in_degree[next] == 0) {
                q.push(next);
            }
            if (flag) {
                cache[next] = max(cache[next], cache[cur] + scc_cash[next]);
            }
        }
    }
}

void Solve(void) {
    resize(node_id, n + 1);
    resize(searched, n + 1);
    resize(scc_idx, n + 1);

    SCC();

    resize(scc_edge, scc.size());
    resize(in_degree, scc.size());
    resize(scc_cash, scc.size());
    resize(cache, scc.size());

    for (int i = 1; i <= n; ++i) {
        for (auto next : edge[i]) {
            if (scc_idx[i] != scc_idx[next]) {
                scc_edge[scc_idx[i]].push_back(scc_idx[next]);
                in_degree[scc_idx[next]]++;
            }
        }
    }

    TopologySort();
    int ans = 0;
    for (int i = 0; i < p; i++) {
        ans = max(ans, cache[scc_idx[restaurant[i]]]);
    }

    cout << ans;
}

void Init(void) {
    cin >> n >> m;

    resize(edge, n + 1);
    resize(cash, n + 1);

    for (int i = 0; i < m; i++) {
        int src, dst;
        cin >> src >> dst;
        edge[src].push_back(dst);
    }
    for (int i = 1; i <= n; i++) {
        cin >> cash[i];
    }
    cin >> init >> p;

    resize(restaurant, p);
    for (int i = 0; i < p; i++) {
        cin >> restaurant[i];
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}