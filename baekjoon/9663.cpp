#include<iostream>
#include<vector>
#include<stack>
#include<utility>

using namespace std;

int main(void) {
	int N, answer = 0;
	cin >> N;

	stack<pair<int, int>> backtrack, path;
	vector<vector<int>> map(N, vector<int>(N, 0));

	for (int i = 0; i < N; ++i) { //초기화
		backtrack.emplace(0, i);
	}
	while (!backtrack.empty()) {
		pair<int, int> top = backtrack.top();
		backtrack.pop();
		path.push(top);
		int stacksize = backtrack.size();
		if (path.size() == N) {
			answer++;
			path.pop();
		}
		for (int i = 1; top.first + i < N; ++i) { //비유망 위치 갱신
			map[top.first + i][top.second]++;
			if (0 <= top.second - i)
				map[top.first + i][top.second - i]++;
			if (top.second + i < N)
				map[top.first + i][top.second + i]++;
		}

		for (int i = 0; i < N && top.first + 1 < N; ++i) { //다음 유망한 위치 push
			if (map[top.first + 1][i] == 0) {
				backtrack.emplace(top.first + 1, i);
			}
		}
		if (stacksize == backtrack.size()) { // push 안했으면 갱신된 비유망 위치 되돌림
			if (backtrack.empty()) {
				while (!path.empty()) {
					for (int i = 1; path.top().first + i < N; ++i) {
						map[path.top().first + i][path.top().second]--;
						if (0 <= path.top().second - i)
							map[path.top().first + i][path.top().second - i]--;
						if (path.top().second + i < N)
							map[path.top().first + i][path.top().second + i]--;
					}
					path.pop();
				}
			}
			else {
				while (!path.empty() && backtrack.top().first < path.top().first) {
					for (int i = 1; path.top().first + i < N; ++i) {
						map[path.top().first + i][path.top().second]--;
						if (0 <= path.top().second - i)
							map[path.top().first + i][path.top().second - i]--;
						if (path.top().second + i < N)
							map[path.top().first + i][path.top().second + i]--;
					}
					path.pop();
				}
				for (int i = 1; path.top().first + i < N; ++i) {
					map[path.top().first + i][path.top().second]--;
					if (0 <= path.top().second - i)
						map[path.top().first + i][path.top().second - i]--;
					if (path.top().second + i < N)
						map[path.top().first + i][path.top().second + i]--;
				}
				path.pop();
			}
		}
	}
	std::cout << answer;
}