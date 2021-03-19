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
\*************  2021-03-16 00:24:29  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define v vector
#define s stack
#define q queue 
#define l list 
#define pq priority_queue 
#define p pair
#define vi vector<int> 
#define vvi vector<vector<int>>
#define vb vector<bool> 
#define vvb vector<vector<bool>> 
#define si stack<int>
#define qi queue<int>
#define li list<int> 
#define pii pair<int,int>
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF INT32_MAX
#define LINF INT64_MAX
#define endl '\n'
#define For(i,beg,end) for(int i=beg; i<end; i++)
typedef long long ll;
/*************************************************/

int N, M;
int answer;
vvi graph;
vvi cache;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool CanGo(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M;
}

int DP(int i, int j) {
    if (cache[i][j] != -1) {
        return cache[i][j];
    }
    int ret = 0;
    For(k, 0, 4) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (CanGo(x, y) && graph[i][j] < graph[x][y]) {
            ret += DP(x, y);
        }
    }
    return cache[i][j] = ret;
}

void Solve(void) {
    cout << DP(N - 1, M - 1);
}

void Init(void) {
    cin >> N >> M;
    graph.resize(N, vi(M));
    cache.resize(N, vi(M, -1));
    cache[0][0] = 1;
    For(i, 0, N) {
        For(j, 0, M) {
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