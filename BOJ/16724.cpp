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
\*************  2021-02-08 11:41:54  *************/

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

int N, M;
v<string> mat;
v<v<pii>> parent;
vvb searched;
int answer;

pii Find(pii node) {
    if (parent[node.fi][node.se] == make_pair(-1, -1) || parent[node.fi][node.se] == node) {
        return node;
    }
    else {
        return parent[node.fi][node.se] = Find(parent[node.fi][node.se]);
    }
}

void Union(pii a, pii b) {
    parent[Find(a).fi][Find(a).se] = Find(b);
}

void DFS(pii init) {
    s<pii> ss;
    ss.emplace(init);
    searched[init.fi][init.se] = true;
    while (!ss.empty()) {
        auto top = ss.top();
        ss.pop();
        int i = top.fi;
        int j = top.se;
        searched[i][j] = true;
        if (mat[i][j] == 'R') {
            if (!searched[i][j + 1]) {
                ss.emplace(i, j + 1);
            }
            Union({ i,j }, { i,j + 1 });
        }
        else if (mat[i][j] == 'L') {
            if (!searched[i][j - 1]) {
                ss.emplace(i, j - 1);
            }
            Union({ i,j }, { i,j - 1 });
        }
        else if (mat[i][j] == 'U') {
            if (!searched[i - 1][j]) {
                ss.emplace(i - 1, j);
            }
            Union({ i,j }, { i - 1,j });
        }
        else {
            if (!searched[i + 1][j]) {
                ss.emplace(i + 1, j);
            }
            Union({ i,j }, { i + 1,j });
        }
    }
}

void Solve(void) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!searched[i][j]) {
                DFS({ i, j });
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (parent[i][j] == make_pair(i, j)) {
                answer++;
            }
        }
    }
    cout << answer << endl;
}

void Init(void) {
    Boost;
    cin >> N >> M;
    mat.resize(N);
    parent.resize(N, v<pii>(M, { -1, -1 }));
    searched.resize(N, vb(M, false));
    for (int i = 0; i < N; i++) {
        cin >> mat[i];
    }
}

int main(void) {
    Init();
    Solve();
    return 0;
}