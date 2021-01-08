#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        stack<char> s;

        auto iter = str.begin();
        while (iter != str.end()) {
            if (*iter == '(') {
                s.push('(');
            }
            else if (*iter == ')') {
                if (s.empty() || s.top() != '(') {
                    break;
                }
                else {
                    s.pop();
                }
            }
            iter++;
        }
        
        if (iter != str.end() || !s.empty()) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
}