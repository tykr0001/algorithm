#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long int ll;

vector<ll> arr;
int K, N;

ll binarySearch(ll lo, ll hi) {
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		ll count = 0;
		for (int i = 0; i < K; ++i) {
			count += arr[i] / mid;
		}
		if (count >= N)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return hi;
}

int main(void) {
	cin >> K >> N;
	arr.resize(K);
	for (int i = 0; i < K; ++i) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	cout << binarySearch(1, arr[K - 1]);
}