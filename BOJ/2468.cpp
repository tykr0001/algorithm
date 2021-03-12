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
\*************  2021-03-12 16:07:34  *************/

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
int max_height;
vvi graph;
vvb visited;
q<pii> sq;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool CanGo(int i, int j, int height) {
    return 0 <= i && i < N && 0 <= j && j < N && !visited[i][j] && graph[i][j] > height;
}

void BFS(int i, int j, int height) {
    sq.emplace(i, j);
    visited[i][j] = true;
    while (!sq.empty()) {
        auto front = sq.front();
        sq.pop();
        for (int k = 0; k < 4; k++) {
            int x = front.fi + dx[k];
            int y = front.se + dy[k];
            if (CanGo(x, y, height)) {
                sq.emplace(x, y);
                visited[x][y] = true;
            }
        }
    }
}

void Solve(void) {
    for (int k = 0; k < max_height; k++) {
        int cnt = 0;
        visited.clear();
        visited.resize(N, vb(N, false));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (CanGo(i, j, k)) {
                    BFS(i, j, k);
                    cnt++;
                }
            }
        }
        answer = max(answer, cnt);
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> N;
    graph.resize(N, vi(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
            max_height = max(max_height, graph[i][j]);
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}