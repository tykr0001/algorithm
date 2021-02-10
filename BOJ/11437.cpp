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
\*************  2021-02-01 18:05:21  *************/

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

int N, M;
int timer;
vi euler;
vi depth;
vvi graph;
vi idx;
v<v<pii>> sparse_tree;

void DFS(int node, int parent, int d) {
	depth[node] = d;
	euler[++timer] = node;
	idx[node] = timer;
	for (auto elem : graph[node]) {
		if (elem != parent) {
			DFS(elem, node, d + 1);
			euler[++timer] = node;
		}
	}
}

void BuildSparseTree(void) {
	for (int i = 1; i <= 2 * N - 1; i++) {
		sparse_tree[0][i] = { depth[euler[i]], euler[i] };
	}

	for (int k = 1; k < ceil(log2(N)) + 1; k++) {
		for (int i = 1; i <= 2 * N - 1; i++) {
			if (i + (1 << k - 1) <= 2 * N - 1) {
				sparse_tree[k][i] = min(sparse_tree[k - 1][i], sparse_tree[k - 1][i + (1 << k - 1)]);
			}
		}
	}
}

int LCA(int a, int b) {
	a = idx[a];
	b = idx[b];
	if (a > b) {
		swap(a, b);
	}
	int k = floor(log2(b - a + 1));
	return min(sparse_tree[k][a], sparse_tree[k][b - (1 << k) + 1]).se;
}

void Solve(void) {
	DFS(1, 0, 0);
	BuildSparseTree();

	cin >> M;
	for (int i = 0; i < M; i++) {
		int src, dst;
		cin >> src >> dst;
		cout << LCA(src, dst) << endl;
	}
}

void Init(void) {
	Boost;
	cin >> N;
	sparse_tree.resize(ceil(log2(N)) + 1, v<pii>(2 * N));
	euler.resize(2 * N);
	depth.resize(N + 1);
	graph.resize(N + 1);
	idx.resize(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int src, dst;
		cin >> src >> dst;
		graph[src].emplace_back(dst);
		graph[dst].emplace_back(src);
	}
}

int main(void) {
	Init();
	Solve();
	return 0;
}