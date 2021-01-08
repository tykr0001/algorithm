#include <iostream>

using namespace std;

int N, L;

bool CanMakeList(int sum, int len) {
    if (len == 1) {
        return true;
    }
    if ((sum - ((len - 1) * len) / 2) % len == 0) {
        int a = (sum - ((len - 1) * len) / 2) / len;
        return a >= 0;
    }
    return false;
}

int main(void) {
    cin >> N >> L;
    while (L <= 100 && !CanMakeList(N, L)) {
        L++;
    }
    if (L > 100) {
        cout << -1;
    }
    else {
        if (L % 2) { // 홀수
            int a = N / L;
            for (int d = -L / 2; d <= L / 2; d++) {
                cout << a + d << " ";
            }
        }
        else { // 짝수
            int a = (N - (L - 1) * L / 2) / L;
            for (int d = 0; d < L; d++) {
                cout << a + d << " ";
            }
        }
    }
    return 0;
}