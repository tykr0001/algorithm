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
\*************  2021-03-17 22:54:33  *************/

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

int n, m;
int answer;
vs graph;
vvi cache;
int dx[3] = { 0,1,1 };
int dy[3] = { 1,0,1 };

bool CanGo(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

int DP(int i, int j) {
    if (!CanGo(i, j))
        return 0;
    if (cache[i][j] != -1)
        return cache[i][j];
    cache[i][j] = 0;
    int ret = INT32_MAX;
    rep(k, 0, 3) {
        int x = i + dx[k];
        int y = j + dy[k];
        ret = min(ret, DP(x, y));
    }
    if (graph[i][j] == '1') {
        ret++;
        answer = max(answer, ret);
        cache[i][j] = ret;
    }
    return cache[i][j];
}

void Solve(void) {
    DP(0, 0);
    cout << answer*answer << endl;
}

void Init(void) {
    cin >> n >> m;
    graph.resize(n);
    cache.resize(n, vi(m, -1));
    rep(i, 0, n) {
        cin >> graph[i];
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}