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
\*************  2021-02-08 20:51:40  *************/

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

int N;
vvi cost;
vvi cache;
int answer = INF;

void Solve(void) {
	cache.clear();
	cache.resize(N, vi(3, INF));
	cache[0][0] = cost[0][0];
	cache[1][1] = cache[0][0] + cost[1][1];
	cache[1][2] = cache[0][0] + cost[1][2];
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j < 3; j++) {
			if (cache[i][j] != INF) {
				for (int k = 0; k < 3; k++) {
					if (j != k) {
						cache[i + 1][k] = min(cache[i + 1][k], cache[i][j] + cost[i + 1][k]);
					}
				}
			}
		}
	}
	answer = min(answer, min(cache[N - 1][1], cache[N - 1][2]));

	cache.clear();
	cache.resize(N, vi(3, INF));
	cache[0][1] = cost[0][1];
	cache[1][0] = cache[0][1] + cost[1][0];
	cache[1][2] = cache[0][1] + cost[1][2];
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j < 3; j++) {
			if (cache[i][j] != INF) {
				for (int k = 0; k < 3; k++) {
					if (j != k) {
						cache[i + 1][k] = min(cache[i + 1][k], cache[i][j] + cost[i + 1][k]);
					}
				}
			}
		}
	}
	answer = min(answer, min(cache[N - 1][0], cache[N - 1][2]));

	cache.clear();
	cache.resize(N, vi(3, INF));
	cache[0][2] = cost[0][2];
	cache[1][1] = cache[0][2] + cost[1][1];
	cache[1][0] = cache[0][2] + cost[1][0];
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j < 3; j++) {
			if (cache[i][j] != INF) {
				for (int k = 0; k < 3; k++) {
					if (j != k) {
						cache[i + 1][k] = min(cache[i + 1][k], cache[i][j] + cost[i + 1][k]);
					}
				}
			}
		}
	}
	answer = min(answer, min(cache[N - 1][1], cache[N - 1][0]));

	cout << answer << endl;
}

void Init(void) {
	Boost;
	cin >> N;
	cost.resize(N, vi(3));
	for (int i = 0; i < N; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

}

int main(void) {
	Init();
	Solve();
	return 0;
}