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
\*************  2021-02-20 15:42:48  *************/

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
    double x;
    double y;
} a, b, c;

double x_a, y_a;
double x_b, y_b;
double x_c, y_c;
double d_1, d_2, d_3;

double Distance(const point& a, const point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void Solve(void) {
    if ((b.y - a.y) * (c.x - b.x) == (c.y - b.y) * (b.x - a.x)) {
        cout << -1.0 << endl;
    }
    else {
        d_1 = 2 * (Distance(a, b) + Distance(a, c));
        d_2 = 2 * (Distance(b, a) + Distance(b, c));
        d_3 = 2 * (Distance(c, a) + Distance(c, b));

        cout << max(d_1, max(d_2, d_3)) - min(d_1, min(d_2, d_3)) << endl;
    }
}

void Init(void) {
    cout << fixed;
    cout.precision(10);
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}