#include<iostream>
#include<stack>
#include<vector>
#include<utility>
#define _size 9

using namespace std;

class backtrack {
private:
	vector<vector<int>> map;
	vector<pair<int, int>> blank; //좌표<int, int>
	stack<pair<int, int>> tree, path; //blank인덱스<int>, 값<int>
	int index;
public:
	backtrack() {
		map = vector<vector<int>>(_size, vector<int>(_size, 0));
		index = 0;
	}
	void map_initialize(void);
	bool is_in_map(int number);
	void tracking(void);
};

void backtrack::map_initialize() {
	for (int i = 0; i < _size; ++i) {
		for (int j = 0; j < _size; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				blank.emplace_back(i, j);
		}
	}
}

bool backtrack::is_in_map(int number) {
	int i;
	for (i = 0; i < _size; ++i) {
		if (map[blank[index].first][i] == number) break;
		if (map[i][blank[index].second] == number) break;
	}
	if (i < _size) {
		return true;
	}
	else {
		int j, k;
		for (j = 0; j < 3; ++j) {
			for (k = 0; k < 3; ++k) {
				if (map[blank[index].first - blank[index].first % 3 + j][blank[index].second - blank[index].second % 3 + k] == number)
					break;
			}
		}
		if (j == 3 && k == 3)
			return false;
		else
			return true;
	}
}

void backtrack::tracking() {
	while(blank.size() != path.size()){
		int tree_size = tree.size();
		for (int i = 0; i < _size; ++i) {
			if (!is_in_map(i)) {
				tree.emplace(index, i);
			}
		}
		if (tree_size == tree.size()) { //수정해야함
			tree.pop();

			if (tree.top().first != index) {
				index--;
			}
		}
		//map[tree.top().first][blank[index].second];
		path.emplace(tree.top());
		map[blank[tree.top().first].first][blank[tree.top().second].second] = tree.top().second;
		
		index++;
	}
	for (int i = 0; i < _size; ++i) {
		for (int j = 0; j < _size; ++j) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int main(void) {
	backtrack sudoku;
	sudoku.map_initialize();
	sudoku.tracking();
}