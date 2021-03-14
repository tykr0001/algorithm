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
\*************  2021-03-15 01:38:22  *************/

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
#define For(i,beg,end) for(int i=beg; i<end; i++)
typedef long long ll;
/*************************************************/

struct Dice {
    int left;
    int right;
    int up;
    int down;
    int front;
    int back;
} dice;

int N, M, x, y, K;
vvi graph;
qi op_q;
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

bool CanGo(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M;
}

void Rotation(int op) {
    int tmp;
    if (op == 1) {
        tmp = dice.down;
        dice.down = dice.right;
        dice.right = dice.up;
        dice.up = dice.left;
        dice.left = tmp;
    }
    else if (op == 2) {
        tmp = dice.down;
        dice.down = dice.left;
        dice.left = dice.up;
        dice.up = dice.right;
        dice.right = tmp;
    }
    else if (op == 3) {
        tmp = dice.down;
        dice.down = dice.back;
        dice.back = dice.up;
        dice.up = dice.front;
        dice.front = tmp;
    }
    else if (op == 4) {
        tmp = dice.down;
        dice.down = dice.front;
        dice.front = dice.up;
        dice.up = dice.back;
        dice.back = tmp;
    }
}

void Solve(void) {
    while (!op_q.empty()) {
        int front = op_q.front();
        op_q.pop();
        x = x + dx[front];
        y = y + dy[front];
        if (!CanGo(x, y)) {
            x = x - dx[front];
            y = y - dy[front];
            continue;
        }
        Rotation(front);
        if (graph[x][y] == 0) {
            graph[x][y] = dice.down;
        }
        else {
            dice.down = graph[x][y];
            graph[x][y] = 0;
        }
        cout << dice.up << endl;
    }
}

void Init(void) {
    cin >> N >> M >> x >> y >> K;
    graph.resize(N, vi(M));
    For(i, 0, N) {
        For(j, 0, M) {
            cin >> graph[i][j];
        }
    }
    For(i, 0, K) {
        int op;
        cin >> op;
        op_q.emplace(op);
    }
    dice = { 0,0,0,0,0,0 };
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}