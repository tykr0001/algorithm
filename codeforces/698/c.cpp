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
\*************  2021-01-29 00:20:57  *************/

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

ll n;
v<ll> d;
ll a0;
ll a_sum;
bool flag;

int main(void) {
    Boost;
    ll T; cin >> T;
    while (T--) {
        cin >> n;
        d.clear();
        d.resize(2 * n);
        a_sum = 0;
        flag = false;
        for (ll i = 0; i < 2 * n; i++) {
            cin >> d[i];
            if (d[i] % 2)
                flag = true;
        }
        if (flag) {
            cout << "NO" << endl;
            continue;
        }

        sort(d.begin(), d.end());
        d.erase(unique(d.begin(), d.end()), d.end());
        if (d.size() != n) {
            cout << "NO" << endl;
            continue;
        }
        d[0] /= 2;
        a_sum = 0;
        for (ll i = 1; i < n; i++) {
            d[i] /= 2;
            d[i] -= d[0];
            ll tmp = d[i] + a_sum;
            if ((d[i] + a_sum) % i) {
                flag = true;
                break;
            }
            a_sum += (d[i] + a_sum) / i;
        }
        if (flag) {
            cout << "NO" << endl;
            continue;
        }
        if (a_sum >= d[0]) {
            cout << "NO" << endl;
        }
        else {
            ll gap = d[0] - a_sum;
            if (gap % n) {
                cout << "NO" << endl;
            }
            else {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}