#include<iostream>
#include<vector>

using namespace std;

vector<int> arr;
int N, S;
int answer = 0;

void recursive_sum(int iter, int sum) {
	if (iter == N) {
		return;
	}
	else if (sum + arr[iter] == S) {
		answer++;
	}
	recursive_sum(iter + 1, sum + arr[iter]);
	recursive_sum(iter + 1, sum);
}

int main(void) {
	cin >> N >> S;
	arr.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	recursive_sum(0, 0);
	cout << answer;
}