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
\*************  2021-01-26 00:17:36  *************/

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

ll n;

void Solve(void) {
    ll d = 2;
    if (n % 2) {
        cout << "YES" << endl;
        return;
    }
    while (n != 1 && n % 2 == 0) {
        if (n % d == 0) {
            if (d % 2) {
                break;
            }
            n /= d;
        }
        else {
            d += 1;
        }
    }
    if (d % 2 || (n % 2 && n != 1)) {
        cout << "YES" << endl;
        return;
    }
    else {
        cout << "NO" << endl;
        return;
    }
}

void Init(void) {
    cin >> n;
}

int main(void) {
    Boost;
    int T;
    cin >> T;
    while (T--) {
        Init();
        Solve();
    }
    return 0;
}