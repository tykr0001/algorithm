#include<iostream>

using namespace std;

inline const int Tn(int num) {
	return (num * (num + 1) / 2);
}

int main(void) {
	int T;
	cin >> T;
	
	while (T--) {
		int num, count = 0, sum = 0;
		cin >> num;
		for (int i = 1; i < 45; ++i) {
			sum += Tn(i);
			if (sum >= num) {
				sum -= Tn(i);
				break;
			}
			for (int j = i; j < 45; ++j) {
				sum += Tn(j);
				if (sum >= num) {
					sum -= Tn(j);
					break;
				}
				for (int k = j; k < 45; ++k) {
					sum += Tn(k);
					if (sum == num) {
						count = 1;
						sum -= Tn(k);
						break;
					}
					else if (sum > num) {
						sum -= Tn(k);
						break;
					}
					sum -= Tn(k);
				}
				sum -= Tn(j);
			}
			sum -= Tn(i);
		}
		if (count != 0)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}