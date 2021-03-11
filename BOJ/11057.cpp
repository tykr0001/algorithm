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
\*************  2021-03-11 07:38:26  *************/

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
#define MOD 10007

int N;
int answer;
vvi cache;

int DP(int len, int n) {
    if (cache[len][n] != 0) {
        return cache[len][n];
    }
    if (len == 1) {
        return cache[len][n] = 1;
    }
    int ret = 0;
    for (int i = n; i <= 9; i++) {
        ret += DP(len - 1, i);
    }
    return cache[len][n] = ret % MOD;
}

void Solve(void) {
    for (int i = 0; i <= 9; i++) {
        answer += DP(N, i);
        answer %= MOD;
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> N;
    cache.resize(N + 1, vi(10));
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}