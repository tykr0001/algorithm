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
\*************  2021-03-11 05:34:47  *************/

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
vi cost;
vi cache;

int DP(int n) {
    if (cache[n] != 0 || n == 0) {
        return cache[n];
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        ret = max(ret, DP(n - i) + cost[i]);
    }
    return cache[n] = ret;
}

void Solve(void) {
    cout << DP(N);
}

void Init(void) {
    cin >> N;
    cost.resize(N + 1);
    cache.resize(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}