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
\*************  2021-03-25 08:50:03  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define v vector
#define vi vector<int> 
#define vvi vector<vector<int>>
#define vb vector<bool> 
#define vvb vector<vector<bool>> 
#define vs vector<string> 
#define vc vector<char> 
#define vl vector<ll> 
#define vvl vector<vector<ll>> 
#define pii pair<int,int>
#define pll pair<ll,ll> 
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF INT32_MAX
#define LINF INT64_MAX
#define endl '\n'
#define rep(i,beg,end) for(int i=beg; i<end; i++)
typedef long long ll;
/*************************************************/

int row, col;
int answer = INF;
vvi room;
vvi cache;
vpii camera;

int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

bool CanGo(pii pos) {
    return 0 <= pos.fi && pos.fi < row && 0 <= pos.se && pos.se < col&& room[pos.fi][pos.se] != 6;
}

void View(pii pos, int k, int toggle) {
    while (CanGo(pos)) {
        if (toggle == 1)
            cache[pos.fi][pos.se]++;
        if (toggle == 0)
            cache[pos.fi][pos.se]--;
        pos.fi += di[k];
        pos.se += dj[k];
    }
}

void Backtrack(int idx) {
    if (idx == camera.size()) {
        int cnt = 0;
        rep(i, 0, row) {
            rep(j, 0, col) {
                if (cache[i][j] == 0 && room[i][j] != 6)
                    cnt++;
            }
        }
        answer = min(answer, cnt);
        return;
    }

    switch (room[camera[idx].fi][camera[idx].se]) {
    case 1:
        rep(k, 0, 4) {
            View(camera[idx], k, 1);
            Backtrack(idx + 1);
            View(camera[idx], k, 0);
        }
        break;

    case 2:
        rep(k, 0, 2) {
            View(camera[idx], k, 1);
            View(camera[idx], (k + 2) % 4, 1);
            Backtrack(idx + 1);
            View(camera[idx], k, 0);
            View(camera[idx], (k + 2) % 4, 0);
        }
        break;

    case 3:
        rep(k, 0, 4) {
            View(camera[idx], k, 1);
            View(camera[idx], (k + 1) % 4, 1);
            Backtrack(idx + 1);
            View(camera[idx], k, 0);
            View(camera[idx], (k + 1) % 4, 0);
        }
        break;

    case 4:
        rep(k, 0, 4) {
            View(camera[idx], k, 1);
            View(camera[idx], (k + 1) % 4, 1);
            View(camera[idx], (k + 2) % 4, 1);
            Backtrack(idx + 1);
            View(camera[idx], k, 0);
            View(camera[idx], (k + 1) % 4, 0);
            View(camera[idx], (k + 2) % 4, 0);
        }
        break;

    case 5:
        rep(k, 0, 4)
            View(camera[idx], k, 1);
        Backtrack(idx + 1);
        rep(k, 0, 4)
            View(camera[idx], k, 0);
        break;

    default:
        break;
    }
}

void Solve(void) {
    Backtrack(0);
    cout << answer;
}

void Init(void) {
    cin >> row >> col;
    room.resize(row, vi(col));
    cache.resize(row, vi(col));
    rep(i, 0, row) {
        rep(j, 0, col) {
            cin >> room[i][j];
            if (0 < room[i][j] && room[i][j] < 6) {
                camera.emplace_back(i, j);
            }
        }
    }
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}