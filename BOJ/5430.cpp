#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        string p;
        int n;
        int error = 0; // if error == 1 : error
        int flag = 0;
        cin >> p >> n;

        deque<int> x(n, 0);
        string inp;
        cin >> inp;
        for (int i = 1, j = 0; i < inp.length() - 1; i++) {
            if ('0' <= inp[i] && inp[i] <= '9') {
                x[j] = 10 * x[j] + inp[i] - '0';
            }
            else {
                j++;
            }
        }
        for (int i = 0; i < p.length(); i++) {
            if (p[i] == 'R') {
                flag = !flag;
            }
            else {
                if (!x.empty()) {
                    if (flag == 0) {
                        x.pop_front();
                    }
                    else {
                        x.pop_back();
                    }
                }
                else {
                    error = 1;
                    break;
                }
            }
        }
        if (error) {
            cout << "error" << '\n';
        }
        else {
            if (flag != 0) {
                reverse(x.begin(), x.end());
            }
            cout << '[';
            if (!x.empty()) {
                for (int i = 0; i < x.size() * 2 - 1; i++) {
                    if (i % 2 == 0) {
                        cout << x[i / 2];
                    }
                    else {
                        cout << ',';
                    }
                }
            }
            cout << ']' << '\n';
        }
    }
}