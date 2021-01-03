#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    while (str != "0") {
        int i = 0;
        while (i < str.length()) {
            if (str[i] != str[str.length() - 1 - i]) {
                break;
            }
            i++;
        }
        if (i == str.length()) {
            cout << "no" << endl;
        }
        else {
            cout << "yes" << endl;
        }
        cin >> str;
    }
}