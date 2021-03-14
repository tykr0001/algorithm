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
\*************  2021-03-15 03:30:53  *************/

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

int n, k;
vi coins;
vi cache;

void Solve(void) {
    For(i, 0, n) {
        For(j, 0, k + 1) {
            if (j + coins[i] <= k && cache[j] != INF)
                cache[j + coins[i]] = min(cache[j] + 1, cache[j + coins[i]]);
        }
    }
    if (cache[k] == INF) {
        cache[k] = -1;
    }
    cout << cache[k] << endl;
}

void Init(void) {
    cin >> n >> k;
    coins.resize(n);
    cache.resize(k + 1, INF);
    For(i, 0, n) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    cache[0] = 0;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}