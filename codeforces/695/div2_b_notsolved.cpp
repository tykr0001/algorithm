#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        int answer = 0;
        int flag = 0;
        cin >> n;
        vector<int> a(n,0);
        vector<int> state(n,0); // 0:non 1:hill 2:valley
        for (int i = 0; i < n; i++) {
            int inp;
            cin >> inp;
            a[i] = inp;
        }
        if (n <= 4) {
            cout << 0 << '\n';
            continue;
        }
        for (int i = 1; i < n - 1; i++) {
            if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
                state[i] = 2; // vally
                answer++;
            }
            if (a[i - 1]<a[i] && a[i] > a[i + 1]) {
                state[i] = 1; // hill
                answer++;
            }
        }
        if(answer == 0){
            cout << 0 << '\n';
            continue;
        }
        for (int i = 1; i < n - 1; i++) {
            if (state[i - 1] == 2 && state[i] == 1 && state[i + 1] == 2) {
                flag = max(flag, 3);
            }
            else if (state[i - 1] == 1 && state[i] == 2 && state[i + 1] == 1) {
                flag = max(flag, 3);
            }
            else if (state[i - 1] == 1 && state[i] == 2) {
                if(a[i-1]<=a[i+1]){
                    flag = max(flag, 2);
                }
            }
            else if (state[i - 1] == 2 && state[i] == 1) {
                if(a[i-1]>=a[i+1]){
                    flag = max(flag, 2);
                }
            }
            else if (state[i] == 2 || state[i] == 1) {
                flag = max(flag, 1);
            }
        }

        cout << answer - flag << '\n';
    }

    return 0;
}