#include<iostream>

using namespace std;

int T, a, b;
int answer;

int f(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a % 10;
    }
    if (b % 2) {
        int tmp = f(a, b / 2);
        return tmp * tmp * a % 10;
    }
    else {
        int tmp = f(a, b / 2);
        return tmp * tmp % 10;
    }
}

int main(void) {
    cin >> T;
    while (T--) {
        cin >> a >> b;
        answer = f(a, b);
        cout << (answer ? answer : 10) << endl;
    }
}