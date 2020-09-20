#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool is_possible(const int mid, const int N, const vector<int>& arr) {
	int ret = 0;

	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] == 1) {
			i += mid - 1;
			ret += 1;
		}
	}
	
	return ret <= N;
}

int binary_search(int end, const int max_row, const int N, const vector<int>& arr) {
	int begin = 1;
	int mid = (begin + end) / 2;
	int ret = -1;

	while (begin <= end) {
		if (mid >= max_row && is_possible(mid, N, arr)) {
			ret = mid;
			end = mid - 1;
			mid = (begin + end) / 2;
		}
		else {
			begin = mid + 1;
			mid = (begin + end) / 2;
		}
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int row, col, N, M, max_row=0;
	cin >> row >> col >> N >> M;

	vector<int> arr(col, 0);

	for (int i = 0; i < M; ++i) {
		int R, C;
		cin >> R >> C;
		arr[C-1] = 1;
		max_row = max(max_row, R);
	}

	cout << binary_search(row > col ? row : col, max_row, N, arr);
}