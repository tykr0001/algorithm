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
\*************  2021-02-04 01:40:28  *************/

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
#define vi vector<ll> 
#define vvi vector<vector<ll>>
#define vb vector<bool> 
#define vvb vector<vector<bool>> 
#define si stack<ll>
#define qi queue<ll>
#define li list<ll> 
#define pii pair<ll,ll>
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF ll32_MAX
#define LINF ll64_MAX
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

ll n, m;
ll two;
ll five;

void Solve(void) {
    for (ll i = 2; i <= n; i *= 2) {
        two += n / i;
    }
    for (ll i = 5; i <= n; i *= 5) {
        five += n / i;
    }

    for (ll i = 2; i <= n - m; i *= 2) {
        two -= (n - m) / i;
    }
    for (ll i = 5; i <= n - m; i *= 5) {
        five -= (n - m) / i;
    }

    for (ll i = 2; i <= m; i *= 2) {
        two -= m / i;
    }
    for (ll i = 5; i <= m; i *= 5) {
        five -= m / i;
    }

    cout << min(two, five) << endl;
}

void Init(void) {
    Boost;
    cin >> n >> m;
}

int main(void) {
    Init();
    Solve();
    return 0;
}