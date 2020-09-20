#include<iostream>
#include<vector>

using namespace std;

bool possible(const int length, const int M, const vector<int> lesson) {
	int count = 1, sum = 0;
	for (int i = 0; i < lesson.size()-1; ++i) {
		if (lesson[i] > length)
			return false;
		else {
			sum += lesson[i];
			if (sum + lesson[i+1] > length) {
				count++;
				sum = 0;
			}
		}
	}
	return count <= M;
}

int find_min_BD(const int max, const int M, const vector<int>& lesson) {
	int begin = 0, end = max, ret = -1;
	while (begin <= end) {
		int length = (begin + end) / 2;
		if (possible(length, M, lesson)) {
			ret = length;
			end = length - 1;
			length = (begin + end) / 2;
		}
		else {
			begin = length + 1;
			length = (begin + end) / 2;
		}
	}
	return ret;
}

int main(void) {
	int N, M, max = 0;
	cin >> N >> M;

	vector<int> lesson(N);
	for (int i = 0; i < N; ++i) {
		cin >> lesson[i];
		max += lesson[i];
	}
	cout << find_min_BD(max, M, lesson);
	return 0;
}