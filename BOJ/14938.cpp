#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

// Floyd-Warshall(플로이드와샬) 
// @param graph : graph[src][dst] is a weight of the edge which connects src to dst
// @param size  : graph size or number of vertex
// @return      : void
void FloydWarshall(vector<vector<int>>& graph, int size) {
    for (int k = 1; k <= size; k++) { // 중간
        for (int i = 1; i <= size; i++) { // 시작
            for (int j = 1; j <= size; j++) { // 끝
                graph[j][i] = graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V, D, E;
    cin >> V >> D >> E;
    vector<vector<int>> graph(V + 1, vector<int>(V + 1, INF));
    vector<int> items(V + 1);
    vector<int> answer(V + 1, 0);
    for (int i = 1; i < V + 1; i++) {
        cin >> items[i];
    }
    for (int i = 0; i < E; i++) {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        graph[src][dst] = cost;
        graph[dst][src] = cost;
    }

    for (int i = 1; i < V + 1; i++) {
        graph[i][i] = 0;
    }

    FloydWarshall(graph, V);
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (graph[i][j] <= D) {
                answer[i] += items[j];
            }
        }
    }
    sort(answer.rbegin(), answer.rend());
    cout << answer[0] << endl;
    return 0;
}