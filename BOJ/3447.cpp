#include <iostream>
#include <string>

using namespace std;

string DeleteBUG(string str) {
    string ret = str;
    string prev;
    do {
        string tmp = "";
        int state = 0; //0:not bug, 1:B, 2:BU

        prev = ret;
        ret = "";
        for (int i = 0; i < prev.length(); i++) {
            if (state == 0) {
                if (prev[i] == 'B') {
                    tmp += prev[i];
                    state = 1;
                }
                else {
                    ret += tmp + prev[i];
                    tmp = "";
                }
            }
            else if (state == 1) {
                if (prev[i] == 'U') {
                    tmp += prev[i];
                    state = 2;
                }
                else {
                    if (prev[i] == 'B') {
                        ret += tmp;
                        tmp = prev[i];
                        state = 1;
                    }
                    else {
                        ret += tmp + prev[i];
                        tmp = "";
                        state = 0;
                    }
                }
            }
            else if (state == 2) {
                if (prev[i] == 'G') {
                    tmp = "";
                    state = 0;
                }
                else {
                    if (prev[i] == 'B') {
                        ret += tmp;
                        tmp = prev[i];
                        state = 1;
                    }
                    else {
                        ret += tmp + prev[i];
                        tmp = "";
                        state = 0;
                    }
                }
            }
        }
        ret += tmp;
    } while (prev != ret);

    return ret;
}

int main(void) {
    string str;
    while (getline(cin, str)) {
        cout << DeleteBUG(str) << endl;
    }
    return 0;
}