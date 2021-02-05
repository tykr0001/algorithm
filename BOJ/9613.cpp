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
#define INF ll32_MAX
#define LINF ll64_MAX
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

ll T;
ll N;
vi arr;
ll answer;
string inp;

void Solve(void) {
    for (ll i = 0; i < arr.size() - 1; i++) {
        for (ll j = i + 1; j < arr.size(); j++) {
            answer += __gcd(arr[i], arr[j]);
        }
    }
    cout << answer << endl;
}

void Init(void) {
    answer = 0;
    cin >> N;
    arr.clear();
    arr.resize(N);
    for (ll i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int main(void) {
    Boost;
    cin >> T;
    while (T--) {
        Init();
        Solve();
    }
    return 0;
}