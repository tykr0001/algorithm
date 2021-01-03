#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string A, B;
	cin >> A >> B;

	long long answer = 0;
	for (int i = 0; i < A.length(); ++i) {
		for (int j = 0; j < B.length(); ++j) {
			answer += (A[i] - '0') * (B[j] - '0');
		}
	}
	cout << answer;
	return 0;
}

