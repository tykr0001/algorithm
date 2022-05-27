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
\*************  2021-10-08 15:04:13  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using v2i = vector<vi>;
using v3i = vector<v2i>;
using vb = vector<bool>;
using v2b = vector<vector<bool>>;
using v3b = vector<v2b>;
using vl = vector<ll>;
using v2l = vector<vl>;
using v3l = vector<v2l>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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

int N;
int M;
v2i adj;
vi init;

typedef struct {
    int idx;
    int depth;
} Node;

void Solve(void) {
    // BFS
    queue<Node> q;
    vi neigh(N + 1, 0);
    vi ans(N + 1, -1);

    for (int i = 0; i < M; i++) {
        q.emplace(Node { init[i], 0 });
        ans[init[i]] = 0;
        for (auto next : adj[init[i]]) {
            neigh[next]++;
        }
    }

    int cur_time = 0;
    unordered_map<int, int> lazy; // idx, val
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur_time != cur.depth) {
            for (auto p : lazy) {
                neigh[p.fi] += p.se;
            }
            cur_time++;
            lazy.clear();
        }
        for (auto next : adj[cur.idx]) {
            if (ans[next] == -1) {
                if (neigh[next] >= (adj[next].size() % 2 ?
                    adj[next].size() / 2 + 1 : adj[next].size() / 2)) {
                    q.emplace(Node { next, cur.depth + 1 });
                    ans[next] = cur.depth + 1;

                    for (auto nextt : adj[next]) {
                        lazy[nextt]++;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << ' ';
    }
}

void Init(void) {
    cin >> N;
    adj.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        while (1) {
            int inp; cin >> inp;
            if (inp == 0) break;
            adj[i].emplace_back(inp);
        }
    }
    cin >> M;
    init.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> init[i];
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}