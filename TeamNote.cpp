#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

// failure function vector used in KMP
// @param p : pattern string
// @return  : longest length up to each index when prefix & suffix are the same
vector<int> GetPi(const string& p) {
    vector<int> pi(p.size(), 0);
    int j = 0;
    for (int i = 1; i < p.size(); i++) {
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            pi[i] = ++j;
        }
    }
    return pi;
}

// KMP(Knuth-Morris-Pratt)
// @param s : origin string
// @param p : pattern string
// @return  : vector that stores the initial indexs where the pattern appears in the origin
vector<int> KMP(const string& s, const string& p) {
    vector<int> ret;
    vector<int> pi = GetPi(p);
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        while (j > 0 && s[i] != p[j]) {
            j = pi[j - 1];
        }
        if (s[i] == p[j]) {
            if (j == p.size() - 1) {
                ret.push_back(i - j);
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }
    return ret;
}

// Bellman-Ford(벨만-포드)
// @param graph : graph[src] is a vector of {dst,cost}
// @param V     : the number of vertex
// @param init  : initial node to search
// @return      : if graph doesn't have minus cycle, return true
bool BellmanFord(const vector<vector<pair<int, int>>>& graph, int V, int init) {
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