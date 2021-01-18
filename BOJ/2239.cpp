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
\*************  2021-01-16 17:28:22  *************/

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
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

int row[9];
int col[9];
int part[3][3];
v<string> sudoku(9);
v<pii> zero;
bool flag;

void BackTrack(int idx) {
    if (flag) {
        return;
    }
    if (idx == zero.size()) {
        for (int i = 0; i < 9; i++) {
            cout << sudoku[i] << endl;
        }
        flag = true;
    }
    else {
        for (int i = 1; i <= 9; i++) {
            if (!(row[zero[idx].fi] & (1 << i)) && !(col[zero[idx].se] & (1 << i))
                && !(part[zero[idx].fi / 3][zero[idx].se / 3] & (1 << i))) {
                row[zero[idx].fi] |= 1 << i;
                col[zero[idx].se] |= 1 << i;
                part[zero[idx].fi / 3][zero[idx].se / 3] |= 1 << i;
                sudoku[zero[idx].fi][zero[idx].se] = i + '0';
                BackTrack(idx + 1);
                row[zero[idx].fi] ^= 1 << i;
                col[zero[idx].se] ^= 1 << i;
                part[zero[idx].fi / 3][zero[idx].se / 3] ^= 1 << i;
                sudoku[zero[idx].fi][zero[idx].se] = '0';
            }
        }
    }
    return;
}

void Solve(void) {
    BackTrack(0);
    return;
}

void Init(void) {
    Boost;
    for (int i = 0; i < 9; i++) {
        cin >> sudoku[i];
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == '0') {
                zero.emplace_back(i, j);
            }
            part[i/3][j/3] |= (1 << sudoku[i][j] - '0');
            row[i] |= (1 << sudoku[i][j] - '0');
            col[j] |= (1 << sudoku[i][j] - '0');
        }
    }
    return;
}

int main(void) {
    Init();
    Solve();
    return 0;
}