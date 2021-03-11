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
\*************  2021-03-11 04:17:42  *************/

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

int N;
vi T;
vi P;
vi cache;

void Solve(void) {
    for (int i = 1; i <= N; i++) {
        cache[i] = max(cache[i - 1], cache[i]);
        int d = i + T[i] - 1;
        if (d <= N) {
            cache[d] = max(cache[d], cache[i - 1] + P[i]);
        }
    }
    cout << cache[N];
}

void Init(void) {
    cin >> N;
    T.resize(N + 1);
    P.resize(N + 1);
    cache.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}