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
\*************  2021-02-01 16:44:08  *************/

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
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

int N;
v<pii> mat;
vvi cache;

int DP(int beg, int end) {
    if (cache[beg][end] != -1) {
        return cache[beg][end];
    }
    if (beg == end) {
        return 0;
    }
    cache[beg][end] = INF;
    for (int i = beg; i < end; i++) {
        cache[beg][end] = min(cache[beg][end], DP(beg, i) + DP(i + 1, end) + mat[beg].fi * mat[i].se * mat[end].se);
    }
    return cache[beg][end];
}

void Solve(void) {
    cout << DP(0, N - 1);
}

void Init(void) {
    Boost;
    cin >> N;
    mat.resize(N);
    cache.resize(N, vi(N, -1));
    for (int i = 0; i < N; i++) {
        cin >> mat[i].fi >> mat[i].se;
    }
}

int main(void) {
    Init();
    Solve();
    return 0;
}