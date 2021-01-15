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

// Bellman-Ford(벨만포드) 
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
// @brief : this function require 
// global variable dist (vector<int> type) and 
// Compare class which is used as functor of priority queue
// @param gragh : graph[src] is a vector of {dst,cost}
// @param V     : the number of vertex
// @param init  : initial node to search
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

// DFS(Depth-First-Search, 깊이우선탐색) 
// @brief : find a heaviest node
// @param gragh : graph[src] is a vector of {dst,cost}
// @param V     : the number of vertex
// @param init  : initial node to search
// @return      : pair of index and cost about the heaviest node
pair<int,int> DFS(const vector<vector<pair<int,int>>>& graph, int V, int init){
    int max_idx = 0;
    int max_len = 0;
    vector<bool> visited(V+1, false);
    stack<pair<int,int>> search_stack;
    search_stack.emplace(init, 0);
    visited[init] = true;
    while(!search_stack.empty()){
        int src, length;
        tie(src, length) = search_stack.top();
        if(max_len < length){
            max_idx = src;
            max_len = length;
        }
        search_stack.pop();
        for(auto child : graph[src]){
            if(!visited[child.first]){
                visited[child.first] = true;
                search_stack.emplace(src, length);
                search_stack.emplace(child.first, length + child.second);
                break;
            }
        }
    }
    return {max_idx, max_len};
}

// BFS(Breadth-First-Search, 너비우선탐색) 
// @brief : find a heaviest node
// @param gragh : graph[src] is a vector of {dst,cost}
// @param V     : the number of vertex
// @param init  : initial node to search
// @return      : pair of index and cost about the heaviest node
pair<int,int> BFS(const vector<vector<pair<int,int>>>& graph, int V, int init){
    int max_idx = 0;
    int max_len = 0;
    vector<bool> visited(V+1, false);
    queue<pair<int,int>> search_queue;
    search_queue.emplace(init, 0);
    visited[init] = true;
    while(!search_queue.empty()){
        int src, length;
        tie(src, length) = search_queue.front();
        if(max_len < length){
            max_idx = src;
            max_len = length;
        }
        search_queue.pop();
        for(auto child : graph[src]){
            if(!visited[child.first]){
                visited[child.first] = true;
                search_queue.emplace(child.first, length + child.second);
            }
        }
    }
    return {max_idx, max_len};
}

// Pre-order(전위순회) 
// @brief : print node value in char type
// @param tree : is a binary tree and tree[src] is a vector of {dst,cost}
// @param node : must be [0:25]
// @return     : void
void PreOrder(const vector<vector<pair<int, int>>>& tree, int node){
    cout << char(node+'A');
    if(tree[node][0].second != INF){
        PreOrder(tree, tree[node][0].first);
    }
    if(tree[node][1].second != INF){
        PreOrder(tree, tree[node][1].first);
    }
}

// In-order(중위순회) 
// @brief : print node value in char type
// @param tree : is a binary tree and tree[src] is a vector of {dst,cost}
// @param node : must be [0:25]
// @return     : void
void InOrder(const vector<vector<pair<int, int>>>& tree, int node){
    if(tree[node][0].second != INF){
        InOrder(tree, tree[node][0].first);
    }
    cout << char(node+'A');
    if(tree[node][1].second != INF){
        InOrder(tree, tree[node][1].first);
    }
}

// Post-order(후위순회) 
// @brief : print node value in char type
// @param tree : is a binary tree and tree[src] is a vector of {dst,cost}
// @param node : must be [0:25]
// @return     : void
void PostOrder(const vector<vector<pair<int, int>>>& tree, int node){
    if(tree[node][0].second != INF){
        PostOrder(tree, tree[node][0].first);
    }
    if(tree[node][1].second != INF){
        PostOrder(tree, tree[node][1].first);
    }
    cout << char(node+'A');
}

// LCS(Longest-Common-Subsequence, 최장공통부분수열) 
// @brief : find a longest length of LCS which will be stored int cache[a.length()][b.length()]
// @param a : string a
// @param b : string b
// @return   : void
void LongestCommonSubsequence(const string& a, const string& b) {
    vector<vector<int>> cache(1001,vector<int>(1001,0));
    for (int i = 0; i < a.length(); i++) {
        for (int j = 0; j < b.length(); j++) {
            if (a[i] == b[j]) {
                cache[i + 1][j + 1] = cache[i][j] + 1;
            }
            else {
                cache[i + 1][j + 1] = max(cache[i + 1][j], cache[i][j + 1]);
            }
        }
    }
}

// 0-1 Knapsack(0-1 배낭문제) 
// @brief : input each item's weight and value and 
// print a maximum value which will be stored in cache[K]
// @param N : the number of items
// @param K : maximum weight
// @return  : void
void Knapsack(int N, int K) {
    vector<int> cache(K + 1, 0); // cache[i] is max weight up to index i
    vector<vector<int>> item(N + 1, vector<int>(2, 0)); // {weight, value}
    for (int i = 1; i <= N; i++) {
        cin >> item[i][0] >> item[i][1];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = K; j >= 1; j--) {
            if (item[i][0] <= j) {
                cache[j] = max(cache[j], cache[j - item[i][0]] + item[i][1]);
            }
        }
    }
    cout << cache[K] << '\n';
    return;
}

// 2-pointer (투포인터) 
// @brief : print the count when the sum of the cache's subequence is same to the target
// @param cache  : must be a ascending vector
// @param target : what you think
// @return       : void
void TwoPointer(const vector<int>& cache, int target) {
    int answer = 0;
    if (cache.empty()) {
        cout << answer << endl;
        return;
    }
    int lo = 0, hi = 0;
    int sum = cache[lo];
    while (lo <= hi && hi < cache.size() && cache[hi] <= N) {
        if (sum < target) {
            sum += cache[++hi];
        }
        else if (sum > target) {
            sum -= cache[lo++];
        }
        else {
            sum += cache[++hi];
            sum -= cache[lo++];
            answer++;
        }
    }
    cout << answer << endl;
    return;
}