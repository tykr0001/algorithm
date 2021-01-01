#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

bool isBothIn(int x_1, int y_1, int x_2, int y_2, int c_x, int c_y, int r) {
    bool start = r > sqrt((c_x - x_1) * (c_x - x_1) + (c_y - y_1) * (c_y - y_1));
    bool end = r > sqrt((c_x - x_2) * (c_x - x_2) + (c_y - y_2) * (c_y - y_2));
    return start && end;
}

bool isBothOut(int x_1, int y_1, int x_2, int y_2, int c_x, int c_y, int r) {
    bool start = r < sqrt((c_x - x_1)* (c_x - x_1) + (c_y - y_1) * (c_y - y_1));
    bool end = r < sqrt((c_x - x_2)* (c_x - x_2) + (c_y - y_2) * (c_y - y_2));
    return start && end;
}

int main(void) {
    int T;
    cin >> T;
    while (T--) {
        int x_1, y_1, x_2, y_2;
        int n;
        int cnt = 0;
        cin >> x_1 >> y_1 >> x_2 >> y_2 >> n;
        for (int i = 0; i < n; ++i) {
            int c_x, c_y, r;
            cin >> c_x >> c_y >> r;
            if (!(isBothIn(x_1, y_1, x_2, y_2, c_x, c_y, r)
                || isBothOut(x_1, y_1, x_2, y_2, c_x, c_y, r))) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}