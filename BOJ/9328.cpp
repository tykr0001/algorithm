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
\*************  2021-01-21 13:22:39  *************/

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
#define INF 2e9
#define LINF 9e18
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

int T;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void Solve(void) {
    while (T--) {
        int h, w;
        int answer = 0;
        cin >> h >> w;
        v<string> graph(h);
        vb have_key(26, false);
        v<v<pii>> doors(26);
        q<pii> search_queue;
        vvb visited(h, vb(w, false));

        for (int i = 0; i < h; i++) {
            cin >> graph[i];
        }
        string init_key;
        cin >> init_key;
        if (init_key[0] != '0') {
            for (int i = 0; i < init_key.length(); i++) {
                have_key[init_key[i] - 'a'] = true;
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if ((i == 0 || j == 0 || i == h - 1 || j == w - 1) && graph[i][j] != '*') {
                    visited[i][j] = true;
                    if (graph[i][j] == '.') {
                        search_queue.emplace(i, j);
                    }
                    if (graph[i][j] == '$') {
                        answer++;
                        search_queue.emplace(i, j);
                    }
                    if ('a' <= graph[i][j] && graph[i][j] <= 'z') {
                        search_queue.emplace(i, j);
                        have_key[graph[i][j] - 'a'] = true;
                        while (!doors[graph[i][j] - 'a'].empty()) {
                            auto& back = doors[graph[i][j] - 'a'].back();
                            search_queue.emplace(back.fi, back.se);
                            doors[graph[i][j] - 'a'].pop_back();
                        }
                    }
                    if ('A' <= graph[i][j] && graph[i][j] <= 'Z') {
                        if (have_key[graph[i][j] - 'A']) {
                            search_queue.emplace(i, j);
                        }
                        else {
                            doors[graph[i][j] - 'A'].emplace_back(i, j);
                        }
                    }
                }
            }
        }

        while (!search_queue.empty()) {
            auto front = search_queue.front();
            search_queue.pop();
            for (int i = 0; i < 4; i++) {
                int x = front.fi + dx[i];
                int y = front.se + dy[i];
                if (0 <= x && x < h && 0 <= y && y < w && !visited[x][y] && graph[x][y] != '*') {
                    visited[x][y] = true;
                    if (graph[x][y] == '.') {
                        search_queue.emplace(x, y);
                    }
                    if (graph[x][y] == '$') {
                        answer++;
                        search_queue.emplace(x, y);
                    }
                    if ('a' <= graph[x][y] && graph[x][y] <= 'z') {
                        search_queue.emplace(x, y);
                        have_key[graph[x][y] - 'a'] = true;
                        while (!doors[graph[x][y] - 'a'].empty()) {
                            auto& back = doors[graph[x][y] - 'a'].back();
                            search_queue.emplace(back.fi, back.se);
                            doors[graph[x][y] - 'a'].pop_back();
                        }
                    }
                    if ('A' <= graph[x][y] && graph[x][y] <= 'Z') {
                        if (have_key[graph[x][y] - 'A']) {
                            search_queue.emplace(x, y);
                        }
                        else {
                            doors[graph[x][y] - 'A'].emplace_back(x, y);
                        }
                    }
                }
            }
        }
        cout << answer << endl;
    }

    return;
}

void Init(void) {
    Boost;
    cin >> T;
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}