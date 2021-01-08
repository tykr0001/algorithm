#include<iostream>
#include<vector>

using namespace std;

int N, M;
/*
int bruteforce(vector<vector<int>>& arr, vector<vector<bool>>& mask, int _i, int _j, int level) {
	int max = 0;
	if (level == 4) {
		int ret = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (mask[i][j] == true){
					ret += arr[i][j];
				}
			}
		}
		return ret;
	}
	else if(level == 0){
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				int temp;
				mask[i][j] = true;
				if (j + 1 < M) {
					temp = bruteforce(arr, mask, i, j + 1, level + 1);
					if (max < temp)
						max = temp;
				}
				
				if (0 <= j - 1) {
					temp = bruteforce(arr, mask, i, j - 1, level + 1);
					if (max < temp)
						max = temp;
				}
				
				if (i + 1 < N) {
					temp = bruteforce(arr, mask, i + 1, j, level + 1);
					if (max < temp)
						max = temp;
				}
				mask[i][j] = false;
			}
		}
	}
	else if(!mask[_i][_j]){
		int temp;
		mask[_i][_j] = true;
		if (_j + 1 < M) {
			temp = bruteforce(arr, mask, _i, _j + 1, level + 1);
			if (max < temp)
				max = temp;
		}
		if (0 <= _j - 1) {
			temp = bruteforce(arr, mask, _i, _j - 1, level + 1);
			if (max < temp)
				max = temp;
		}
		if (_i + 1 < N) {
			temp = bruteforce(arr, mask, _i + 1, _j, level + 1);
			if (max < temp)
				max = temp;
		}
		mask[_i][_j] = false;

		if (_j + 1 < M && !mask[_i][_j + 1] && level == 1) {
			mask[_i][_j + 1] = true;
			temp = bruteforce(arr, mask, _i, _j, level + 1);
			if (max < temp)
				max = temp;
			mask[_i][_j + 1] = false;
		}
		if (0 <= _j - 1 && !mask[_i][_j - 1] && level == 1) {
			mask[_i][_j - 1] = true;
			temp = bruteforce(arr, mask, _i, _j, level + 1);
			if (max < temp)
				max = temp;
			mask[_i][_j - 1] = false;
		}
		if (_i + 1 < N && !mask[_i + 1][_j] && level == 1) {
			mask[_i + 1][_j] = true;
			temp = bruteforce(arr, mask, _i, _j, level + 1);
			if (max < temp)
				max = temp;
			mask[_i + 1][_j] = false;
		}
	}

	return max;
}
*/


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
	//cout << bruteforce(arr,mask,0,0,0);

	return 0;
}