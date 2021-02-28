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
int n;
ll x_ans;
ll y_ans;
v<ll> x;
v<ll> y;
ll x_sum;
ll y_sum;

void Solve(void) {
    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    if (n % 2 == 0) {
        if (x[n / 2 - 1] <= x_sum / n && x_sum / n < x[n / 2] || x_sum % n == 0 && x_sum / n == x[n / 2]) {
            x_ans = x[n / 2] - x[n / 2 - 1] + 1;
        }
        else {
            x_ans = 1;
        }
    }
    else {
        x_ans = 1;
    }

    if (n % 2 == 0) {
        if (y[n / 2 - 1] <= y_sum / n && y_sum / n < y[n / 2] || y_sum % n == 0 && y_sum / n == y[n / 2]) {
            y_ans = y[n / 2] - y[n / 2 - 1] + 1;
        }
        else {
            y_ans = 1;
        }
    }
    else {
        y_ans = 1;
    }

    cout << x_ans * y_ans << endl;
}

void Init(void) {
    cin >> n;
    x_sum = y_sum = x_ans = y_ans = 0;
    x.clear();
    y.clear();
    x.resize(n);
    y.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        x_sum += x[i];
        y_sum += y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
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