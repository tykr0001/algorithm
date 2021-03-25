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
\*************  2021-03-25 08:20:47  *************/

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

int N;
vvl graph;
vvl cache;

void Solve(void) {
    rep(i, 0, N) {
        rep(j, 0, N) {
            if (i + graph[i][j] < N)
                cache[i + graph[i][j]][j] += cache[i][j];
            if (j + graph[i][j] < N)
                cache[i][j + graph[i][j]] += cache[i][j];
        }
    }
    cout << cache[N - 1][N - 1];
}

void Init(void) {
    cin >> N;
    graph.resize(N, vl(N));
    cache.resize(N, vl(N));
    cache[0][0] = 1;
    rep(i, 0, N) {
        rep(j, 0, N) {
            cin >> graph[i][j];
        }
    }
    graph[N - 1][N - 1] = 1;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}