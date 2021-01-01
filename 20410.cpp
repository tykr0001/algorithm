#include <iostream>

using namespace std;

int main(void) {
    int M, SEED, X_1, X_2;
    cin >> M >> SEED >> X_1 >> X_2;

    for (int a = 0; a < M; a++) {
        for (int c = 0; c < M; c++) {
            if (X_1 == (a * SEED + c) % M && X_2 == (a * X_1 + c) % M) {
                cout << a << " " << c << endl;
                return 0;
            }
        }
    }

    return 0;
}