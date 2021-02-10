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
#define SIZE 8
int D;
v<v<ll>> graph(SIZE, v<ll>(SIZE, 0));

v<v<ll>> operator*(v<v<ll>> a, v<v<ll>> b) {
    v<v<ll>> ret(SIZE, v<ll>(SIZE, 0));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return ret;
}

v<v<ll>> ex(int n) {
    if (n == 1) {
        return graph;
    }
    v<v<ll>> tmp(ex(n / 2));
    if (n % 2) {
        return tmp * tmp * graph;
    }
    else {
        return tmp * tmp;
    }
}

void Solve(void) {
    cout << ex(D)[0][0] << endl;
}

void Init(void) {
    Boost;
    cin >> D;
    graph[0][1] = graph[0][2] = 1;
    graph[1][0] = graph[1][2] = graph[1][3] = 1;
    graph[2][0] = graph[2][1] = graph[2][3] = graph[2][4] = 1;
    graph[3][1] = graph[3][2] = graph[3][4] = graph[3][5] = 1;
    graph[4][2] = graph[4][3] = graph[4][5] = graph[4][7] = 1;
    graph[5][3] = graph[5][4] = graph[5][6] = 1;
    graph[6][5] = graph[6][7] = 1;
    graph[7][4] = graph[7][6] = 1;
}

int main(void) {
    Init();
    Solve();
    return 0;
}