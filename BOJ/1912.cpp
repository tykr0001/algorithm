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
\*************  2021-03-08 06:03:34  *************/

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
int answer;
vi arr;
vvi cache;

int DP(int idx, int selected) {
    if (cache[idx][selected] != -1001) {
        return cache[idx][selected];
    }
    if (selected == 0) {
        return cache[idx][selected] = 0;
    }
    else {
        return cache[idx][selected] = max(DP(idx - 1, 0), DP(idx - 1, 1)) + arr[idx];
    }
}

void Solve(void) {
    DP(N - 1, 1);
    for (int i = 0; i < N; i++) {
        if (cache[i][1] > answer) {
            answer = cache[i][1];
        }
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cache.resize(N, vi(2, -1001));
    cache[0][1] = arr[0];
    cache[0][0] = 0;
    answer = -2e9;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}