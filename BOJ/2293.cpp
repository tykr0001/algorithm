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
\*************  2021-03-12 03:23:10  *************/

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

int n, k;
vi coin;
vi cache;

void Solve(void) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j >= coin[i]) {
                cache[j] += cache[j - coin[i]];
            }
        }
    }
    cout << cache[k] << endl;
}

void Init(void) {
    cin >> n >> k;
    coin.resize(n);
    cache.resize(k + 1, 0);
    cache[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}