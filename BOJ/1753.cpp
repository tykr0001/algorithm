#include <bits/stdc++.h>

using namespace std;

int V, E, K;
vector<list<pair<int,int>>> graph; // graph[src] = list<dst, weight>
vector<int> dist; // dist[i] :  K to i

class Compare {
public:
    bool operator()(int a, int b) {
        return dist[a] > dist[b];
    }
};

priority_queue<int, vector<int>, Compare> pq;

void Dijkstra(int init) {
    dist[init] = 0;
    pq.emplace(init);

    while (!pq.empty()) {
        int v = pq.top();
        
        pq.pop();
        for (auto iter = graph[v].begin(); iter != graph[v].end(); iter++) {
            if (dist[iter->first] > dist[v] + iter->second) {
                dist[iter->first] = dist[v] + iter->second;
                pq.push(iter->first);
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] != INT32_MAX) {
            cout << dist[i] << '\n';
        }
        else {
            cout << "INF" << '\n';
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E >> K;
    graph.resize(V + 1);
    dist.resize(V + 1, INT32_MAX);

    for (int i = 0; i < E; i++) {
        int src, dst, weight;
        cin >> src >> dst >> weight;
        graph[src].emplace_back(dst,weight);
    }

    Dijkstra(K);

    return 0;
}