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
\*************  2021-01-25 17:43:03  *************/

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
#define INF 2e9
#define LINF 9e18
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

ll A, B;
vector<ll> cache;

ll DP(ll n) {
    if (cache[n] != -1) {
        return cache[n];
    }
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    if (n == (n & -n)) {
        return cache[n] = 2 * DP(n / 2) + n / 2 - 1;
    }
    else {
        if (n % 2)
            return cache[n] = 2 * DP(n - 1) - DP(n - 2) + 1;
        else
            return cache[n] = DP(n - 1) + DP(n / 2) - DP(n / 2 - 1);

    }
}

void Solve(void) {
    cout << DP(B) - DP(A - 1);
}

void Init(void) {
    Boost;
    cin >> A >> B;
    cache.resize(B + 1, -1);
}

int main(void) {
    Init();
    Solve();
    return 0;
}