#include<iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T > 0) {
		T--;
		int row, col, count, sum;
		cin >> row >> col;
		int** grid = new int* [row];
		for (int i = 0; i < row; ++i) {
			grid[i] = new int[col];
			for (int j = 0; j < col; ++j) {
				cin >> grid[i][j];
			}
		}

		sum = 0;
		for (int j = 0; j < col; ++j) {
			count = 0;
			for (int i = 0; i < row; ++i) {
				if (grid[i][j] == 1) {
					sum += row - i - 1 - count;
					count++;
				}
			}
		}
		cout << sum << '\n';
	}
}