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
\*************  2022-03-25 18:07:55  *************/

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

int v, e;
v2i scc;
v2i edge;
vi node_id;
vb searched;
stack<int> s;
int id;

int DFS(int node) {
    node_id[node] = ++id;
    int parent = node_id[node];
    s.push(node);

    for (auto next : edge[node]) {
        if (node_id[next] == 0)
            parent = min(parent, DFS(next));
        else if (!searched[next])
            parent = min(parent, node_id[next]);
    }

    if (parent == node_id[node]) {
        vi cycle;
        while (1) {
            int top = s.top();
            s.pop();
            cycle.push_back(top);
            searched[top] = true;
            if (top == node) break;
        }
        scc.push_back(cycle);
    }
    return parent;
}

void SCC(int n) {
    for (int i = 1; i <= n; i++) {
        if (node_id[i] == 0)
            DFS(i);
    }
}

void Solve(void) {
    SCC(v);

    cout << scc.size() << endl;

    for (auto& cycle : scc)
        sort(cycle);
    sort(scc);

    for (auto& cycle : scc) {
        for (auto& node : cycle)
            cout << node << " ";
        cout << -1 << endl;
    }
}

void Init(void) {
    cin >> v >> e;
    edge.resize(v + 1);
    node_id.resize(v + 1);
    searched.resize(v + 1);

    for (int i = 0; i < e; i++) {
        int from, to;
        cin >> from >> to;
        edge[from].push_back(to);
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}