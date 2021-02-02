#include<iostream>
#include<vector>

using namespace std;

int N, M;

int main(void) {
	int max = 0;
	cin >> N >> M;
	vector<vector<int>> arr(N, vector<int>(M, 0));
	vector<vector<bool>> mask(N, vector<bool>(M, false));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
		}
	}


	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int temp = 0;
			if (i + 3 < N) { // 아래로 1자
				temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j];
				if (max < temp)
					max = temp;
			}
			if (j + 3 < M) { // 오른쪽로 1자
				temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
				if (max < temp)
					max = temp;
			}

			if (i + 1 < N && j + 1 < M) { // 네모
				temp = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];
				if (max < temp)
					max = temp;
			}

			if (i + 2 < N && j + 1 < M) {
				temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1];
				if (max < temp)
					max = temp;
				temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1];
				if (max < temp)
					max = temp;
				temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i][j + 1];
				if (max < temp)
					max = temp;
				temp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
				if (max < temp)
					max = temp;
			}
			if (i + 2 < N && 0 <= j - 1) {
				temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j - 1];
				if (max < temp)
					max = temp;
				temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j - 1];
				if (max < temp)
					max = temp;
				temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i][j - 1];
				if (max < temp)
					max = temp;
				temp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j - 1] + arr[i + 2][j - 1];
				if (max < temp)
					max = temp;
			}


			if (j + 2 < M && i + 1 < N) {
				temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2];
				if (max < temp)
					max = temp;
				temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1];
				if (max < temp)
					max = temp;
				temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j];
				if (max < temp)
					max = temp;
				temp = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
				if (max < temp)
					max = temp;
			}
			if (j + 2 < M && 0 <= i - 1) {
				temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 2];
				if (max < temp)
					max = temp;
				temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 1];
				if (max < temp)
					max = temp;
				temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j];
				if (max < temp)
					max = temp;
				temp = arr[i][j] + arr[i][j + 1] + arr[i - 1][j + 1] + arr[i - 1][j + 2];
				if (max < temp)
					max = temp;
			}

		}
	}
	cout << max;

	return 0;
}