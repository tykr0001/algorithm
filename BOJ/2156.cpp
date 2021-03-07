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
\*************  2021-03-08 01:26:18  *************/

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
vi arr;
vvi cache;

int DP(int idx, int day) {
    if (cache[idx][day] != -1 || idx == 0) {
        return cache[idx][day];
    }
    if (day == 0) {
        return cache[idx][day] = max(max(DP(idx - 1, 0), DP(idx - 1, 1)), DP(idx - 1, 2));
    }
    if (day == 1) {
        return cache[idx][day] = DP(idx - 1, 0) + arr[idx];
    }
    if (day == 2) {
        return cache[idx][day] = DP(idx - 1, 1) + arr[idx];
    }
}

void Solve(void) {
    cout << max(max(DP(N - 1, 0), DP(N - 1, 1)), DP(N - 1, 2)) << endl;
}

void Init(void) {
    cin >> N;
    arr.resize(N);
    cache.resize(N, vi(3, -1));
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cache[0][0] = 0;
    cache[0][1] = arr[0];
    cache[0][2] = arr[0];
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}