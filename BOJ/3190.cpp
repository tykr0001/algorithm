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
\*************  2021-03-15 00:24:40  *************/

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

struct OP {
    int time;
    int turn;
};

int N, K, L;
int dir;
int answer;
// 0=>blank, 1=>apple, 2=>snake
vvi graph;
q<OP> OP_q;
deque<pii> snake;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

bool CanGo(int i, int j) {
    return 1 <= i && i <= N && 1 <= j && j <= N && graph[i][j] != 2;
}

void Solve(void) {
    snake.emplace_front(1, 1);
    graph[1][1] = 2;
    while (1) {
        answer++;
        int x = snake.front().first + dx[dir];
        int y = snake.front().second + dy[dir];
        if (CanGo(x, y)) {
            snake.emplace_front(x, y);
            if (graph[x][y] != 1) {
                graph[snake.back().first][snake.back().second] = 0;
                snake.pop_back();
            }
            graph[x][y] = 2;
        }
        else {
            break;
        }
        if (!OP_q.empty() && OP_q.front().time == answer) {
            dir += OP_q.front().turn + 4;
            dir %= 4;
            OP_q.pop();
        }
    }
    cout << answer << endl;
}

void Init(void) {
    cin >> N >> K;
    graph.resize(N + 1, vi(N + 1));
    For(i, K) {
        int row, col;
        cin >> row >> col;
        graph[row][col] = 1;
    }
    cin >> L;
    For(i, L) {
        int X; char C;
        cin >> X >> C;
        if (C == 'L') {
            OP_q.push({ X,-1 });
        }
        else {
            OP_q.push({ X,1 });
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}