#include <bits/stdc++.h>

using namespace std;

void star(int i, int j, int size) {
	if ((i / size) % 3 == 1 && (j / size) % 3 == 1) {
		cout << ' ';
	}
	else if (size / 3 == 0) {
		cout << '*';
	}
	else {
		star(i, j, size / 3);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			star(i, j, N/3);
		}
		cout << '\n';
	}
	return 0;
}