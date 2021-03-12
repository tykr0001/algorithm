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
\*************  2021-03-12 04:35:14  *************/

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

struct point {
    int x;
    int y;
} p1, p2, p3, p4;

void Solve(void) {
    if (p1.x == p2.x)
        p4.x = p3.x;
    if (p1.x == p3.x)
        p4.x = p2.x;
    if (p2.x == p3.x)
        p4.x = p1.x;

    if (p1.y == p2.y)
        p4.y = p3.y;
    if (p1.y == p3.y)
        p4.y = p2.y;
    if (p2.y == p3.y)
        p4.y = p1.y;
    cout << p4.x << ' ' << p4.y << endl;
}

void Init(void) {
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}