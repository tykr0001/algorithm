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
\*************  2021-01-15 13:54:36  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define LL long long
#define pb push_back
#define eb emplace_back
#define v vector 
#define s stack
#define q queue 
#define l list 
#define p pair
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define Deb(x) cout<<#x<<"="<<x<<end;
/*************************************************/

int n, m;
vector<int> parent;

int Find(int idx) {
	if (parent[idx] == idx) {
		return idx;
	}
	else {
		return parent[idx] = Find(parent[idx]);
	}
}

void Union(int src, int dst) {
	parent[Find(src)] = Find(dst);
}

void Solve(void) {
	while (m--) {
		int op, src, dst;
		cin >> op >> src >> dst;
		if (op == 0) {
			Union(src, dst);
		}
		else {
			if (Find(src) == Find(dst)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
}

void Init(void) {
	Boost;
	cin >> n >> m;
	parent.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
}

int main(void) {
	Init();
	Solve();
	return 0;
}