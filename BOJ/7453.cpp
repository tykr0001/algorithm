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
\*************  2021-01-18 22:14:03  *************/

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
#define LINF 9e18
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

ll N;
ll answer;
vi A, B, C, D;
vi AB, CD;

void Solve(void) {
    for (ll i = 0; i < N * N; i++) {
        auto lo = lower_bound(AB.begin(), AB.end(), -CD[i]);
        auto hi = upper_bound(AB.begin(), AB.end(), -CD[i]);
        if (-CD[i] == *lo) {
            answer += hi - lo;
        }
    }
    cout << answer << endl;
    return;
}

void Init(void) {
    Boost;
    cin >> N;
    A.resize(N);
    B.resize(N);
    C.resize(N);
    D.resize(N);
    AB.resize(N * N);
    CD.resize(N * N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            AB[N * i + j] = A[i] + B[j];
            CD[N * i + j] = C[i] + D[j];
        }
    }
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}