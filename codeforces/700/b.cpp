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

ll t;
ll A, B, n;
v<pair<ll,ll>> m;
bool flag;
void Solve(void) {
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            ll cnt;
            if (m[i].se % A) {
                cnt = m[i].se / A + 1;
            }
            else {
                cnt = m[i].se / A;
            }
            B -= cnt * m[i].fi;
            m[i].se -= cnt * A;
            if (B < 0) {
                flag = true;
                break;
            }
        }
        else {
            ll hc, mc;
            if (m[i].se % A) {
                hc = m[i].se / A + 1;
            }
            else {
                hc = m[i].se / A;
            }
            if (B % m[i].fi) {
                mc = B / m[i].fi + 1;
            }
            else {
                mc = B / m[i].fi;
            }
            if (hc > mc) {
                flag = true;
            }
        }
    }

    if (flag) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}

void Init(void) {
    cin >> A >> B >> n;
    m.clear();
    m.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> m[i].fi;
    }
    for (int i = 0; i < n; i++) {
        cin >> m[i].se;
    }
    sort(m.begin(), m.end());
    flag = false;
}

int main(void) {
    Boost;
    cin >> t;
    while (t--) {
        Init();
        Solve();
    }
    return 0;
}