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
\*************  2021-04-01 02:00:57  *************/

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
/*************************************************/

int N, M;
int answer;
vs graph;
vvb visited;

int di[4] = { 0,0,-1,1 };
int dj[4] = { -1,1,0,0 };

bool CanGo(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M;
}

int BFS(pii init) {
    int ret = 0;
    queue<pair<pii, int>> sq;
    sq.emplace(init, 0);
    visited[init.fi][init.se] = true;
    while (!sq.empty()) {
        pii point = sq.front().fi;
        int len = sq.front().se;
        ret = max(ret, len);
        sq.pop();
        rep(k, 0, 4) {
            int i = point.fi + di[k];
            int j = point.se + dj[k];
            if (CanGo(i, j) && !visited[i][j] && graph[i][j] == 'L') {
                sq.emplace(pii { i, j }, len + 1);
                visited[i][j] = true;
            }
        }
    }
    return ret;
}

void Solve(void) {
    rep(i, 0, N) {
        rep(j, 0, M) {
            if (graph[i][j] == 'L') {
                visited = vvb(N, vb(M, false));
                answer = max(answer, BFS({ i,j }));
            }
        }
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> N >> M;
    graph.resize(N);
    rep(i, 0, N) {
        cin >> graph[i];
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}