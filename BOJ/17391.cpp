#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> dp; // i, j 까지 가는 데에 필요한 최소 격자 수
queue<pair<int, int>> q; // BFS queue

bool CheckBorder(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M;
}

void BFS() {
    q.emplace(0, 0);
    dp[0][0] = 0;
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        int r = front.first;
        int c = front.second;
        int boost = map[r][c];
        for (int i = r + 1; i <= r + boost; i++) {
            if (CheckBorder(i, c)) {
                if (dp[i][c] > dp[r][c] + 1) {
                    dp[i][c] = dp[r][c] + 1;
                    q.emplace(i, c);
                }
            }
        }
        for (int j = c + 1; j <= c + boost; j++) {
            if (CheckBorder(r, j)) {
                if (dp[r][j] > dp[r][c] + 1) {
                    dp[r][j] = dp[r][c] + 1;
                    q.emplace(r, j);
                }
            }
        }
    }
}

int main(void) {
    cin >> N >> M;
    map.resize(N, vector<int>(M, 0));
    dp.resize(N, vector<int>(M, INT32_MAX));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    BFS();
    cout << dp[N - 1][M - 1] << endl;

    return 0;
}