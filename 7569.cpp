#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>

using namespace std;

int bfs(const int floor, const int row, const int col, vector<vector<vector<int>>>& box, queue<pair<pair<int, int>, int>>& tomato) {
	int level = -1;
	while (!tomato.empty()) {
		int size = tomato.size();
		level++;
		while (size--) {
			pair<pair<int, int>, int>& element = tomato.front();
			if ((element.first.first + 1 < floor) && (box[element.first.first + 1][element.first.second][element.second] == 0)) {
				box[element.first.first + 1][element.first.second][element.second] = 1;
				tomato.push(make_pair(make_pair(element.first.first + 1, element.first.second), element.second));
			}
			if ((element.first.first - 1 >= 0) && (box[element.first.first - 1][element.first.second][element.second] == 0)) {
				box[element.first.first - 1][element.first.second][element.second] = 1;
				tomato.push(make_pair(make_pair(element.first.first - 1, element.first.second), element.second));
			}
			if ((element.first.second + 1 < row) && (box[element.first.first][element.first.second + 1][element.second] == 0)) {
				box[element.first.first][element.first.second + 1][element.second] = 1;
				tomato.push(make_pair(make_pair(element.first.first, element.first.second + 1), element.second));
			}
			if ((element.first.second - 1 >= 0) && (box[element.first.first][element.first.second - 1][element.second] == 0)) {
				box[element.first.first][element.first.second - 1][element.second] = 1;
				tomato.push(make_pair(make_pair(element.first.first, element.first.second - 1), element.second));
			}
			if ((element.second + 1 < col) && (box[element.first.first][element.first.second][element.second + 1] == 0)) {
				box[element.first.first][element.first.second][element.second + 1] = 1;
				tomato.push(make_pair(make_pair(element.first.first, element.first.second), element.second + 1));
			}
			if ((element.second - 1 >= 0) && (box[element.first.first][element.first.second][element.second - 1] == 0)) {
				box[element.first.first][element.first.second][element.second - 1] = 1;
				tomato.push(make_pair(make_pair(element.first.first, element.first.second), element.second - 1));
			}
			tomato.pop();
		}
	}

	for (int i = 0; i < floor; ++i)
		for (int j = 0; j < row; ++j)
			for (int k = 0; k < col; ++k)
				if (box[i][j][k] == 0)
					return -1;
	return level;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int col, row, floor;
	cin >> col >> row >> floor;

	vector<vector<vector<int>>> box(floor, vector<vector<int>>(row, vector<int>(col, 0)));
	queue<pair<pair<int, int>,int>> tomato;

	for (int i = 0; i < floor; ++i) {
		for (int j = 0; j < row; ++j) {
			for (int k = 0; k < col; ++k) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) {
					tomato.push(make_pair(make_pair(i, j),k));
				}
			}
		}
	}

	cout << bfs(floor, row, col, box, tomato);

}