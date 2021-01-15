#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    int mask = (1 << 26) - 1;
    cin >> N >> M;
    vector<int> str(N);

    for (int i = 0; i < N; i++) {
        string inp;
        cin >> inp;
        for (int j = 0; j < inp.size(); j++) {
            str[i] |= 1 << (inp[j] - 'a');
        }
    }

    for (int i = 0; i < M; i++) {
        int o;
        char x;
        int cnt = 0;
        cin >> o >> x;
        if (o == 1) {
            mask ^= 1 << (x - 'a');
        }
        else {
            mask |= 1 << (x - 'a');
        }
        for (int i = 0; i < N; i++) {
            if ((str[i] & mask) == str[i]) {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}