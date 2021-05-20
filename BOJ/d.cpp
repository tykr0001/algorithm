#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

vector<vector<pair<int,int>>> edge;
vector<vector<int>> reverse_edge(1001);
priority_queue<int> pq;
vector<int> trap_idx(2001);
vector<int> node_weight(2001, INF);

int dijkstra(int n, int init) {
    pq.emplace(init);
    node_weight[init] = 0;
    while (!pq.empty()) {
        auto top = pq.top();
        if (trap_idx[top]) {
            for (int i=1; i<=n; i++){
                if(reverse_edge[top][i]) {
                    if(node_weight[top] + reverse_edge[top][i] < node_weight[i]) {
                        pq.emplace(i);
                    }
                }
            }
        }
    }
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
    edge.resize(n + 1);
    node_weight.resize(2001);
    for (int i = 0; i < roads.size(); i++) {
        int src, dst, dist;
        src = roads[i][0];
        dst = roads[i][1];
        dist = roads[i][2];
        edge[src][dst] = {min(edge[src][dst].first, dist),1};
        edge[dst][src] = {min(edge[dst][src].first, dist),0};
    }

    for (int i = 0; i < traps.size(); i++) {
        trap_idx[traps[i]]++;
    }

    answer = dijkstra(n, start);
    return answer;
}

int main(void) {

}