#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

void FloydWarshall(vector<vector<int>>& graph, int size) {
    for (int k = 1; k <= size; k++) { // 중간
        for (int i = 1; i <= size; i++) { // 시작
            for (int j = 1; j <= size; j++) { // 끝
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V + 1, vector<int>(V + 1, 1e9));
    for (int i = 1; i <= V; i++) {
        graph[i][i] = 0;
    }
    for (int i = 0; i < E; i++) {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        graph[src][dst] = min(graph[src][dst], cost);
    }

    FloydWarshall(graph, V);

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (graph[i][j] == INF)
                graph[i][j] = 0;
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}