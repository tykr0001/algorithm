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
\*************  2021-01-16 13:41:46  *************/

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
#define INF 1e9
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

int N;
int answer = INF;
vvi W;
int cache[16][1 << 16]; // [src][visited]

// 현재상태에서 탐색 진행할 경우 최소 거리
int TSP(int dst, int path) {
    if (cache[dst][path]) {
        return cache[dst][path];
    }
    if (path == (1<<N)-1) {
        if(W[dst][0] == 0){
            return INF;
        }
        else{
            return W[dst][0];
        }
    }
    else {
        cache[dst][path] = INF;
        for (int i = 0; i < N; i++) {
            if (i != dst && W[dst][i] != INF && !((path >> i) & 1)) {
                cache[dst][path] = min(cache[dst][path], TSP(i, path | (1 << i)) + W[dst][i]);
            }
        }
        return cache[dst][path];
    }
}

void Solve(void) {
    answer = TSP(0, 1);
    cout << answer << endl;
    return;
}

void Init(void) {
    Boost;
    cin >> N;
    W.resize(N, vi(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];
            if (W[i][j] == 0 && i != j) {
                W[i][j] = INF;
            }
        }
    }
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}