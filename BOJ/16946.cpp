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
\*************  2021-02-08 13:56:42  *************/

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

v<string> mat;
vvi elem;
int N, M;
v<v<pii>> parent;
vvb searched;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

pii Find(pii node) {
    if (parent[node.fi][node.se] == pii({ -1, -1 }) || parent[node.fi][node.se] == node) {
        return node;
    }
    else {
        return parent[node.fi][node.se] = Find(parent[node.fi][node.se]);
    }
}

void Union(pii a, pii b) {
    parent[Find(a).fi][Find(a).se] = Find(b);
}

bool CanGo(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M&& mat[i][j] == '0';
}

void BFS(pii init) {
    q<pii> sq;
    sq.emplace(init);
    searched[init.fi][init.se] = true;
    while (!sq.empty()) {
        auto front = sq.front();
        sq.pop();
        for (int dir = 0; dir < 4; dir++) {
            int i = front.fi + dx[dir];
            int j = front.se + dy[dir];
            if (CanGo(i, j) && !searched[i][j]) {
                sq.emplace(i, j);
                searched[i][j] = true;
                pii rt(Find(front));
                pii ch(Find({ i, j }));
                if (rt != ch) {
                    elem[rt.fi][rt.se] += elem[ch.fi][ch.se];
                    Union(ch, rt);
                }
            }
        }
    }
}

void Solve(void) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!searched[i][j] && mat[i][j] == '0') {
                BFS({ i,j });
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int answer;
            if (mat[i][j] == '0') {
                answer = 0;
            }
            else {
                set<pii> childs;
                answer = 1;
                for (int dir = 0; dir < 4; dir++) {
                    int x = i + dx[dir];
                    int y = j + dy[dir];
                    if (CanGo(x, y)) {
                        pii ch(Find({ x, y }));
                        if (childs.find(ch) == childs.end()) {
                            childs.insert(ch);
                            answer += elem[ch.fi][ch.se];
                        }
                    }
                }
            }
            cout << answer % 10;
        }
        cout << endl;
    }
}

void Init(void) {
    Boost;
    cin >> N >> M;
    mat.resize(N);
    parent.resize(N, v<pii>(M, { -1, -1 }));
    searched.resize(N, vb(M, false));
    elem.resize(N, vi(M, 1));
    for (int i = 0; i < N; i++) {
        cin >> mat[i];
    }
}

int main(void) {
    Init();
    Solve();
    return 0;
}