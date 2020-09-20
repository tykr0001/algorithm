#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include <limits.h>

using namespace std;

int TSP(vector<vector<int>>& W, vector<bool>& visited, vector<int>& path, const int N, const int len) {
	if (path.size() == N) {
		if (W[path.back()][0] != 0)
			return len + W[path.back()][0];
		else
			return INT_MAX;
	}
	int ret = INT_MAX;

	for (int next = 0; next < N; ++next) {
		int cur = path.back();
		if (visited[next] == true || W[cur][next] == 0)
			continue;
		path.push_back(next);
		visited[next] = true;
		ret = min(ret, TSP(W, visited, path, N, len + W[cur][next]));
		visited[next] = false;
		path.pop_back();
	}

	return ret;
}

int main(void) {
	int N;
	cin >> N;

	vector<vector<int>> W(N, vector<int>(N, 0));
	vector<bool> visited(N, false);
	vector<int> path(1, 0);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> W[i][j];
		}
	}

	visited[0] = true;

	cout << TSP(W, visited, path, N, 0);

	return 0;
}