#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    int T;
    int x1, y1, r1, x2, y2, r2;
    double d; // 중점사이의 거리
    cin >> T;
    while (T--) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if (x1 == x2 && y1 == y2) {
            if (r1 == r2) {
                cout << -1 << endl;
            }
            else {
                cout << 0 << endl;
            }
            continue;
        }
        d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        if (d<abs(r1 - r2) || d>r1 + r2) {
            cout << 0 << endl;
        }
        else if (d == abs(r1 - r2) || d == abs(r1 + r2)) {
            cout << 1 << endl;
        }
        else {
            cout << 2 << endl;
        }
    }
    return 0;
}