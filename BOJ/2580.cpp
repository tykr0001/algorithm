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
\*************  2021-03-15 22:55:37  *************/

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

int row[9];
int col[9];
int part[3][3];
vvi sudoku(9, vi(9));
v<pii> zero;
bool flag;

void BackTrack(v<pii>::iterator it) {
	if (flag) {
		return;
	}
	if (it == zero.end()) {
		For(i, 0, 9) {
			For(j, 0, 9) {
				cout << sudoku[i][j] << ' ';
			}
			cout << endl;
		}
		flag = true;
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (!(row[it->fi] & (1 << i)) && !(col[it->se] & (1 << i))
				&& !(part[it->fi / 3][it->se / 3] & (1 << i))) {
				row[it->fi] |= 1 << i;
				col[it->se] |= 1 << i;
				part[it->fi / 3][it->se / 3] |= 1 << i;
				sudoku[it->fi][it->se] = i;
				BackTrack(it + 1);
				row[it->fi] ^= 1 << i;
				col[it->se] ^= 1 << i;
				part[it->fi / 3][it->se / 3] ^= 1 << i;
				sudoku[it->fi][it->se] = 0;
			}
		}
	}
	return;
}

void Solve(void) {
	BackTrack(zero.begin());
	return;
}

void Init(void) {
	Boost;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0) {
				zero.emplace_back(i, j);
			}
			part[i / 3][j / 3] |= (1 << sudoku[i][j]);
			row[i] |= (1 << sudoku[i][j]);
			col[j] |= (1 << sudoku[i][j]);
		}
	}
	return;
}

int main(void) {
	Init();
	Solve();
	return 0;
}