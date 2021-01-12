#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

vector<int> dist;
class Compare {
public:
    bool operator()(int a, int b) {
        return dist[a] > dist[b];
    }
};

// Dijkstra(다익스트라)
// this function require belows
// global variable dist (vector<int> type) and
// Compare class which is used as functor of priority queue
// @oaram gragh : graph[src] is a vector of {dst,cost}
// @oaram V     : the number of vertex
// @oaram init  : initial node to search
// @return      : void
void Dijkstra(const vector<vector<pair<int, int>>>& graph, int V, int init) {
    dist.resize(V + 1, INF);
    dist[init] = 0;
    priority_queue<int, vector<int>, Compare> pq;
    pq.emplace(init);
    while (!pq.empty()) {
        int src = pq.top();
        pq.pop();
        for (auto iter = graph[src].begin(); iter != graph[src].end(); iter++) {
            int dst, cost;
            tie(dst, cost) = *iter;
            if (dist[dst] > dist[src] + cost) {
                dist[dst] = dist[src] + cost;
                pq.emplace(dst);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V, E, init, goal;
    cin >> V >> E;
    vector<vector<pair<int, int>>> graph(V + 1);
    for (int i = 0; i < E; i++) {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        graph[src].emplace_back(dst, cost);
    }
    cin >> init >> goal;
    Dijkstra(graph, V, init);
    cout << dist[goal] << endl;
    return 0;
}