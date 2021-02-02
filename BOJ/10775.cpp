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
\*************  2021-02-01 12:16:41  *************/

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

int G, P;
vi airplanes;
vi parent;
int answer;

int Find(int node) {
	if (node == -1 || parent[node] == node) {
		return node;
	}
	else {
		return parent[node] = Find(parent[node]);
	}
}

void Union(int a, int b) {
	parent[Find(a)] = Find(b);
}

void Solve(void) {
	for (int i = 0; i < P; i++) {
		if (Find(airplanes[i]) == 0) {
			break;
		}
		Union(Find(airplanes[i]), Find(airplanes[i]) - 1);
		answer++;
	}
	cout << answer << endl;
}

void Init(void) {
	Boost;
	cin >> G >> P;
	parent.resize(G + 1);
	airplanes.resize(P + 1);
	for (int i = 1; i <= G; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < P; i++) {
		cin >> airplanes[i];
	}
}

int main(void) {
	Init();
	Solve();
	return 0;
}