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
\*************  2021-01-18 15:10:21  *************/

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
ll answer = LINF;
ll answer_lo;
ll answer_mid;
ll answer_hi;
vi liquid;

void Solve(void) {
    for (ll lo = 0; lo < N - 2; lo++) {
        ll mid = lo + 1, hi = N - 1;
        while (mid < hi) {
            if (llabs(liquid[lo] + liquid[mid] + liquid[hi]) < answer) {
                answer = llabs(liquid[lo] + liquid[mid] + liquid[hi]);
                answer_lo = lo;
                answer_mid = mid;
                answer_hi = hi;
            }
            if (liquid[lo] + liquid[mid] + liquid[hi] < 0) {
                mid++;
            }
            else if (liquid[lo] + liquid[mid] + liquid[hi] > 0) {
                hi--;
            }
            else {
                break;
            }
        }
    }

    cout << liquid[answer_lo] << " " << liquid[answer_mid] << " " << liquid[answer_hi] << endl;
    return;
}

void Init(void) {
    Boost;
    cin >> N;
    liquid.resize(N);
    for (ll i = 0; i < N; i++) {
        cin >> liquid[i];
    }
    sort(liquid.begin(), liquid.end());
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}