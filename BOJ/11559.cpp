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
\*************  2021-04-27 16:07:15  *************/

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
template<class T, class U>
void sort(T& container, U cmp) { sort(container.begin(), container.end(), cmp); }
template<class T, class U>
istream& operator>>(istream& is, pair<T, U>& rhs) { is >> rhs.fi >> rhs.se; return is; }
template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& rhs) { os << rhs.fi << ' ' << rhs.se; return os; }
template<class T>
istream& operator>>(istream& is, vector<T>& rhs) { for (T& elem : rhs) is >> elem; return is; }
template<class T>
ostream& operator<<(ostream& os, const vector<T>& rhs) { for (const T& elem : rhs) os << elem << endl; return os; }
template<class T>
void resize(T& container, int _size) { container.resize(_size); }
template<class T, typename... sizes>
void resize(T& container, int _size, sizes... _sizes) { container.resize(_size); for (auto& elem : container) resize(elem, _sizes...); }
/*************************************************/

vs graph;
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

bool CanGo(int i, int j) {
    return 0 <= i & i < 12 && 0 <= j && j < 6;
}

void BFS(pii init, char color) {
    queue<pii> sq;
    vvb visited;
    vpii same;
    sq.emplace(init);
    resize(visited, 12, 6);
    visited[init.fi][init.se] = true;
    same.emplace_back(init);
    int cnt = 1;
    while (!sq.empty()) {
        pii node = sq.front();
        sq.pop();
        rep(k, 0, 4) {
            int i = node.fi + di[k];
            int j = node.se + dj[k];
            if (CanGo(i, j) && !visited[i][j] && graph[i][j] == color) {
                sq.emplace(i, j);
                visited[i][j] = true;
                same.emplace_back(i, j);
                cnt++;
            }
        }
    }
    if (cnt >= 4) {
        for (auto& node : same) {
            graph[node.fi][node.se] = '.';
        }
    }
}

void Solve(void) {
    vs prev;
    int ans = 0;
    do {
        prev = graph;
        rep(i, 0, 12) {
            rep(j, 0, 6) {
                if (graph[i][j] != '.')
                    BFS(pii { i,j }, graph[i][j]);
            }
        }

        rep(j, 0, 6) {
            int pos = 0;
            while (pos < 12) {
                if (graph[pos][j] == '.') {
                    int iter = pos;
                    while (iter < 11 && graph[++iter][j] == '.');
                    if (iter == 12) break;
                    graph[pos][j] = graph[iter][j];
                    graph[iter][j] = '.';
                }
                pos++;
            }
        }

        ans++;
    } while (prev != graph);
    cout << ans - 1;
}

void Init(void) {
    resize(graph, 12);
    for (int i = 11; i >= 0; i--)
        cin >> graph[i];
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}