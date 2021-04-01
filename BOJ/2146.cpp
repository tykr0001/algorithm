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
\*************  2021-04-01 17:09:48  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

int N;
int cnt;
int answer;
vvi graph;
vvb visited;

int di[4] = { 0,0,-1,1 };
int dj[4] = { -1,1,0,0 };

bool CanGo(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < N;
}


int BFS(pii init) {
    cnt++;
    queue<pair<pii, int>> sq;
    sq.emplace(init, 0);
    visited[init.fi][init.se] = true;
    while (!sq.empty()) {
        auto front = sq.front().fi;
        auto len = sq.front().se;
        sq.pop();
        rep(k, 0, 4) {
            int i = front.fi + di[k];
            int j = front.se + dj[k];
            if (CanGo(i, j) && !visited[i][j] && graph[i][j] != graph[init.fi][init.se]) {
                sq.emplace(pii { i, j }, len + 1);
                visited[i][j] = true;
                if (graph[i][j] != 0) {
                    return len;
                }
            }
        }
    }
    return INF;
}

void InitSet(pii init) {
    cnt++;
    queue<pii> sq;
    sq.emplace(init);
    visited[init.fi][init.se] = true;
    graph[init.fi][init.se] = cnt;
    while (!sq.empty()) {
        auto front = sq.front();
        sq.pop();
        rep(k, 0, 4) {
            int i = front.fi + di[k];
            int j = front.se + dj[k];
            if (CanGo(i, j) && !visited[i][j] && graph[i][j]) {
                sq.emplace(i, j);
                visited[i][j] = true;
                graph[i][j] = cnt;
            }
        }
    }
}

void Solve(void) {
    answer = INF;
    rep(i, 0, N) {
        rep(j, 0, N) {
            if (graph[i][j]) {
                visited = vvb(N, vb(N));
                answer = min(answer, BFS({ i,j }));
            }
        }
    }
    cout << answer;
}

void Init(void) {
    cin >> N;
    graph = vvi(N, vi(N));
    visited = vvb(N, vb(N));
    cin >> graph;
    rep(i, 0, N) {
        rep(j, 0, N) {
            if (graph[i][j] && !visited[i][j])
                InitSet({ i,j });
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}