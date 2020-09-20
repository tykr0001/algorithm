#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long int> arr;
int K, N;

long long int binarySearch(long long int begin, long long int end) {
	while (begin <= end) {
		long long int mid = (begin + end) / 2;
		long long count = 0;
		for (int i = 0; i < K; ++i) {
			count += arr[i] / mid;
		}
		if (count >= N)
			begin = mid + 1;
		else
			end = mid - 1;
	}
	return end;
}

int main(void) {

	cin >> K >> N;
	arr.resize(K);
	for (int i = 0; i < K; ++i) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	cout << binarySearch(1, arr[K-1]);
}