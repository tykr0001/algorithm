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
\*************  2021-01-16 14:05:30  *************/

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

ll T;
ll n, m;
ll answer;

vi A;
vi B;
vi sum_A;
vi sum_B;

void Solve(void) {
    for (ll i = 0; i < sum_A.size(); i++) {
        ll target = T - sum_A[i];
        auto ub = upper_bound(sum_B.begin(), sum_B.end(), target);
        auto lb = lower_bound(sum_B.begin(), sum_B.end(), target);
        answer += ub - lb;
    }
    cout << answer << endl;
    return;
}

void Init(void) {
    Boost;
    cin >> T;

    cin >> n;
    A.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (ll i = 0; i < n; i++) {
        ll sum = A[i];
        sum_A.push_back(sum);
        for (ll j = i + 1; j < n; j++) {
            sum += A[j];
            sum_A.push_back(sum);
        }
    }
    sort(sum_A.begin(), sum_A.end());

    cin >> m;
    B.resize(m);
    for (ll i = 0; i < m; i++) {
        cin >> B[i];
    }
    for (ll i = 0; i < m; i++) {
        ll sum = B[i];
        sum_B.push_back(sum);
        for (ll j = i + 1; j < m; j++) {
            sum += B[j];
            sum_B.push_back(sum);
        }
    }
    sort(sum_B.begin(), sum_B.end());

    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}