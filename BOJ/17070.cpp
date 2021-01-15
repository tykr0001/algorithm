#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> house;

// cache[i][j][state], state : 0->horizon, 1->vertical 2->diagonal
vector<vector<vector<int>>> cache;

void DP(void) {
    cache[0][1][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (j + 1 < N && house[i][j + 1] != 1) {
                cache[i][j + 1][0] += cache[i][j][0] + cache[i][j][2];
            }
            if (i + 1 < N && house[i + 1][j] != 1) {
                cache[i + 1][j][1] += cache[i][j][1] + cache[i][j][2];
            }
            if (i + 1 < N && j + 1 < N && house[i + 1][j] != 1 && house[i][j + 1] != 1 && house[i + 1][j + 1] != 1) {
                cache[i + 1][j + 1][2] += cache[i][j][0] + cache[i][j][1] + cache[i][j][2];
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    house.resize(N, vector<int>(N, 0));
    cache.resize(N, vector<vector<int>>(N, vector<int>(3, 0)));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> house[i][j];
        }
    }
    DP();
    cout << cache[N - 1][N - 1][0] + cache[N - 1][N - 1][1] + cache[N - 1][N - 1][2] << endl;
}