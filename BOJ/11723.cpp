#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int mask = 0;
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        string op;
        int num;
        cin >> op;
        if (op == "all") {
            mask = 0b11111111111111111111;
        }
        else if (op == "empty") {
            mask = 0;
        }
        else {
            cin >> num;
            if (op == "add") {
                mask |= 1 << num - 1;
            }
            if (op == "remove") {
                mask &= (1 << num - 1) - 1;
            }
            if (op == "check") {
                if ((mask >> num - 1) % 2) {
                    cout << 1 << '\n';
                }
                else {
                    cout << 0 << '\n';
                }
            }
            if (op == "toggle") {
                mask ^= 1 << num - 1;
            }
        }
    }
}