#include <bits/stdc++.h>

using namespace std;

vector<list<pair<int, int>>> graph;
int N, E;

class Compare {
public:
    bool operator()(const tuple<int, int>& a, const tuple<int, int>& b) {
        return get<1>(a) > get<1>(b);
    }
};

int Dijkstra(int src, int dst) {
    if (src == dst) {
        return 0;
    }
    vector<int> table;
    table.resize(N + 1, INT32_MAX);
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, Compare> pq;
    pq.emplace(src, 0);
    table[src] = 0;
    while (!pq.empty()) {
        int i, d;
        tie(i, d) = pq.top();
        if (i == dst) {
            return d;
        }
        pq.pop();
        for (auto iter = graph[i].begin(); iter != graph[i].end(); iter++) {
            if (d + iter->second < table[iter->first]) {
                table[iter->first] = d + iter->second;
                pq.emplace(iter->first, d + iter->second);
            }
        }
    }
    return -1;
}

int main(void) {
    int v_1, v_2;
    cin >> N >> E;
    graph.resize(N + 1);
    for (int i = 0; i < E; i++) {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        graph[src].emplace_back(dst, cost);
        graph[dst].emplace_back(src, cost);
    }
    cin >> v_1 >> v_2;
    int a = Dijkstra(1, v_1);
    int b = Dijkstra(1, v_2);
    int c = Dijkstra(v_1, N);
    int d = Dijkstra(v_2, N);
    int m = Dijkstra(v_1, v_2);

    if (m != -1) {
        if (a == -1 && b == -1 || c == -1 && d == -1) {
            cout << -1 << endl;
        }
        else if (a == -1 || d == -1)
            cout << b + m + c;
        else if (b == -1 || c == -1)
            cout << a + m + d;
        else {
            if (a + d < b + c) {
                cout << a + m + d;
            }
            else {
                cout << b + m + c;
            }
        }
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}