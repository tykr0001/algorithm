#include <bits/stdc++.h>

using namespace std;



int main(void) {
    int T;
    cin >> T;
    while (T--) {
        int n;
        int answer = 1;
        map<string, int> m;

        cin >> n;
        for (int i = 0; i < 2 * n; i++) {
            string str;
            cin >> str;
            if (i % 2 == 1) {
                if (m.find(str) != m.end()) {
                    m[str]++;
                }
                else {
                    m[str] = 1;
                }
            }
        }

        for (auto iter = m.begin(); iter != m.end(); iter++) {
            answer *= (iter->second) + 1;
        }
        cout << answer - 1 << endl;
    }
}