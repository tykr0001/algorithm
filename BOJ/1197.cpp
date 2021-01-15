#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int V;
int E;
int init_src;
int init_dst;
int init_weight = INF;
vector<list<pair<int, int>>> graph;

class Compare {
public:
    bool operator()(const tuple<int, int, int>& lhs, const tuple<int, int, int>& rhs) {
        return get<2>(lhs) > get<2>(rhs);
    }
};

int MST(const vector<list<pair<int, int>>>& graph, int V) {
    int ret = 0;
    int cnt = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Compare> pq;
    vector<bool> searched(V + 1, false);
    pq.emplace(init_src, init_dst, init_weight);
    searched[init_src] = true;
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (!searched[get<1>(top)]) {
            searched[get<1>(top)] = true;
            ret += get<2>(top);
            if (++cnt == V - 1) {
                break;
            }
            for (auto next : graph[get<0>(top)]) {
                if (!searched[next.first]) {
                    pq.emplace(get<0>(top), next.first, next.second);
                }
            }
            for (auto next : graph[get<1>(top)]) {
                if (!searched[next.first]) {
                    pq.emplace(get<1>(top), next.first, next.second);
                }
            }
        }
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E;
    graph.resize(V + 1);
    for (int i = 0; i < E; i++) {
        int src, dst, weight;
        cin >> src >> dst >> weight;
        graph[src].emplace_back(dst, weight);
        graph[dst].emplace_back(src, weight);
        if (weight < init_weight) {
            init_src = src;
            init_dst = dst;
            init_weight = weight;
        }
    }
    cout << MST(graph, V);
}