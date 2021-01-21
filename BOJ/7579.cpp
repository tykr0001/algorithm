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
\*************  2021-01-21 10:10:17  *************/

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
int max_m;
int answer = INF;
vector<int> memories;
vector<int> costs;

void Knapsack() {
    vector<int> cache(M + max_m + 1, INF); // cache[i] is min weight up to index i
    cache[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = M + max_m; j > 0; j--) {
            if (memories[i] <= j) {
                cache[j] = min(cache[j], cache[j - memories[i]] + costs[i]);
            }
        }
    }
    for (int i = M + max_m; i >= M; i--) {
        answer = min(answer, cache[i]);
    }
    cout << answer << endl;
}

void Solve(void) {
    Knapsack();
    return;
}

void Init(void) {
    Boost;
    cin >> N >> M;
    memories.resize(N);
    costs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> memories[i];
        max_m = max(max_m, memories[i]);
    }
    for (int i = 0; i < N; i++) {
        cin >> costs[i];
    }
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}