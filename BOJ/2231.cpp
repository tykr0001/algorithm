#include <iostream>

using namespace std;

int conquer(int i) {
    int ret = 0;
    while (i) {
        ret += i % 10;
        i /= 10;
    }
    return ret;
}

int main(void) {
    int N;
    cin >> N;
    int i = 0;
    for (; i < N; i++) {
        if (N == i + conquer(i)) {
            cout << i << endl;
            return 0;
        }
    }
    if (i == N) {
        cout << 0 << endl;
    }
    return 0;
}