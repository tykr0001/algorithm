#include <bits/stdc++.h>

using namespace std;

int N, M;
int answer = 5000;
int answer_idx;
vector<vector<int>> v;

void FloydWarshall(void) {
    for (int k = 1; k <= N; k++) { // 중간
        for (int i = 1; i <= N; i++) { // 시작
            for (int j = 1; j <= N; j++) { // 끝
                v[j][i] = v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }
}

int KevinBaconNumber(int i) {
    int ret = 0;
    for (int j = 1; j <= N; j++) {
        if (v[i][j] != 5000) {
            ret += v[i][j];
        }
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    v.resize(N + 1, vector<int>(N + 1, 5000));
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        v[x][y] = v[y][x] = 1;
    }
    for (int i = 1; i <= N; i++) {
        v[i][i] = 0;
    }
    FloydWarshall();

    for (int i = 1; i <= N; i++) {
        int tmp = KevinBaconNumber(i);
        if (answer > tmp) {
            answer = tmp;
            answer_idx = i;
        }
    }

    cout << answer_idx << endl;
    return 0;
}