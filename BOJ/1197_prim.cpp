#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using pii = pair<int, int>;

vector<bool> visited;
// graph[src] = vector<weight, dst>
vector<vector<pii>> graph; 
int V, E;

int Prim(int init) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; // <weight, node>
    pq.push(pii(0, init));
    int ret = 0;
    while (!pq.empty()) {
        auto edge = pq.top();
        pq.pop();
        if (visited[edge.second])
            continue;
        visited[edge.second] = true;
        ret += edge.first;
        for (pii next_edge : graph[edge.second]) {
            if (!visited[next_edge.second]) {
                pq.push(next_edge);
            }
        }
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> E;
    graph.resize(V + 1);
    visited.resize(V + 1);
    while (E--) {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        graph[src].emplace_back(cost, dst);
        graph[dst].emplace_back(cost, src);
    }
    cout << Prim(1);
}