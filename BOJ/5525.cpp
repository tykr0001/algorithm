#include<iostream>
#include<string>

using namespace std;

int main(void) {
	int N, M, count=0;
	string S,buffer;

	cin >> N >> M >> S;

	for (int i = 0; i < M; ++i) {
		if (S[i] == 'I' && S[i + 1] == 'O') {
			int rep = 0;
			while (S[i + 1] == 'O' && S[i + 2] == 'I') {
				rep += 1;
				i += 2;
				if (rep == N) {
					rep--;
					count++;
				}
			}
		}
	}
	cout << count;
}