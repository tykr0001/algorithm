#include <iostream>

using namespace std;

int answer[10];

void SaveDigit(int n, int ex) {
    while (n > 0) {
        answer[n % 10] += ex;
        n /= 10;
    }
}

void Solve(int a, int b, int ex) {
    while (a % 10 != 0 && a <= b) {
        SaveDigit(a, ex);
        a++;
    }
    if (a > b) {
        return;
    }

    while (b % 10 != 9 && b >= a) {
        SaveDigit(b, ex);
        b--;
    }

    int cnt = b / 10 - a / 10 + 1;
    for (int i = 0; i < 10; ++i) {
        answer[i] += cnt * ex;
    }

    Solve(a / 10, b / 10, ex * 10);
}

int main() {
    int n;
    cin >> n;

    Solve(1, n, 1);
    for (int i = 0; i < 10; ++i){
        cout << answer[i] << " ";
    }
    return 0;
}