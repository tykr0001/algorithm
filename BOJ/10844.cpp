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
\*************  2021-01-15 22:56:51  *************/

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
#define MOD 1000000000

v<v<ll>> cache;
int N;
ll answer;

ll DP(int len, int n) {
    if (cache[len][n] != -1) {
        return cache[len][n];
    }
    if (n == 0) {
        return cache[len][n] = DP(len - 1, n + 1);
    }
    else if (n == 9) {
        return cache[len][n] = DP(len - 1, n - 1);
    }
    else {
        return cache[len][n] = (DP(len - 1, n - 1) + DP(len - 1, n + 1)) % MOD;
    }
}

void Solve(void) {
    for (int i = 0; i < 10; i++) {
        answer += DP(N, i);
    }
    cout << answer % MOD << endl;
}

void Init(void) {
    cin >> N;
    cache.resize(N + 1, v<ll>(10, -1));
    cache[1][0] = 0;
    for (int i = 1; i < 10; i++) {
        cache[1][i] = 1;
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}