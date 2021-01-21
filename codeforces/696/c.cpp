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
\*************  2021-01-19 23:12:10  *************/

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

void Solve(void) {
	while (T--) {
		int n;
		cin >> n;
		li a;
		vb selected(2 * n, false);
		list<pii> answer_pair;
		for (int i = 0; i < 2 * n; i++) {
			int inp;
			cin >> inp;
			a.emplace_back(inp);
		}
		sort(a.begin(), a.end(), greater<int>());
		int target = a.back();
		bool flag = true;
		for (auto i = a.begin(); i != a.end(); i++) {
			auto iter = lower_bound(a.begin(), a.end(), target - *i);
			if (*iter + *i == target) {
				target = *i;
				answer_pair.emplace_front(*iter, *i);
				i = a.erase(i);
				a.erase(iter);
			}
		}

		if (answer_pair.size() != n - 1) {
			cout << "NO" << endl;
		}
		else {
			answer_pair.emplace_back(a.front(),a.back());
			cout << "YES" << endl;
			cout << answer_pair.back().fi + answer_pair.back().se << endl;
			for (auto i : answer_pair) {
				cout << i.fi << " " << i.se << endl;
			}
		}
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