#include <bits/stdc++.h>
#define INF 1e9s

using namespace std;

// Bellman-Ford
// @param graph : graph[src] == vector<dst,cost>
// @param V     : the number of vertex
// @param init  : initial node to search
// @return      : if graph doesn't have minus cycle, return true
bool BellmanFord(vector<vector<pair<int, int>>>& graph, int V, int init) {
    vector<int> dist(V + 1, INF);
    dist[init] = 0;

    // iterator each node V times , O(VE)
    for (int i = 0; i < V; i++) {
        for (int src = 1; src <= V; src++) {
            for (auto iter = graph[src].begin(); iter != graph[src].end(); iter++) {
                int dst = iter->first;
                int cost = iter->second;
                if (dist[dst] > dist[src] + cost) {
                    dist[dst] = dist[src] + cost;
                    // In Vth search, determine graph has minus cycle or not
                    if (i == V - 1) {
                        return false;
                    }
                }
            }
        }
    }

    // graph doesn't have minus cycle
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int V, E, W;
        cin >> V >> E >> W;
        vector<vector<pair<int, int>>> graph(V + 1);

        for (int i = 0; i < E; i++) {
            int src, dst, cost;
            cin >> src >> dst >> cost;
            graph[src].emplace_back(dst, cost);
            graph[dst].emplace_back(src, cost);
        }

        for (int i = 0; i < W; i++) {
            int src, dst, cost;
            cin >> src >> dst >> cost;
            graph[src].emplace_back(dst, -cost);
        }

        if (!BellmanFord(graph, V, 1)) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
}