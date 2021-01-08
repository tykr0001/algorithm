#include <bits/stdc++.h>

using namespace std;

string str;

int main(void) {
    while (1) {
        getline(cin, str);
        if (str == ".") {
            break;
        }

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
            else if (*iter == '[') {
                s.push('[');
            }
            else if (*iter == ']') {
                if (s.empty() || s.top() != '[') {
                    break;
                }
                else {
                    s.pop();
                }
            }
            iter++;
        }
        if (iter != str.end() || !s.empty()) {
            cout << "no" << endl;
        }
        else {
            cout << "yes" << endl;
        }
    }
}