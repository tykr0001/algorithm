#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int N, M, pair = 0;
		cin >> N >> M;
		vector<int> A, B;
		A.resize(N);
		B.resize(M);
		for (int i = 0; i < N; ++i)
			cin >> A[i];
		for (int i = 0; i < M; ++i)
			cin >> B[i];
		sort(A.begin(), A.end(), greater<int>());
		sort(B.begin(), B.end(), greater<int>());

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (A[i] > B[j]) {
					pair += (M - j);
					break;
				}
			}
		}
		cout << pair << endl;
	}
}