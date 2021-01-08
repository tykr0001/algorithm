#include <bits/stdc++.h>

using namespace std;

int N; // num of vertex
int M; // num of edge
int X; // goal;

vector<vector<int>> g;
int answer = 0;

void FloydWarshall(void) {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (g[i][k] != -1 && g[k][j] != -1) {
                    if (g[i][j] != -1) {
                        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                    }
                    else {
                        g[i][j] = g[i][k] + g[k][j];
                    }
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> X;
    g.resize(N + 1, vector<int>(N + 1, -1));
    for (int i = 0; i < M; i++) {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        g[src][dst] = cost;
    }
    for (int i = 0; i <= N; i++) {
        g[i][i] = 0;
    }

    FloydWarshall();

    for (int i = 1; i <= N; i++) {
        if (answer < g[i][X] + g[X][i]) {
            answer = g[i][X] + g[X][i];
        }
    }
    cout << answer << '\n';
    // debug
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << g[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    return 0;
}