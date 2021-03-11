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
\*************  2021-03-11 05:57:35  *************/

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
vi A;
vi op(4);
int max_cache[11][11][11][11][11];
int min_cache[11][11][11][11][11];

int MaxDP(int n, int plus, int minus, int mul, int div);
int MinDP(int n, int plus, int minus, int mul, int div);

int MaxDP(int n, int plus, int minus, int mul, int div) {
    if (max_cache[n][plus][minus][mul][div] != 0) {
        return max_cache[n][plus][minus][mul][div];
    }
    if (n == 0) {
        return max_cache[n][plus][minus][mul][div] = A[0];
    }
    int ret = -2e9;
    if (plus > 0)
        ret = max(ret, MaxDP(n - 1, plus - 1, minus, mul, div) + A[n]);
    if (minus > 0)
        ret = max(ret, MaxDP(n - 1, plus, minus - 1, mul, div) - A[n]);
    if (mul > 0) {
        ret = max(ret, MaxDP(n - 1, plus, minus, mul - 1, div) * A[n]);
        ret = max(ret, MinDP(n - 1, plus, minus, mul - 1, div) * A[n]);
    }
    if (div > 0 && A[n] != 0) {
        ret = max(ret, MaxDP(n - 1, plus, minus, mul, div - 1) / A[n]);
        ret = max(ret, MinDP(n - 1, plus, minus, mul, div - 1) / A[n]);
    }
    return max_cache[n][plus][minus][mul][div] = ret;
}

int MinDP(int n, int plus, int minus, int mul, int div) {
    if (min_cache[n][plus][minus][mul][div] != 0) {
        return min_cache[n][plus][minus][mul][div];
    }
    if (n == 0) {
        return min_cache[n][plus][minus][mul][div] = A[0];
    }
    int ret = 2e9;
    if (plus > 0)
        ret = min(ret, MinDP(n - 1, plus - 1, minus, mul, div) + A[n]);
    if (minus > 0)
        ret = min(ret, MinDP(n - 1, plus, minus - 1, mul, div) - A[n]);
    if (mul > 0) {
        ret = min(ret, MinDP(n - 1, plus, minus, mul - 1, div) * A[n]);
        ret = min(ret, MaxDP(n - 1, plus, minus, mul - 1, div) * A[n]);
    }
    if (div > 0 && A[n] != 0) {
        ret = min(ret, MinDP(n - 1, plus, minus, mul, div - 1) / A[n]);
        ret = min(ret, MaxDP(n - 1, plus, minus, mul, div - 1) / A[n]);
    }
    return min_cache[n][plus][minus][mul][div] = ret;
}

void Solve(void) {
    cout << MaxDP(N - 1, op[0], op[1], op[2], op[3]) << endl;
    cout << MinDP(N - 1, op[0], op[1], op[2], op[3]);
}

void Init(void) {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}