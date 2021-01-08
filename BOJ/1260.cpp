#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

void DFS(int V, int N, vector<vector<bool>>& adj, vector<bool>& visited);
void BFS(int V, int N, vector<vector<bool>>& adj, vector<bool>& visited, queue<int> q);

int main(void) {
	int N, M, V;
	queue<int> q;

	cin >> N >> M >> V;

	vector<vector<bool>> adj(N + 1, vector<bool>(N + 1, false));
	vector<bool> visited(N + 1, false);

	for (int i = 0; i < M; ++i) {
		int from, to;
		cin >> from >> to;
		adj[from][to] = true;
		adj[to][from] = true;
	}
	visited[V] = true;
	
	DFS(V, N, adj, visited);
	cout << '\n';
	visited.clear();
	visited.assign(N + 1, false);
	BFS(V, N, adj, visited, q);
	cout << '\n';

	return 0;
}

void DFS(int V, int N, vector<vector<bool>>& adj, vector<bool>& visited) {
	cout << V << ' ';

	for (int i = 1; i <= N; ++i) {
		if (adj[V][i] && !visited[i]) {
			visited[i] = true;
			DFS(i, N, adj, visited);
		}
	}
}
void BFS(int V, int N, vector<vector<bool>>& adj, vector<bool>& visited, queue<int> q) {
	q.push(V);
	visited[V] = true;

	while (!q.empty()) {
		V = q.front();
		q.pop();
		cout << V << ' ';
		for (int i = 1; i <= N; ++i) {
			if (adj[V][i] && !visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}