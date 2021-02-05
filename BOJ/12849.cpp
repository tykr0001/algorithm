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
\*************  2021-02-06 04:00:21  *************/

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

#define MOD 1000000007
int D;
v<li> graph(8);
vvi cache;

void Solve(void) {
    for (int i = 1; i <= D; i++) {
        for (int j = 0; j < 8; j++) {
            for (auto elem : graph[j]) {
                cache[i][elem] += cache[i - 1][j];
                cache[i][elem] %= MOD;
            }
        }
    }
    cout << cache[D][0] << endl;
}

void Init(void) {
    Boost;
    cin >> D;
    graph[0].emplace_back(1); graph[0].emplace_back(2);
    graph[1].emplace_back(0); graph[1].emplace_back(2); graph[1].emplace_back(3);
    graph[2].emplace_back(0); graph[2].emplace_back(1); graph[2].emplace_back(3); graph[2].emplace_back(4);
    graph[3].emplace_back(1); graph[3].emplace_back(2); graph[3].emplace_back(4); graph[3].emplace_back(5);
    graph[4].emplace_back(2); graph[4].emplace_back(3); graph[4].emplace_back(5); graph[4].emplace_back(7);
    graph[5].emplace_back(3); graph[5].emplace_back(4); graph[5].emplace_back(6);
    graph[6].emplace_back(5); graph[6].emplace_back(7);
    graph[7].emplace_back(4); graph[7].emplace_back(6);
    cache.resize(D + 1, vi(8, 0));
    cache[0][0] = 1;
}

int main(void) {
    Init();
    Solve();
    return 0;
}