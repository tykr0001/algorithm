#include<iostream>
#include<string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, length;
	cin >> N;
	
	string* filename = new string[N];
	string answer = "";
	for (int i = 0; i < N; ++i) {
		cin >> filename[i];
	}

	length = filename[0].length();

	for (int i = 0; i < length; ++i) {
		int j = 0;
		for (; j < N-1; ++j) {
			if (filename[j][i] != filename[j + 1][i])
				break;
		}
		if (j == N - 1) answer += filename[0][i];
		else answer += "?";
	}
	cout << answer;
	return 0;
}