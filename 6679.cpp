#include<iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int bin;
	int twe;
	int hex;
	for (int i = 2992; i < 10000; ++i) {
		bin = i / 1000 + i % 1000 / 100 + i % 100 / 10 + i % 10;
		twe = i / (12 * 12 * 12) + i % (12 * 12 * 12) / (12 * 12) + i % (12 * 12) / 12 + i % 12;
		hex = i / (16 * 16 * 16) + i % (16 * 16 * 16) / (16 * 16) + i % (16 * 16) / 16 + i % 16;

		if (bin == twe && twe == hex) cout << i << '\n';
	}

	return 0;
}