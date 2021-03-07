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
\*************  2021-02-18 23:52:18  *************/

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

int t;
string a;
string b;
int max_h;
int max_m;
int h;
int m;

bool CanReverse(int n) {
    return (n / 10 == 0 || n / 10 == 1 || n / 10 == 2 || n / 10 == 5 || n / 10 == 8) &&
        (n % 10 == 0 || n % 10 == 1 || n % 10 == 2 || n % 10 == 5 || n % 10 == 8);
}

int ReverseNum(int n) {
    int ret = 0;
    if (n % 10 == 0)
        ret += 0 * 10;
    else if (n % 10 == 1)
        ret += 1 * 10;
    else if (n % 10 == 2)
        ret += 5 * 10;
    else if (n % 10 == 5)
        ret += 2 * 10;
    else if (n % 10 == 8)
        ret += 8 * 10;

    if (n / 10 == 0)
        ret += 0;
    else if (n / 10 == 1)
        ret += 1;
    else if (n / 10 == 2)
        ret += 5;
    else if (n / 10 == 5)
        ret += 2;
    else if (n / 10 == 8)
        ret += 8;
    return ret;
}

void Solve(void) {
    while (1) {
        if (CanReverse(h) && CanReverse(m) && max_h > ReverseNum(m) && max_m > ReverseNum(h)) {
            if (h < 10) {
                cout << 0;
            }
            cout << h << ":";
            if (m < 10) {
                cout << 0;
            }
            cout << m << endl;
            break;
        }
        if (++m == max_m) {
            m = 0;
            if (++h == max_h) {
                h = 0;
            }
        }
    }
}

void Init(void) {
    cin >> max_h >> max_m >> b;
    h = (b[0] - '0') * 10 + b[1] - '0';
    m = (b[3] - '0') * 10 + b[4] - '0';
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