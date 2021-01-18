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
#define INF 1e9
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

int R, C;
int answer = 0;
vb visited(25);
v<string> graph;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void BackTrack(const pii& loc, int depth) {
    answer = max(answer, depth);
    for (int i = 0; i < 4; i++) {
        int x = loc.fi + dx[i];
        int y = loc.se + dy[i];
        if (0 <= x && x < R && 0 <= y && y < C && !visited[graph[x][y] - 'A']) {
            visited[graph[x][y] - 'A'] = true;
            BackTrack({ x,y }, depth + 1);
            visited[graph[x][y] - 'A'] = false;
        }
    }

}

void Solve(void) {
    visited[graph[0][0] - 'A'] = true;
    BackTrack({ 0,0 }, 1);
    cout << answer << endl;
    return;
}

void Init(void) {
    Boost;
    cin >> R >> C;
    graph.resize(R);
    for (int i = 0; i < R; i++) {
        cin >> graph[i];
    }
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}