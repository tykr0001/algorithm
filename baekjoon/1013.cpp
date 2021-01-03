#include <iostream>
#include <string>
#include <regex>

using namespace std;

int T;
string str;

// (100+1+ | 01)+
void RegularExpression(string str) {
    // 0 => 1 ***
    // 1 => 10
    // 2 => 100+
    // 3 => 100+1
    // 4 => 100+1+
    // 5 => 100+1+0
    // 6 => 0 ***
    // 7 => 1
    int state;
    if (str.length() == 1) {
        cout << "NO" << endl;
        return;
    }
    if (str[0] == '1') {
        state = 0;
    }
    else {
        state = 6;
    }
    for (int i = 1; i < str.length(); ++i) {
        switch (state) {
        case 0:
            if (str[i] == '0') {
                state = 1;
            }
            else {
                cout << "NO" << endl;
                return;
            }
            break;

        case 1:
            if (str[i] == '0') {
                state = 2;
            }
            else {
                cout << "NO" << endl;
                return;
            }
            break;

        case 2:
            if (str[i] == '1') {
                state = 3;
            }
            break;

        case 3:
            if (str[i] == '0') {
                state = 6;
            }
            else {
                state = 4;
            }
            break;

        case 4:
            if (str[i] == '0') {
                state = 5;
            }
            break;

        case 5:
            if (str[i] == '0') {
                state = 2;
            }
            else {
                state = 7;
            }
            break;

        case 6:
            if (str[i] == '1') {
                state = 7;
            }
            else {
                cout << "NO" << endl;
                return;
            }
            break;

        case 7:
            if (str[i] == '0') {
                state = 6;
            }
            else {
                state = 0;
            }
            break;

        default:
            break;
        }
    }
    if (state == 3 || state == 4 || state == 7) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}


int main(void) {
    cin >> T;
    while (T--) {
        cin >> str;
        RegularExpression(str);
        //cout << (regex_match(str, regex("(100+1+|01)+")) ? "YES" : "NO") << endl;
    }
    return 0;
}