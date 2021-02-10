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
\*************  2021-02-10 01:38:33  *************/

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

ll N;
v<vvi> cache;
ll answer;

// top-down ÀÌ¿Ö¾È?
ll DP(ll len, ll selected, ll n_last) {
    if (cache[len][selected][n_last] != -1) {
        return cache[len][selected][n_last];
    }
    if (len == 1) {
        return cache[len][selected][n_last] != -1 ? cache[len][selected][n_last] : 0;
    }
    if ((selected >> n_last) & 1 == 0) {
        return cache[len][selected][n_last] = 0;
    }
    ll ret;
    if (n_last == 0) {
        ret = DP(len - 1, selected, n_last + 1) + DP(len - 1, selected ^ (1 << n_last), n_last + 1);
    }
    else if (n_last == 9) {
        ret = DP(len - 1, selected, n_last - 1) + DP(len - 1, selected ^ (1 << n_last), n_last - 1);
    }
    else {
        ret = DP(len - 1, selected, n_last - 1) + DP(len - 1, selected ^ (1 << n_last), n_last - 1)
            + DP(len - 1, selected, n_last + 1) + DP(len - 1, selected ^ (1 << n_last), n_last + 1);
    }
    return cache[len][selected][n_last] = ret;
}

void Solve(void) {
    // for (ll i = 0; i < 10; i++) {
    //     answer += DP(N, 0b1111111111, i);
    // }

    // bottom-up
    for (ll i = 1; i < N; i++) {
        for (ll j = 0; j < 10; j++) {
            for (ll mask = 0; mask < 1024; mask++) {
                if (j == 0) {
                    cache[i + 1][mask | 1 << (j + 1)][j + 1] += cache[i][mask][j];
                    cache[i + 1][mask | 1 << (j + 1)][j + 1] %= 1000000000;
                }
                else if (j == 9) {
                    cache[i + 1][mask | 1 << (j - 1)][j - 1] += cache[i][mask][j];
                    cache[i + 1][mask | 1 << (j - 1)][j - 1] %= 1000000000;
                }
                else {
                    cache[i + 1][mask | 1 << (j + 1)][j + 1] += cache[i][mask][j];
                    cache[i + 1][mask | 1 << (j - 1)][j - 1] += cache[i][mask][j];
                    cache[i + 1][mask | 1 << (j + 1)][j + 1] %= 1000000000;
                    cache[i + 1][mask | 1 << (j - 1)][j - 1] %= 1000000000;
                }
            }
        }
    }
    for (ll i = 0; i < 10; i++) {
        answer += cache[N][0b1111111111][i];
    }
    
    cout << answer % 1000000000 << endl;
}

void Init(void) {
    Boost;
    cin >> N;
    // for top-down dp
    // cache.resize(N + 1, vvi(1024, vi(10, -1)));
    // for (ll i = 1; i < 10; i++) {
    //     cache[1][1 << i][i] = 1;
    // }
    // for (ll i = 0; i < 1024; i++) {
    //     cache[1][i][0] = 0;
    // }

    cache.resize(N + 1, vvi(1024, vi(10, 0)));
    for (ll i = 1; i < 10; i++) {
        cache[1][1 << i][i] = 1;
    }
    cache[1][0b1][0] = 0;
}

int main(void) {
    Init();
    Solve();
    return 0;
}