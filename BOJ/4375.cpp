#include <bits/stdc++.h>

using namespace std;

int n;

int main(void) {
    while (true) {
        cin >> n;
        if(cin.eof())
            break;
            
        int m = 0;
        for (int i = 1; i <= n; i++) {
            m = m * 10 + 1;
            m %= n;
            if (m == 0) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}