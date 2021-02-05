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
#define INF INT32_answer
#define LINF INT64_answer
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<endl;
typedef long long ll;
/*************************************************/

int N, M;
int answer = 0;
vector<vector<int>> arr;
vector<vector<bool>> mask;

void Solve(void) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int temp = 0;
			if (i + 3 < N) { // 아래로 1자
				temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j];
				if (answer < temp)
					answer = temp;
			}

			if (j + 3 < M) { // 오른쪽로 1자
				temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
				if (answer < temp)
					answer = temp;
			}

			if (i + 1 < N && j + 1 < M) { // 네모
				temp = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];
				if (answer < temp)
					answer = temp;
			}

			if (i + 2 < N && j + 1 < M) {
				temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1];
				if (answer < temp)
					answer = temp;
				temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1];
				if (answer < temp)
					answer = temp;
				temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i][j + 1];
				if (answer < temp)
					answer = temp;
				temp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
				if (answer < temp)
					answer = temp;
			}

			if (i + 2 < N && 0 <= j - 1) {
				temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j - 1];
				if (answer < temp)
					answer = temp;
				temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j - 1];
				if (answer < temp)
					answer = temp;
				temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i][j - 1];
				if (answer < temp)
					answer = temp;
				temp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j - 1] + arr[i + 2][j - 1];
				if (answer < temp)
					answer = temp;
			}


			if (j + 2 < M && i + 1 < N) {
				temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2];
				if (answer < temp)
					answer = temp;
				temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1];
				if (answer < temp)
					answer = temp;
				temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j];
				if (answer < temp)
					answer = temp;
				temp = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
				if (answer < temp)
					answer = temp;
			}

			if (j + 2 < M && 0 <= i - 1) {
				temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 2];
				if (answer < temp)
					answer = temp;
				temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 1];
				if (answer < temp)
					answer = temp;
				temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j];
				if (answer < temp)
					answer = temp;
				temp = arr[i][j] + arr[i][j + 1] + arr[i - 1][j + 1] + arr[i - 1][j + 2];
				if (answer < temp)
					answer = temp;
			}

		}
	}
	cout << answer;
}

void Init(void) {
	Boost;
	cin >> N >> M;
	arr.resize(N, vector<int>(M, 0));
	mask.resize(N, vector<bool>(M, false));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
		}
	}
}
int main(void) {
	Init();
	Solve();
	return 0;
}