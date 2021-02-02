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
\*************  2021-02-01 16:12:03  *************/

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
#define INF 2e9
#define LINF 9e18
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

int N, M;
int S, E;
vi arr;
vvi cache;

int DP(int start, int end) {
    if (cache[start][end] != -1) {
        return cache[start][end];
    }
    if (start == end) {
        return 1;
    }
    if (start > end) {
        if (arr[start] == arr[end]) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (arr[start] != arr[end]) {
        return cache[start][end] = 0;
    }
    else {
        return cache[start][end] = DP(start + 1, end - 1);
    }
}

void Solve(void) {
    while (M--) {
        cin >> S >> E;
        cout << DP(S, E) << endl;
    }
}

void Init(void) {
    Boost;
    cin >> N;
    arr.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    cache.resize(N + 1, vi(N + 1, -1));
    cin >> M;
}

int main(void) {
    Init();
    Solve();
    return 0;
}