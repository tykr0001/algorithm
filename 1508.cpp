#include<iostream>
#include<vector>

using namespace std;

bool possible_distance(const int distance, const int M, const vector<int>& arr) {
	int count = 1;
	int cur = arr[0];
	for (int i = 1; i < arr.size(); ++i) {
		int next = arr[i];
		if (cur + distance <= next) {
			cur = next;
			count++;
		}
	}
	if (count >= M)
		return true;
	else
		return false;
}

int find_minst_distance(const int N, const int M, const vector<int>& arr) {
	int begin = 0, end = N, ret = -1;
	while (begin <= end) {
		int distance = (begin + end) / 2;
		if (possible_distance(distance, M, arr)) {
			ret = distance;
			begin = distance + 1;
		}
		else
			end = distance - 1;
	}
	return ret;
}

int main(void) {
	int N, M, K, distance;
	cin >> N >> M >> K;

	vector<int> arr;
	arr.resize(K);
	for (int i = 0; i < K; ++i)
		cin >> arr[i];
	distance = find_minst_distance(N, M, arr);

	int cur = arr[0];
	int count = 1;
	cout << "1";
	for (int i = 1; i < arr.size(); ++i) {
		int next = arr[i];
		if (cur + distance <= next && count < M) {
			cout << "1";
			cur = next;
			count++;
		}
		else
			cout << "0";
	}
	cout << endl;
}