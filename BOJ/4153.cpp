#include <bits/stdc++.h>

using namespace std;

int main(void) {
    while (1) {
        vector<int> a(3);

        for (int i = 0; i < 3; i++) {
            cin >> a[i];
        }
        if (a[0] == 0 && a[1] == 0 && a[2] == 0) {
            break;
        }
        sort(a.begin(), a.end());

        if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) {
            cout << "right" << endl;
        }
        else {
            cout << "wrong" << endl;
        }
    }
    return 0;
}