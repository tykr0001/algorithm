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
#define vi vector<ll> 
#define vvi vector<vector<ll>>
#define vb vector<bool> 
#define vvb vector<vector<bool>> 
#define si stack<ll>
#define qi queue<ll>
#define li list<ll> 
#define pii pair<ll,ll>
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2e9
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

ll N;
v<pii> loc;
double answer;

void Solve(void) {
    for (ll i = 0; i < N; i++) {
        answer += (loc[i].fi + loc[i + 1 < N ? i + 1 : 0].fi) * (loc[i].se - loc[i + 1 < N ? i + 1 : 0].se);
    }
    answer = abs(answer) / 2.0;
    cout << fixed;
    cout.precision(1);
    cout << answer << endl;
    return;
}

void Init(void) {
    Boost;
    cin >> N;
    loc.resize(N);
    for (ll i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        loc[i] = { x,y };
    }
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}