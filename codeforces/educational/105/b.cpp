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

int n, U, R, D, L;
bool flag = false;
void Solve(void) {
    for (int pos = 0; pos < 16; pos++) {
        int p1 = pos & 1;
        int p2 = (pos & 2) >> 1;
        int p3 = (pos & 4) >> 2;
        int p4 = (pos & 8) >> 3;
        if (n - 2 >= U - p1 - p2 && U - p1 - p2 >= 0 &&
            n - 2 >= D - p3 - p4 && D - p3 - p4 >= 0 &&
            n - 2 >= R - p2 - p3 && R - p2 - p3 >= 0 &&
            n - 2 >= L - p4 - p1 && L - p4 - p1 >= 0) {
            flag = true;
        }
    }
    if (flag) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

void Init(void) {
    cin >> n >> U >> R >> D >> L;
    flag = false;
}

int main(void) {
    Boost;
    int t; cin >> t;
    while (t--) {
        Init();
        Solve();
    }
    return 0;
}