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
\*************  2022-04-02 12:51:53  *************/

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
v2i cache; // cache[idx][color] : 부모색이 color, idx를 root로 하는 subtree의 최소값
v2i edge;
vb visited;
v2i tree; // tree[parent] = {childs...}

void DFS(int root) {
    for (auto c : edge[root]) {
        if (!visited[c]) {
            visited[c] = true;
            tree[root].push_back(c);
            DFS(c);
        }
    }
}

int DP(int root, int color) {
    int& ret = cache[root][color];
    if (ret != 0) return ret;

    int min_val = 0;
    ret += color;
    // Top-down DP
    for (auto child : tree[root]) {
        min_val = INF;
        for (int i = 1; i < 20; i++) {
            if (i != color) {
                min_val = min(min_val, DP(child, i));
            }
        }
        ret += min_val;
    }
    return cache[root][color] = ret;
}

void Solve(void) {
    DFS(0);
    DP(0, 0);
    cout << cache[0][0];
}

void Init(void) {
    cin >> n;
    resize(edge, n + 1);
    resize(visited, n + 1);
    resize(cache, n + 1, 20);
    resize(tree, n + 1);
    for (int i = 0; i < n - 1; i++) {
        int src, dst;
        cin >> src >> dst;
        edge[src].push_back(dst);
        edge[dst].push_back(src);
    }
    edge[0].push_back(1);
    edge[1].push_back(0);
    visited[0] = true;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}