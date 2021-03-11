#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> inp;

void Solve(void) {
    for (int i = 0; i < N; i++) {
        const string& str = inp[i];
        int lo = 0;
        int hi = str.length() - 1;
        int cnt = 0;
        bool flag = true;
        while (lo <= hi) {
            if (str[lo] != str[hi]) {
                if (cnt != 0) {
                    flag = false;
                    break;
                }
                if (str[lo + 1] == str[hi]) {
                    lo++;
                    cnt++;
                }
                else if (str[lo] == str[hi - 1]) {
                    hi--;
                    cnt++;
                }
                else{
                    flag = false;
                    break;
                }
            }
            lo++;
            hi--;
        }
        if (flag) {
            if (cnt == 0) {
                cout << 1 << '\n';
            }
            if (cnt == 1) {
                cout << 2 << '\n';
            }
        }
        else {
            cout << 3 << '\n';
        }
    }
}

void Init(void) {
    cin >> N;
    inp.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> inp[i];
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Init();
    Solve();
    return 0;
}
