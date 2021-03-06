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
\*************  2021-02-03 03:01:02  *************/

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

vector<int> arr;
vector<bool> mask;
int k;

void C(int idx, int depth) {
	if (depth == 6) {
		for (int i = 0; i < k; ++i) {
			if (mask[i] == true) {
				cout << arr[i] << " ";
			}
		}
		cout << endl;
	}
	for (int i = idx; i < k; ++i) {
		mask[i] = true;
		C(i + 1, depth + 1);
		mask[i] = false;
	}
}

void Solve(void) {
	while (1) {
		cin >> k;
		if (k == 0) break;
		arr.resize(k);
		mask.resize(k, false);
		for (int i = 0; i < k; ++i) {
			cin >> arr[i];
		}

		C(0, 0);
		cout << endl;
	}
}

void Init(void) {
	Boost;
}

int main(void) {
	Init();
	Solve();
	return 0;
}