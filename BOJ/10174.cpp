#include <iostream>
#include <string>

using namespace std;

bool IsEqual(char a, char b) {
    if ('A' <= a && a <= 'z' && 'A' <= b && b <= 'z') {
        if (a == b) {
            return true;
        }
        else {
            if (a < b) {
                if (a - 'A' == b - 'a') {
                    return true;
                }
                return false;
            }
            else {
                if (a - 'a' == b - 'A') {
                    return true;
                }
                return false;
            }
        }
    }
    else {
        if (a == b) {
            return true;
        }
        else {
            return false;
        }

    }
}

int main(void) {
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string str;
        getline(cin, str);
        int i = 0;
        while (i < str.length()) {
            if (!IsEqual(str[i], str[str.length() - 1 - i])) {
                break;
            }
            i++;
        }
        if (i == str.length()) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}