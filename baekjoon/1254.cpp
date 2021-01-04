#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string S = ""; // a#b#a#b
    string tmp; //abab
    cin >> tmp;

    for (int i = 0; i < tmp.length(); ++i) {
        S += tmp[i];
        S += "#";
    }
    S.pop_back();

    int idx = S.length() / 2;
    int i = 0;
    if (S.length() % 2) {
        while (idx + i < S.length()) {
            if (S[idx - i] != S[idx + i]) {
                idx++;
                i = 0;
            }
            else {
                ++i;
            }
        }
    }

    // idx 홀수 : (idx / 2 + 1) * 2 - > idx - 1 + 2 -> idx + 1
    // idx 짝수 : (idx / 2) * 2 + 1 - > idx + 1
    cout << idx + 1 << endl;

    return 0;
}