#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string origin;
    string answer;
    string bomb;
    string s;
    cin >> origin >> bomb;
    answer.resize(origin.size());

    int idx = 0;
    for (int i = 0; i < origin.length(); i++) {
        answer[idx++] = origin[i];
        if (answer[idx - 1] == bomb[bomb.length() - 1]) {
            if (idx - bomb.length() >= 0) {
                bool is_bomb = true;
                for (int j = 0; j < bomb.length(); j++) {
                    if (answer[idx - 1 - j] != bomb[bomb.length() - 1 - j]) {
                        is_bomb = false;
                        break;
                    }
                }
                if (is_bomb) {
                    idx -= bomb.length();
                }
            }
        }
    }

    if (idx > 0) {
        for (int i = 0; i < idx; i++) {
            cout << answer[i];
        }
    }
    else {
        cout << "FRULA";
    }
    return 0;
}