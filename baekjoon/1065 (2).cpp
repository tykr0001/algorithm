#include<iostream>

using namespace std;

int digitNumber(int n) {
	int ret_val = 0;
	while (n > 0) {
		ret_val++;
		n /= 10;
	}
	return ret_val;
}

bool isHansu(int n) {
	int digit_num = digitNumber(n);
	if(digit_num <= 2) {
		return true;
	}

	int d = (n % 10) - (n / 10 % 10); // 공차

	while (--digit_num > 0) {
		if (d != n % 10 - (n / 10 % 10)) {
			return false;
		}
		n /= 10; // 일의 자리 제거
	}
	return true;

}
int main(void) {
	int N;
	int cnt = 0;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		if (isHansu(i)) {
			//cout << i << endl;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
