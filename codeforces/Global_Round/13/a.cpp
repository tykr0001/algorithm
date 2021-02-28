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

int N, Q;
int op, k;
int num_1;
vi a;

void Solve(void) {
    while (Q--) {
        cin >> op >> k;
        if (op == 1) {
            if (a[k - 1] == 0) {
                num_1++;
            }
            else {
                num_1--;
            }
            a[k - 1] = 1 - a[k - 1];
        }
        else {
            if (k <= num_1) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
    }
}

void Init(void) {
    cin >> N >> Q;
    num_1 = 0;
    a.clear();
    a.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (a[i] != 0) {
            num_1++;
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}