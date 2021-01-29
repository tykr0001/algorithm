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
\*************  2021-01-28 23:44:16  *************/

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

int D;
int Q;
vi a;

void Solve(void) {
    for (int i = 0; i < Q; i++) {
        if (a[i] >= D * 10) {
            cout << "YES" << endl;
        }
        else {
            int r = a[i] % 10;
            int tmp = D;
            while (tmp % 10 != r && a[i] >= tmp) {
                tmp += D;
            }
            if (a[i] >= tmp) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
}

void Init(void) {
    cin >> Q >> D;
    a.clear();
    a.resize(Q);
    for (int i = 0; i < Q; i++) {
        cin >> a[i];
    }
}

int main(void) {
    Boost;
    int T; cin >> T;
    while (T--) {
        Init();
        Solve();
    }
    return 0;
}