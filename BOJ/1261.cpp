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
\*************  2021-03-29 14:42:34  *************/

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

int M, N;
vs maze;
vvi dist;

int di[4] = { 0,0,-1,1 };
int dj[4] = { -1,1,0,0 };

bool CanGo(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M;
}

int ZeroOneBFS(const pii& init) {
    deque<pii> sq;
    sq.emplace_back(init);
    while (!sq.empty()) {
        auto front = sq.front();
        sq.pop_front();
        rep(k, 0, 4) {
            int i = front.fi + di[k];
            int j = front.se + dj[k];
            if (CanGo(i, j)) {
                int cost = dist[front.fi][front.se] + maze[i][j] - '0';
                if (cost < dist[i][j]) {
                    dist[i][j] = cost;
                    if (maze[i][j] == '0')
                        sq.emplace_front(i, j);
                    else {
                        sq.emplace_back(i, j);
                    }
                }
            }
        }
    }
    return dist[N - 1][M - 1];
}

void Solve(void) {
    cout << ZeroOneBFS({ 0,0 });
}

void Init(void) {
    cin >> M >> N;
    maze.resize(N);
    dist.resize(N, vi(M, INF));
    dist[0][0] = 0;
    rep(i, 0, N) {
        cin >> maze[i];
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}