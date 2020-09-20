#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

bool is_possible(const int N, const int mid, const vector<int>& arr) {
	int child_num = 0;
	
	vector<int>::const_iterator iter = arr.begin();
	while (iter != arr.end()) {
		child_num += *iter / mid;
		if (*iter % mid != 0) child_num++;
		iter++;
	}
	return child_num <= N;
}

int binary_search(const int N, const vector<int>& arr) {
	int beg = 1, end = arr.back();
	int mid = (beg + end) / 2;
	int ret = -1;
	while (beg <= end) {
		if (is_possible(N, mid, arr)) {
			ret = mid;
			end = mid - 1;
			mid = (beg + end) / 2;
		}
		else {
			beg = mid + 1;
			mid = (beg + end) / 2;
		}
	}

	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> arr(M);

	for(int i=0; i<M; ++i) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	cout << binary_search(N, arr);

	return 0;
}