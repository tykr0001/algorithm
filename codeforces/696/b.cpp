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
\*************  2021-01-20 00:14:26  *************/

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
vb prime;
vi cache;

void Eratos(void) {
	prime.resize(30000, true);
	for (int i = 2; i < 30000; i++) {
		if (prime[i]) {
			cache.push_back(i);
			for (int j = i * 2; j < 30000; j += i) {
				prime[j] = false;
			}
		}
	}
}

void Solve(void) {
	Eratos();
	while (T--) {
		int d;
		cin >> d;
		int d_1, d_2;
		int flag = 0;
		for (int i = 0; i < cache.size(); i++) {
			if (flag == 0 && cache[i] - 1 >= d) {
				d_1 = cache[i];
				flag++;
			}
			if (flag == 1 && cache[i] - d_1 >= d) {
				d_2 = cache[i];
				break;
			}
		}
		cout << d_1 * d_2 << endl;

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