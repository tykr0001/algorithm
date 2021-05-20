#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using pii = pair<int, int>;

vector<int> parent;



vector<pair<int, pii>> edge; // <cost, <src, dst>>



int V, E;

int Find(int n) {
    if (parent[n] == n) return n;
    else return parent[n] = Find(parent[n]);
}

void Union(int p, int c) {
    parent[Find(c)] = Find(p);
}

int Kruskal(void) {
    int ret = 0;
    for (auto& e : edge) {
        int cost = e.first;
        int src = e.second.first;
        int dst = e.second.second; 
        if (Find(src) != Find(dst)) {
            Union(src, dst);
            ret += cost;
        }
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> E;
    edge.resize(E);
    parent.resize(V + 1);
    for (int i = 1; i <= V; i++)
        parent[i] = i;

    for (auto& elem : edge) {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        elem = pair<int, pii>(cost, pii(src, dst));
    }
    sort(edge.begin(), edge.end());

    cout << Kruskal();
    return 0;
}