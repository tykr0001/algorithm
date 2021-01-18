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
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

int kSize;
int answer[2];
vvi graph;
vvi colors;
vvi searched;
v<pii> blank;
int dx[4] = { 1,-1,1,-1 };
int dy[4] = { 1,1,-1,-1 };

void Check(const pii& node) {
    int x = node.fi;
    int y = node.se;
    searched[x][y]++;
    for (int i = 0; i < 4; i++) {
        int j = 1;
        while (0 <= x + j * dx[i] && x + j * dx[i] < kSize
            && 0 <= y + j * dy[i] && y + j * dy[i] < kSize) {
            searched[x + j * dx[i]][y + j * dy[i]]++;
            j++;
        }
    }
}

void Uncheck(const pii& node) {
    int x = node.fi;
    int y = node.se;
    searched[x][y]--;
    for (int i = 0; i < 4; i++) {
        int j = 1;
        while (0 <= x + j * dx[i] && x + j * dx[i] < kSize
            && 0 <= y + j * dy[i] && y + j * dy[i] < kSize) {
            searched[x + j * dx[i]][y + j * dy[i]]--;
            j++;
        }
    }
}

void Solve(const int idx, const int depth, int color) {
    answer[color] = max(answer[color], depth);

    for (int i = idx + 1; i < blank.size(); i++) {
        int x = blank[i].fi;
        int y = blank[i].se;
        if (colors[x][y] == color && searched[x][y] == 0) {
            Check(blank[i]);
            Solve(i, depth + 1, color);
            Uncheck(blank[i]);
        }
    }
    return;
}

void Init(void) {
    Boost;
    cin >> kSize;
    graph.resize(kSize, vi(kSize, 0));
    colors.resize(kSize, vi(kSize, 0));
    searched.resize(kSize, vi(kSize, 0));
    for (int i = 0; i < kSize; i++) {
        for (int j = 0; j < kSize; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 1) {
                blank.emplace_back(i, j);
            }
            if ((i + j) % 2) {
                colors[i][j] = 1;
            }
        }
    }
    return;
}

int main(void) {
    Init();
    Solve(-1, 0, 0);
    Solve(-1, 0, 1);
    cout << answer[0] + answer[1] << endl;
    return 0;
}