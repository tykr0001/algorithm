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
\*************  2021-03-13 01:43:54  *************/

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

int L;
int answer;
int ii, ij;
int gi, gj;

int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool CanGo(int i, int j) {
    return 0 <= i && i < L && 0 <= j && j < L;
}

void BFS(int i, int j) {
    q<p<pii, int>> sq;
    sq.push({ {i, j}, 0 });
    vvb visited;
    visited.resize(L, vb(L));
    visited[i][j] = true;
    while (!sq.empty()) {
        auto front = sq.front();
        sq.pop();
        if (front.fi.fi == gi && front.fi.se == gj) {
            cout << front.se << endl;
            break;
        }
        For(k, 8) {
            int x = front.fi.fi + dx[k];
            int y = front.fi.se + dy[k];
            if (CanGo(x, y) && !visited[x][y]) {
                sq.push({ {x, y}, front.se + 1 });
                visited[x][y] = true;
            }
        }
    }
}

void Solve(void) {
    BFS(ii, ij);
}

void Init(void) {
    cin >> L;
    cin >> ii >> ij >> gi >> gj;
    answer = 0;
}

int main(void) {
    Boost;
    int T; cin >> T;
    while (T--) {
        Init();
        Solve();
    }
    return 0;
}