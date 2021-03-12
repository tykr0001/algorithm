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
\*************  2021-03-12 21:49:43  *************/

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
#define For(i,n) for(int i=0; i<n; i++)
typedef long long ll;
/*************************************************/

int N, M;
int r, c, d;
int answer;
int cnt = 10;
vvi graph;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool CanGo(int i, int j) {
    return graph[i][j] != 1;
}

void Solve(void) {
    while (true) {
        if (graph[r][c] == 0)
            answer++;
        graph[r][c] = cnt++;

        bool flag = false;
        for (int k = d + 1; k < d + 5; k++) {
            int x = r + dx[k % 4];
            int y = c + dy[k % 4];
            if (CanGo(x, y) && graph[x][y] == 0) {
                r = x;
                c = y;
                d = k;
                flag = true;
                break;
            }
        }
        if (!flag) {
            int x = r + dx[(d + 2) % 4];
            int y = c + dy[(d + 2) % 4];
            if (CanGo(x, y)) {
                r = x;
                c = y;
            }
            else {
                break;
            }
        }
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> N >> M;
    cin >> r >> c >> d;
    if (d == 1) d = 3;
    else if (d == 3) d = 1;
    graph.resize(N, vi(M));
    For(i, N) {
        For(j, M) {
            cin >> graph[i][j];
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}