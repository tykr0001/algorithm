#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> sticker(2, vector<int>(N));
        vector<vector<int>> cache(2, vector<int>(N + 2, 0));

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < N; j++) {
                cin >> sticker[i][j];
            }
        }


        for (int j = 0; j < N; j++) {
            for (int i = 0; i < 2; i++) {
                if (i == 0) {
                    cache[i][j + 2] = max(cache[1][j + 1], cache[1][j]) + sticker[i][j];
                }
                else {
                    cache[i][j + 2] = max(cache[0][j + 1], cache[0][j]) + sticker[i][j];
                }
            }
        }

        cout << max(max(cache[0][N], cache[0][N + 1]), max(cache[1][N], cache[1][N + 1])) << '\n';
    }

    return 0;
}