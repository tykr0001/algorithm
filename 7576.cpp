#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>

using namespace std;

int bfs(const int row, const int col, vector<vector<int>>& box, queue<pair<int, int>>& tomato) {
	int level = -1;
	//vector<queue<pair<int, int>>> next_tomato(tomato.size());
	while (!tomato.empty()) {
		int size = tomato.size();
		level++;
		while (size--) {
			pair<int, int>& element = tomato.front();
			if ((element.first + 1 < row) && (box[element.first + 1][element.second] == 0)) {
				box[element.first + 1][element.second] = 1;
				tomato.push(make_pair(element.first + 1, element.second));
			}
			if ((element.first - 1 >= 0) && (box[element.first - 1][element.second] == 0)) {
				box[element.first - 1][element.second] = 1;
				tomato.push(make_pair(element.first - 1, element.second));
			}
			if ((element.second + 1 < col) && (box[element.first][element.second + 1] == 0)) {
				box[element.first][element.second + 1] = 1;
				tomato.push(make_pair(element.first, element.second + 1));
			}
			if ((element.second - 1 >= 0) && (box[element.first][element.second - 1] == 0)) {
				box[element.first][element.second - 1] = 1;
				tomato.push(make_pair(element.first, element.second - 1));
			}
			tomato.pop();
		}
	}
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (box[i][j] == 0)
				return -1;
	return level;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int col, row;
	cin >> col >> row;

	vector<vector<int>> box(row, vector<int>(col, 0));
	queue<pair<int, int>> tomato;

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				tomato.push(make_pair(i, j));
			}
		}
	}

	cout << bfs(row, col, box, tomato);

}