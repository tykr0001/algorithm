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
\*************  2021-03-12 02:50:37  *************/

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

int w, h;
int answer;
vvi graph;
vvb visited;
int dx[8] = { 0,0,-1,1,-1,-1,1,1 };
int dy[8] = { -1,1,0,0,-1,1,-1,1 };

bool CanGo(int i, int j) {
    return 0 <= i && i < h && 0 <= j && j < w
        && graph[i][j] == 1 && !visited[i][j];
}

void BFS(int i, int j) {
    q<pii> sq;
    sq.emplace(i, j);
    visited[i][j] = true;
    while (!sq.empty()) {
        auto front = sq.front();
        sq.pop();
        for (int k = 0; k < 8; k++) {
            int x = front.fi + dx[k];
            int y = front.se + dy[k];
            if (CanGo(x, y)) {
                sq.emplace(x, y);
                visited[x][y] = true;
            }
        }
    }
}

void Solve(void) {
    while (true) {
        answer = 0;
        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }
        graph.clear();
        graph.resize(h, vi(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> graph[i][j];
            }
        }
        visited.clear();
        visited.resize(h, vb(w, false));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (CanGo(i, j)) {
                    BFS(i, j);
                    answer++;
                }
            }
        }
        cout << answer << endl;
    }
}

void Init(void) {
    ;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}