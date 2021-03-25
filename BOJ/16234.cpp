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
\*************  2021-03-25 11:20:42  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define v vector
#define vi vector<int> 
#define vvi vector<vector<int>>
#define vb vector<bool> 
#define vvb vector<vector<bool>> 
#define vs vector<string> 
#define vc vector<char> 
#define vl vector<ll> 
#define vvl vector<vector<ll>> 
#define pii pair<int,int>
#define pll pair<ll,ll> 
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF INT32_MAX
#define LINF INT64_MAX
#define endl '\n'
#define rep(i,beg,end) for(int i=beg; i<end; i++)
typedef long long ll;
/*************************************************/

int N, L, R;
int answer;
bool flag;
vvi graph;
vvb visited;

int di[4] = { 0,0,-1,1 };
int dj[4] = { -1,1,0,0 };

bool CanGo(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < N && !visited[i][j];
}

bool BFS(pii init) {
    int sum = 0;
    queue<pii> sq;
    vector<pii> countries;
    sq.emplace(init);
    visited[init.fi][init.se] = true;
    countries.emplace_back(init);
    sum += graph[init.fi][init.se];
    while (!sq.empty()) {
        auto cur = sq.front();
        sq.pop();
        rep(k, 0, 4) {
            int i = cur.fi + di[k];
            int j = cur.se + dj[k];
            if (CanGo(i, j) && L <= abs(graph[cur.fi][cur.se] - graph[i][j])
                && abs(graph[cur.fi][cur.se] - graph[i][j]) <= R) {
                sq.emplace(i, j);
                visited[i][j] = true;
                countries.emplace_back(i, j);
                sum += graph[i][j];
            }
        }
    }
    for (auto pos : countries) {
        graph[pos.fi][pos.se] = sum / countries.size();
    }
    return countries.size() > 1;
}

void Solve(void) {
    while (1) {
        flag = false;
        visited.clear();
        visited.resize(N, vb(N, false));
        rep(i, 0, N) {
            rep(j, 0, N) {
                if (!visited[i][j]) {
                    flag = BFS({ i,j }) || flag;
                }
            }
        }


        if (!flag) {
            break;
        }
        answer++;
    }
    cout << answer;
}

void Init(void) {
    cin >> N >> L >> R;
    graph.resize(N, vi(N));
    rep(i, 0, N) {
        rep(j, 0, N) {
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