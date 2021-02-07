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
\*************  2021-02-07 22:43:17  *************/

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

int n;

void Solve(void) {
    if (n % 10 >= 5) {
        cout << n / 10 * 10 + 10 << endl;
    }
    else {
        cout << n / 10 * 10 << endl;
    }
    if (n / 10 % 10 >= 5) {
        cout << n / 100 * 100 + 100 << endl;
    }
    else {
        cout << n / 100 * 100 << endl;
    }
    if (n / 100 % 10 >= 5) {
        cout << n / 1000 * 1000 + 1000 << endl;
    }
    else {
        cout << n / 1000 * 1000 << endl;
    }
}

void Init(void) {
    Boost;
    cin >> n;
}

int main(void) {
    Init();
    Solve();
    return 0;
}