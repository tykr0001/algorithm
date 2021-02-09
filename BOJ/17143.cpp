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
#define INF INT32_MAX
#define LINF INT64_MAX
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

typedef struct {
    int r, c, sp, d, z, idx;
} shark;

int R, C, M;
v<vvi> mat;
v<shark> sharks;
int cnt;
int answer;

bool Compare(int i, int j) {
    return sharks[i].z > sharks[j].z;
}

void Solve(void) {
    for (int j = 0; j < C; j++) {
        // Fishing
        for (int i = 0; i < R; i++) {
            if (mat[i][j].size() != 0) {
                answer += sharks[mat[i][j][0]].z;
                sharks[mat[i][j][0]].idx = -1;
                mat[i][j].clear();
                break;
            }
        }

        // MoveShark
        for (int i = 0; i < M; i++) {
            if (sharks[i].idx != -1) {
                mat[sharks[i].r][sharks[i].c].clear();
            }
        }
        for (int i = 0; i < M; i++) {
            if (sharks[i].idx != -1) {
                int& r = sharks[i].r;
                int& c = sharks[i].c;
                int& sp = sharks[i].sp;
                int& d = sharks[i].d;

                switch (d)                 {
                case 1:
                    r -= sp;
                    if (r < 0) {
                        d = 2;
                        r = 0 - r;
                    }
                    if (r >= R) {
                        d = 1;
                        r = (R - 1) - (r - (R - 1));
                    }
                    break;
                case 2:
                    r += sp;
                    if (r >= R) {
                        d = 1;
                        r = (R - 1) - (r - (R - 1));
                    }
                    if (r < 0) {
                        d = 2;
                        r = 0 - r;
                    }
                    break;
                case 3:
                    c += sp;
                    if (c >= C) {
                        d = 4;
                        c = (C - 1) - (c - (C - 1));
                    }
                    if (c < 0) {
                        d = 3;
                        c = 0 - c;
                    }
                    break;
                case 4:
                    c -= sp;
                    if (c < 0) {
                        d = 3;
                        c = 0 - c;
                    }
                    if (c >= C) {
                        d = 4;
                        c = (C - 1) - (c - (C - 1));
                    }
                    break;

                default:
                    break;
                }
                mat[r][c].emplace_back(i);
            }
        }

        // KillShark
        for (int i = 0; i < R; i++) {
            for (int k = 0; k < C; k++) {
                if (mat[i][k].size() > 1) {
                    sort(mat[i][k].begin(), mat[i][k].end(), Compare);
                    int alive = mat[i][k][0];
                    for (int m = 1; m < mat[i][k].size(); m++) {
                        sharks[mat[i][k][m]].idx = -1;
                    }
                    mat[i][k].clear();
                    mat[i][k].emplace_back(alive);
                }
            }
        }
    }
    cout << answer << endl;
}

void Init(void) {
    Boost;
    cin >> R >> C >> M;
    mat.resize(R, vvi(C, vi(0)));
    sharks.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> sharks[i].r >> sharks[i].c >> sharks[i].sp >> sharks[i].d >> sharks[i].z;
        sharks[i].idx = cnt;
        if (sharks[i].d == 1 || sharks[i].d == 2) {
            sharks[i].sp %= 2 * (R - 1);
        }
        else {
            sharks[i].sp %= 2 * (C - 1);
        }
        sharks[i].r--;
        sharks[i].c--;
        mat[sharks[i].r][sharks[i].c].emplace_back(cnt++);
    }
}

int main(void) {
    Init();
    Solve();
    return 0;
}