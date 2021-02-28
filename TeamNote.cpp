#include <bits/stdc++.h>
#define INF 1e9
typedef long long ll;
using namespace std;

// Comment template
// Title
// @brief :
// @param : 
// @param : 
// @return :

// @brief : failure function vector used in KMP 
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

// Floyd-Warshall(�÷��̵�ͼ�) 
// @param graph : graph[src][dst] is a weight of the edge which connects src to dst
// @param size  : graph size or number of vertex
// @return      : void
void FloydWarshall(vector<vector<int>>& graph, int size) {
    for (int k = 1; k <= size; k++) { // �߰�
        for (int i = 1; i <= size; i++) { // ����
            for (int j = 1; j <= size; j++) { // ��
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

// Bellman-Ford(��������) 
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
// Dijkstra(���ͽ�Ʈ��) 
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

// DFS(Depth-First-Search, ���̿켱Ž��) 
// @brief : find a heaviest node
// @param gragh : graph[src] is a vector of {dst,cost}
// @param V     : the number of vertex
// @param init  : initial node to search
// @return      : pair of index and cost about the heaviest node
pair<int, int> DFS(const vector<vector<pair<int, int>>>& graph, int V, int init) {
    int max_idx = 0;
    int max_len = 0;
    vector<bool> visited(V + 1, false);
    stack<pair<int, int>> search_stack;
    search_stack.emplace(init, 0);
    visited[init] = true;
    while (!search_stack.empty()) {
        int src, length;
        tie(src, length) = search_stack.top();
        if (max_len < length) {
            max_idx = src;
            max_len = length;
        }
        search_stack.pop();
        for (auto child : graph[src]) {
            if (!visited[child.first]) {
                visited[child.first] = true;
                search_stack.emplace(src, length);
                search_stack.emplace(child.first, length + child.second);
                break;
            }
        }
    }
    return { max_idx, max_len };
}

// BFS(Breadth-First-Search, �ʺ�켱Ž��) 
// @brief : find a heaviest node
// @param gragh : graph[src] is a vector of {dst,cost}
// @param V     : the number of vertex
// @param init  : initial node to search
// @return      : pair of index and cost about the heaviest node
pair<int, int> BFS(const vector<vector<pair<int, int>>>& graph, int V, int init) {
    int max_idx = 0;
    int max_len = 0;
    vector<bool> visited(V + 1, false);
    queue<pair<int, int>> search_queue;
    search_queue.emplace(init, 0);
    visited[init] = true;
    while (!search_queue.empty()) {
        int src, length;
        tie(src, length) = search_queue.front();
        if (max_len < length) {
            max_idx = src;
            max_len = length;
        }
        search_queue.pop();
        for (auto child : graph[src]) {
            if (!visited[child.first]) {
                visited[child.first] = true;
                search_queue.emplace(child.first, length + child.second);
            }
        }
    }
    return { max_idx, max_len };
}

// Pre-order(������ȸ) 
// @brief : print node value in char type
// @param tree : is a binary tree and tree[src] is a vector of {dst,cost}
// @param node : must be [0:25]
// @return     : void
void PreOrder(const vector<vector<pair<int, int>>>& tree, int node) {
    cout << char(node + 'A');
    if (tree[node][0].second != INF) {
        PreOrder(tree, tree[node][0].first);
    }
    if (tree[node][1].second != INF) {
        PreOrder(tree, tree[node][1].first);
    }
}

// In-order(������ȸ) 
// @brief : print node value in char type
// @param tree : is a binary tree and tree[src] is a vector of {dst,cost}
// @param node : must be [0:25]
// @return     : void
void InOrder(const vector<vector<pair<int, int>>>& tree, int node) {
    if (tree[node][0].second != INF) {
        InOrder(tree, tree[node][0].first);
    }
    cout << char(node + 'A');
    if (tree[node][1].second != INF) {
        InOrder(tree, tree[node][1].first);
    }
}

// Post-order(������ȸ) 
// @brief : print node value in char type
// @param tree : is a binary tree and tree[src] is a vector of {dst,cost}
// @param node : must be [0:25]
// @return     : void
void PostOrder(const vector<vector<pair<int, int>>>& tree, int node) {
    if (tree[node][0].second != INF) {
        PostOrder(tree, tree[node][0].first);
    }
    if (tree[node][1].second != INF) {
        PostOrder(tree, tree[node][1].first);
    }
    cout << char(node + 'A');
}

// LCS(Longest-Common-Subsequence, �������κм���) 
// @brief : find a longest length of LCS which will be stored int cache[a.length()][b.length()]
// @param a : string a
// @param b : string b
// @return   : void
void LCS(const string& a, const string& b) {
    vector<vector<int>> cache(1001, vector<int>(1001, 0));
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

// 0-1 Knapsack(0-1 �賶����) 
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

// 2-pointer (��������) 
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
    while (lo <= hi && hi < cache.size() && cache[hi] <= target) {
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

vector<int> parent;
// Find(���ε�)
// @brief      : Find the root node of parameter
// @param node : A child node
// @return     : Index of the root node
int Find(int node) {
    if (parent[node] == node) {
        return node;
    }
    else {
        return parent[node] = Find(parent[node]);
    }
}

// Union(���Ͽ�)
// @brief   : Union the disjoint set
// @param a : child node of the set
// @param b : child node of another set
// @return  : void
void Union(int a, int b) {
    parent[Find(a)] = Find(b);
}

vector<bool> is_prime;
vector<int> cache;
// Sieve of Eratosthenes(�����佺�׳׽��� ü)
// @brief  : Find prime numbers under n
// @return : void
void Eratos(int n) {
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            cache.emplace_back(i);
            for (int j = i * 2; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}


// LIS(Longest-Increasing-Subsequence ���������κм���)
// @brief     : print length and elements of LIS
// @param arr : target vector
// @return    : void
void LIS(vector<int>& arr) {
    vector<int> lis;
    vector<int> idx;
    vector<int> answer;
    lis.emplace_back(arr[0]);
    idx.emplace_back(0);
    for (int i = 1; i < arr.size(); i++) {
        if (lis.back() < arr[i]) {
            lis.emplace_back(arr[i]);
            idx.emplace_back(lis.size() - 1);
        }
        else {
            auto iter = lower_bound(lis.begin(), lis.end(), arr[i]);
            *iter = arr[i];
            idx.emplace_back(distance(lis.begin(), iter));

        }
    }

    for (int i = arr.size() - 1, j = lis.size() - 1; i >= 0; i--) {
        if (idx[i] == j) {
            answer.emplace_back(arr[i]);
            j--;
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
}


vector<ll> arr;
vector<ll> tree;
// Segment-Tree(���׸�ƮƮ��)
// @brief           : Build segment-tree which memorizes partial sum
// @param node      : node index (root node == 1)
// @param start,end : array index (init start == 0, init end == array size - 1)
// @return          : Partial sum from start to end
ll InitSegmentTree(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    else {
        return tree[node] = InitSegmentTree(node * 2, start, (start + end) / 2) + InitSegmentTree(node * 2 + 1, (start + end) / 2 + 1, end);
    }
}

// @brief : Update segment tree with index and value
// @param node       : node index (root node == 1)
// @param start, end : array index (init start == 0, init end == array size - 1)
// @param idx        : index of new value
// @param k          : new value
// @return           : updated tree[node]
ll UpdateSegmentTree(int node, int start, int end, int idx, ll k) {
    if (idx < start || idx > end) {
        return tree[node];
    }
    if (start == end) {
        return tree[node] = k;
    }
    else {
        return tree[node] = UpdateSegmentTree(node * 2, start, (start + end) / 2, idx, k) + tree[node * 2 + 1] + UpdateSegmentTree(node * 2 + 1, (start + end) / 2 + 1, end, idx, k);
    }
}

// @brief            : return partial sum of segment-tree
// @param start,end  : array index (init start == 0, init end == array size - 1)
// @param left,right : array index to get the partial sum
// @return           : partial sum
ll SumSegmentTree(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    else {
        return SumSegmentTree(node * 2, start, (start + end) / 2, left, right) + SumSegmentTree(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    }
}