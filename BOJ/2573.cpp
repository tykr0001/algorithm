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
\*************  2021-03-29 17:32:23  *************/

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
/*************************************************/

int N, M;
int answer;
vvi graph;
vvb visited;

int di[4] = { 0,0,1,-1 };
int dj[4] = { 1,-1,0,0 };

bool CanGo(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M;
}

void BFS(pii init) {
    queue<pii> sq;
    sq.emplace(init);
    visited[init.fi][init.se] = true;
    while (!sq.empty()) {
        auto front = sq.front();
        sq.pop();
        rep(k, 0, 4) {
            int i = front.fi + di[k];
            int j = front.se + dj[k];
            if (CanGo(i, j) && !visited[i][j] && graph[i][j] > 0) {
                sq.emplace(i, j);
                visited[i][j] = true;
            }
        }
    }
}

void Solve(void) {
    while (1) {
        answer++;
        vvi next_graph(graph);
        rep(i, 0, N) {
            rep(j, 0, M) {
                rep(k, 0, 4) {
                    if (CanGo(i + di[k], j + dj[k]) && graph[i + di[k]][j + dj[k]] == 0)
                        next_graph[i][j]--;

                    if (next_graph[i][j] < 0)
                        next_graph[i][j] = 0;
                }
            }
        }
        graph = next_graph;
        int cnt = 0;
        bool flag = false;
        visited = vvb(N, vb(M));
        rep(i, 0, N) {
            rep(j, 0, M) {
                if (!visited[i][j] && graph[i][j]) {
                    BFS({ i,j });
                    cnt++;
                }
                if (graph[i][j])
                    flag = true;
            }
        }
        if (cnt >= 2) {
            cout << answer << endl;
            return;
        }
        if (!flag) {
            cout << 0 << endl;
            return;
        }

    }
}

void Init(void) {
    cin >> N >> M;
    graph.resize(N, vi(M));
    visited.resize(N, vb(M));
    rep(i, 0, N) {
        rep(j, 0, M) {
            cin >> graph[i][j];
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}