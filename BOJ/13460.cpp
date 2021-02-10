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
\*************  2021-02-06 05:05:36  *************/

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

struct BallState {
    int depth;
    int rx;
    int ry;
    int bx;
    int by;
};

int N, M;
v<string> board;
v<v<v<vb>>> visited;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int answer;
int hx, hy;
int rx, ry;
int bx, by;

void MoveBall(int& x, int& y, int dir) {
    while (1) {
        x += dx[dir];
        y += dy[dir];
        if (board[x][y] == '#') {
            x -= dx[dir];
            y -= dy[dir];
            break;
        }
        else if (board[x][y] == 'O') {
            break;
        }
    }
}

void BFS() {
    q<BallState> sq;
    sq.push({ 0, rx, ry, bx, by });
    visited[rx][ry][bx][by] = true;
    while (!sq.empty()) {
        BallState front = sq.front();
        sq.pop();

        if (front.depth > 10) {
            break;
        }
        if (front.rx == hx && front.ry == hy) {
            answer = front.depth;
            break;
        }

        for (int dir = 0; dir < 4; dir++) {
            int rx = front.rx;
            int ry = front.ry;
            int bx = front.bx;
            int by = front.by;
            MoveBall(rx, ry, dir);
            MoveBall(bx, by, dir);

            if (bx == hx && by == hy) {
                continue;
            }

            if (rx == bx && ry == by) {
                switch (dir) {
                case 0:
                    front.ry > front.by ? by-- : ry--;
                    break;
                case 1:
                    front.ry > front.by ? ry++ : by++;
                    break;
                case 2:
                    front.rx > front.bx ? bx-- : rx--;
                    break;
                case 3:
                    front.rx > front.bx ? rx++ : bx++;
                    break;
                default:
                    break;
                }
            }

            if (!visited[rx][ry][bx][by]) {
                sq.push({ front.depth + 1, rx, ry, bx, by });
                visited[rx][ry][bx][by] = true;
            }
        }
    }
}

void Solve(void) {
    BFS();
    cout << answer << endl;
}

void Init(void) {
    Boost;
    cin >> N >> M;
    answer = -1;
    board.resize(N);
    visited.resize(N, v<v<vb>>(M, v<vb>(N, vb(M, false))));
    for (int i = 0; i < N; i++) {
        cin >> board[i];
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'O') {
                hx = i; hy = j;
            }
            if (board[i][j] == 'R') {
                rx = i; ry = j;
            }
            if (board[i][j] == 'B') {
                bx = i; by = j;
            }
        }
    }
}

int main(void) {
    Init();
    Solve();
    return 0;
}