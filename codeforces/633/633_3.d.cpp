#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long LL;

LL t;

int main(void) {
    cin >> t;
    while (t--) {
        LL n;
        cin >> n;
        vector<LL> odd;
        vector<LL> even;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            if (tmp % 2) odd.push_back(tmp);
            else even.push_back(tmp);
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());

        LL a = 0;
        LL b = 0;
        int flag = 0; // 0:Alice, 1:Bob
        while (n--) {
            if (flag % 2 == 0) {
                flag = 1;
                if (!even.empty() && !odd.empty()) {
                    if (even.back() > odd.back()) {
                        a += even.back();
                        even.pop_back();
                    }
                    else {
                        odd.pop_back();
                    }
                }
                else if (!even.empty()) {
                    a += even.back();
                    even.pop_back();
                }
                else {
                    odd.pop_back();
                }
            }
            else {
                flag = 0;
                if (!even.empty() && !odd.empty()) {
                    if (even.back() < odd.back()) {
                        b += odd.back();
                        odd.pop_back();
                    }
                    else {
                        even.pop_back();
                    }
                }
                else if (!odd.empty()) {
                    b += odd.back();
                    odd.pop_back();
                }
                else {
                    even.pop_back();
                }
            }
        }
        if (a > b) {
            cout << "Alice" << endl;
        }
        else if (a == b) {
            cout << "Tie" << endl;
        }
        else {
            cout << "Bob" << endl;
        }
    }

    return 0;
}