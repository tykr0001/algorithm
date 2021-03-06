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
\*************  2021-02-03 04:50:03  *************/

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

int T;
int N;
vi cache;
vb is_prime;

void Eratos(void) {
	for (int i = 2; i <= 123456 * 2; i++) {
		if (is_prime[i]) {
			cache.emplace_back(i);
			for (int j = i * 2; j <= 123456 * 2; j += i) {
				is_prime[j] = false;
			}
		}
	}
}

void Solve(void) {
	while (1) {
		cin >> N;
		if (N == 0) {
			return;
		}
		auto lo = lower_bound(cache.begin(), cache.end(), N + 1);
		auto hi = upper_bound(cache.begin(), cache.end(), 2 * N);
		cout << distance(lo, hi) << endl;
	}

}

void Init(void) {
	is_prime.resize(123456 * 2 + 1, true);
	is_prime[0] = is_prime[1] = false;
	Eratos();
}

int main(void) {
	Boost;
	Init();
	Solve();
	return 0;
}