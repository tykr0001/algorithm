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
\*************  2021-03-25 07:27:17  *************/

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

int R, C;
int minute;
vs graph;
vvb visited;
pii init, goal;
queue<pii> water_queue;

int di[4] = { 0,0,1,-1 };
int dj[4] = { 1,-1,0,0 };

bool CanGo(int i, int j) {
    return 0 <= i && i < R && 0 <= j && j < C&& graph[i][j] != 'X';
}

void Flood() {
    queue<pii> next_queue;
    while (!water_queue.empty()) {
        auto pos = water_queue.front();
        water_queue.pop();
        rep(k, 0, 4) {
            int i = pos.fi + di[k];
            int j = pos.se + dj[k];
            if (CanGo(i, j) && graph[i][j] == '.') {
                graph[i][j] = '*';
                next_queue.emplace(i, j);
            }
        }
    }
    water_queue = next_queue;
}

int BFS() {
    int ret = 0;
    queue<pair<pii, int>> sq;
    sq.emplace(init, 1);
    visited[init.fi][init.se] = true;
    while (!sq.empty()) {
        auto pos = sq.front().first;
        auto time = sq.front().second;
        sq.pop();
        if (minute < time) {
            minute = time;
            Flood();
        }
        rep(k, 0, 4) {
            int i = pos.fi + di[k];
            int j = pos.se + dj[k];
            if (CanGo(i, j) && graph[i][j] != '*' && !visited[i][j]) {
                visited[i][j] = true;
                sq.emplace(pair<int, int>(i, j), time + 1);
                if (pair<int, int>(i, j) == goal) {
                    ret = time;
                    break;
                }
            }
        }
    }
    return ret;
}

void Solve(void) {
    int answer = BFS();
    if (answer != 0)
        cout << answer;
    else
        cout << "KAKTUS";
}

void Init(void) {
    cin >> R >> C;
    graph.resize(R);
    visited.resize(R, vb(C));
    rep(i, 0, R) {
        cin >> graph[i];
        rep(j, 0, C) {
            if (graph[i][j] == 'S') {
                init.fi = i;
                init.se = j;
            }
            if (graph[i][j] == 'D') {
                goal.fi = i;
                goal.se = j;
            }
            if (graph[i][j] == '*') {
                water_queue.emplace(i, j);
            }
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}