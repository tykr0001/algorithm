#include<iostream>
#include<vector>
#include<stack>
#include<utility>
#define _size 9

using namespace std;

bool isnum_in_sudoku(vector<vector<int>>& sudoku, pair<int, int> location, int number) {
	int i;
	for (i = 0; i < _size; ++i) {
		if (sudoku[location.first][i] == number) break;
		if (sudoku[i][location.second] == number) break;
	}
	if (i < _size) {
		return true;
	}
	else {
		int j, k;
		for (j = 0; j < 3; ++j) {
			for (k = 0; k < 3; ++k) {
				if (sudoku[location.first - location.first % 3 + j][location.second - location.second % 3 + k] == number)
					break;
			}
		}
		if (j == 3 && k == 3)
			return false;
		else
			return true;
	}
}

int main(void) {
	vector<vector<int>> sudoku(_size, vector<int>(_size, 0));
	vector<pair<int, int>> blank;
	stack<pair<int, int>> backtrack; //�ڸ�(blank������ �ε���)<int>, ��<int>
	stack<pair<int, int>> path; //�ڸ�<int>, ��<int>
	int index = 0; //blank������ �ε���

	for (int i = 0; i < _size; ++i) {
		for (int j = 0; j < _size; ++j) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0) {
				blank.emplace_back(i, j);
			}
		}
	}
	
	for (int i = 1; i <= _size; ++i) {
		for (int j = 0; i < _size; ++j) {
			if (!isnum_in_sudoku(sudoku, blank[index], i)) {
				backtrack.emplace(index, i);
			}
		}
	}

	while (!backtrack.empty()) {
		pair<int, int> top = backtrack.top();
		path.top();
		backtrack.pop();
		int stacksize = backtrack.size();
		if (path.size() == blank.size()) {
			for (int i = 0; i < _size; ++i) {
				for (int j = 0; j < _size; ++j) {
					cout <<  sudoku[i][j] << endl;
				}
				cout << endl;
			}
			break;
		}

		sudoku[blank[index].first][blank[index].second] = top.second; // ������ ����
		index++;

		int i, j;
		for (i = 1; i <= _size; ++i) {
			for (j = 0; i < _size; ++j) {
				if (!isnum_in_sudoku(sudoku, blank[index], i)) { // ������ �˻��� push
					backtrack.emplace(index, i);
				}
			}
		}
		if (stacksize == backtrack.size()) { // push �ȵ����� �ǵ��ư�
			if (backtrack.empty()) {
				while (!path.empty()) {
					index--;
					sudoku[blank[index].first][blank[index].second] = 0; // ������ 0���� �簻��
					path.pop();
				}
			}
			else {
				while (!path.empty() && backtrack.top().first < path.top().first) {
					index--;
					sudoku[blank[index].first][blank[index].second] = 0; // ������ 0���� �簻��
					path.pop();
				}
				index--;
				sudoku[blank[index].first][blank[index].second] = 0; // ������ 0���� �簻��
				path.pop();
			}
		}
	}
	return 0;
}