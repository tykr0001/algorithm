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
\*************  2021-02-09 12:48:22  *************/

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

int M, N;
vvi mat;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int answer;

bool CanGo(int i, int j) {
    return 0 <= i && i < M && 0 <= j && j < N;
}

void Solve(void) {
    q<pii> sq;
    sq.emplace(0, 0);
    while (!sq.empty()) {
        auto front = sq.front();
        sq.pop();
        for (int i = 0; i < 4; i++) {
            int x = front.fi + dx[i];
            int y = front.se + dy[i];
            if (CanGo(x, y) && mat[front.fi][front.se] > mat[x][y]) {
                if (x == M - 1 && y == N - 1) {
                    answer++;
                }
                else {
                    sq.emplace(x, y);
                }
            }
        }
    }

    cout << answer << endl;
}

void Init(void) {
    Boost;
    cin >> M >> N;
    mat.resize(M, vi(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }
}

int main(void) {
    Init();
    Solve();
    return 0;
}