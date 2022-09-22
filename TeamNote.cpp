/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using v2i = vector<vi>;
using v3i = vector<v2i>;
using vb = vector<bool>;
using v2b = vector<vb>;
using vs = vector<string>;
using v2s = vector<vs>;
using vc = vector<char>;
using v2c = vector<vc>;
using vl = vector<ll>;
using v2l = vector<vl>;
using v3l = vector<v2l>;
using vd = vector<double>;
using v2d = vector<vd>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define rep(i,beg,end) for(int i=beg; i<end; i++)
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
template<class T>
void sort(T& container) { sort(container.begin(), container.end()); }
template<class T1, typename T2>
void sort(T1& container, T2 cmp) { sort(container.begin(), container.end(), cmp); }
template<class T1, class T2>
istream& operator>>(istream& is, pair<T1, T2>& rhs) { is >> rhs.fi >> rhs.se; return is; }
template<class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& rhs) { os << rhs.fi << ' ' << rhs.se; return os; }
template<class T>
istream& operator>>(istream& is, vector<T>& rhs) { for (T& elem : rhs) is >> elem; return is; }
template<class T>
ostream& operator<<(ostream& os, const vector<T>& rhs) { for (const T& elem : rhs) os << elem << ' '; os << endl; return os; }
template<class T>
void resize(T& container, int _size) { container.resize(_size); }
template<class T, typename... Size>
void resize(T& container, int _size, Size... _sizes) { container.resize(_size); for (auto& elem : container) resize(elem, _sizes...); }
/*************************************************/

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

// Floyd-Warshall(플로이드와샬) 
// @param graph : graph[src][dst] is a weight of the edge which connects src to dst
// @param size  : graph size or number of vertex
// @return      : void
void FloydWarshall(vector<vector<int>>& graph, int size) {
    for (int k = 1; k <= size; k++) { // 중간
        for (int i = 1; i <= size; i++) { // 시작
            for (int j = 1; j <= size; j++) { // 끝
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
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

// BFS(Breadth-First-Search, 너비우선탐색) 
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

// Pre-order(전위순회) 
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

// In-order(중위순회) 
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

// Post-order(후위순회) 
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

// LCS(Longest-Common-Subsequence, 최장공통부분수열) 
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
// Find(파인드)
// @brief      : Find the root node of parameter
// @param n    : A child node
// @return     : Index of the root node
int Find(int n) {
    if (parent[n] == n) return n;
    else return parent[n] = Find(parent[n]);
}

// Union(유니온)
// @brief   : Union the disjoint set
// @param p : child node of the set (this will be the root)
// @param c : child node of another set
// @return  : void
void Union(int p, int c) {
    parent[Find(c)] = Find(p);
}

vector<bool> is_prime;
vector<int> cache;
// Sieve of Eratosthenes(에라토스테네스의 체)
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


// LIS(Longest-Increasing-Subsequence 최장증가부분수열)
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

// Segment-Tree(세그먼트트리)
struct Segment {
    vl arr;
    vl tree;
    ll MOD = INT64_MAX;

    Segment() { }
    Segment(int n) : arr(n + 1), tree(1 << int(ceil(log2(n))) + 1) { }

    // fix the Args start at 1, end at n
    ll SumInit(int node, int start, int end) {
        if (start == end) return tree[node] = arr[start];
        int mid = (start + end) / 2;
        return tree[node] = SumInit(node * 2, start, mid)
            + SumInit(node * 2 + 1, mid + 1, end);
    }

    ll SumUpdate(int node, int start, int end, int idx, ll diff) {
        if (idx < start || idx > end) return tree[node];
        if (start == end) return tree[node] += diff;
        int mid = (start + end) / 2;
        return tree[node] = SumUpdate(node * 2, start, mid, idx, diff)
            + SumUpdate(node * 2 + 1, mid + 1, end, idx, diff);
    }

    ll Sum(int node, int start, int end, int left, int right) {
        if (left > end || right < start) return 0;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return tree[node] = Sum(node * 2, start, mid, left, right)
            + Sum(node * 2 + 1, mid + 1, end, left, right);
    }

    // fix the Args start at 1, end at n
    ll MulInit(int node, int start, int end) {
        if (start == end) return tree[node] = arr[start];
        int mid = (start + end) / 2;
        return tree[node] = MulInit(node * 2, start, mid) *
            MulInit(node * 2 + 1, mid + 1, end) %
            MOD;
    }

    ll MulUpdate(int node, int start, int end, int idx, ll num) {
        if (idx < start || idx > end) return tree[node];
        if (start == end) return tree[node] = num;
        int mid = (start + end) / 2;
        return tree[node] = MulUpdate(node * 2, start, mid, idx, num) *
            MulUpdate(node * 2 + 1, mid + 1, end, idx, num) %
            MOD;
    }

    ll Mul(int node, int start, int end, int left, int right) {
        if (left > end || right < start) return 1;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return Mul(node * 2, start, mid, left, right) *
            Mul(node * 2 + 1, mid + 1, end, left, right) %
            MOD;
    }
} seg;


// Trie(트라이)
struct Trie {
    Trie* next[26];
    bool finish;

    Trie() : finish(false) {
        memset(next, 0, sizeof(next));
    }
    ~Trie() {
        for (int i = 0; i < 26; i++)
            if (next[i] != nullptr)
                delete next[i];
    }
    void Insert(const char* key) {
        if (*key == '\0') {
            finish = true;
        }
        else {
            int cur = *key - 'a';
            if (next[cur] == nullptr)
                next[cur] = new Trie();
            next[cur]->Insert(key + 1);
        }
    }
    Trie* Find(const char* key) {
        if (*key == '\0')
            return nullptr;
        if (finish)
            return this;
        int cur = *key - 'a';
        return next[cur]->Find(key + 1);
    }
};

using line = pair<pll, pll>;
/** CCW(counter-clock-wise)
 *  @return  ccw=>1, cw=>-1, pararell=>0
 */
int CCW(const pll& a, const pll& b, const pll& c) {
    ll op = (a.fi * b.se + b.fi * c.se + c.fi * a.se) -
        (a.se * b.fi + b.se * c.fi + c.se * a.fi);
    if (op > 0) return 1;
    else if (op < 0) return -1;
    else return 0;
}

/** IsIntersect(선분교차판정)
 *  @return  what you think
 */
bool IsIntersect(const line& x, const line& y) {
    pll a = x.fi;
    pll b = x.se;
    pll c = y.fi;
    pll d = y.se;
    int ab = CCW(a, b, c) * CCW(a, b, d);
    int cd = CCW(c, d, a) * CCW(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return a <= d && c <= b;
    }
    return ab <= 0 && cd <= 0;
}

// Fenwick-Tree(펜윅트리)  
struct Fenwick {
    ll n;
    vl arr;
    vl tree;
    vl bit1;
    vl bit2;

    Fenwick() { }
    Fenwick(int n) : n(n), arr(n + 1), tree(n + 1), bit1(n + 1), bit2(n + 1) { }

    ll Sum(int idx) {
        ll ret = 0;
        while (idx > 0) {
            ret += tree[idx];
            idx -= (idx & -idx);
        }
        return ret;
    }

    void Update(int idx, ll diff) {
        while (idx < tree.size()) {
            tree[idx] += diff;
            idx += (idx & -idx);
        }
    }

    ll Min(int a, int b) {
        ll ret = LINF;
        ll idx = a;
        while (idx + (idx & -idx) <= b) {
            ret = min(ret, bit2[idx]);
            idx += (idx & -idx);
        }
        if (idx <= b) ret = min(ret, arr[idx]);

        idx = b;
        while (idx - (idx & -idx) >= a) {
            ret = min(ret, bit1[idx]);
            idx -= (idx & -idx);
        }
        if (idx >= a) ret = min(ret, arr[idx]);
        return ret;
    };

    void MinUpdate(int idx, ll val) {
        if (arr[idx] == val) return;

        ll l, r;
        ll li, ri;
        ll lmin, rmin;

#define MIN_INIT {    \
            li = idx - 1;       \
            lmin = INT64_MAX;   \
            ri = idx + 1;       \
            rmin = INT64_MAX;   \
        }

#define MIN_UPDATE {                              \
            while (li > 0 && li - (li & -li) + 1 >= l) {    \
                lmin = min(lmin, bit1[li]);                 \
                li -= (li & -li);                           \
            }                                               \
            if (li >= l) lmin = min(lmin, arr[li]);         \
            while (ri <= n && ri + (ri & - ri) - 1 <= r) {  \
                rmin = min(rmin, bit2[ri]);                 \
                ri += (ri & - ri);                          \
            }                                               \
            if (ri <= min(n, r)) rmin = min(rmin, arr[ri]); \
        }

        r = idx;
        l = r - (r & -r) + 1;
        MIN_INIT;
        while (r <= n) {
            if (val <= bit1[r]) {
                bit1[r] = val;
            }
            else if (bit1[r] == arr[idx]) {
                MIN_UPDATE;
                bit1[r] = min(val, min(lmin, rmin));
            }
            r = r + (r & -r);
            l = r - (r & -r) + 1;
        }
        l = idx;
        r = l + (l & -l) - 1;
        MIN_INIT;
        while (l > 0) {
            if (val <= bit2[l]) {
                bit2[l] = val;
            }
            else if (bit2[l] == arr[idx]) {
                MIN_UPDATE;
                bit2[l] = min(val, min(lmin, rmin));
            }
            l = l - (l & -l);
            r = l + (l & -l) - 1;
        }
        arr[idx] = val;
    }

    ll Max(int a, int b) {
        ll ret = 0;
        ll idx = a;
        while (idx + (idx & -idx) <= b) {
            ret = max(ret, bit2[idx]);
            idx += (idx & -idx);
        }
        if (idx <= b) ret = max(ret, arr[idx]);

        idx = b;
        while (idx - (idx & -idx) >= a) {
            ret = max(ret, bit1[idx]);
            idx -= (idx & -idx);
        }
        if (idx >= a) ret = max(ret, arr[idx]);
        return ret;
    };

    void MaxUpdate(int idx, ll val) {
        if (arr[idx] == val) return;

        ll l, r;
        ll li, ri;
        ll lmax, rmax;

#define MAX_INIT {      \
            li = idx - 1;       \
            lmax = 0;           \
            ri = idx + 1;       \
            rmax = 0;           \
        }

#define MAX_UPDATE {                                \
            while (li > 0 && li - (li & -li) + 1 >= l) {    \
                lmax = max(lmax, bit1[li]);                 \
                li -= (li & -li);                           \
            }                                               \
            if (li >= l) lmax = max(lmax, arr[li]);         \
            while (ri <= n && ri + (ri & - ri) - 1 <= r) {  \
                rmax = max(rmax, bit2[ri]);                 \
                ri += (ri & - ri);                          \
            }                                               \
            if (ri <= max(n, r)) rmax = max(rmax, arr[ri]); \
        }

        r = idx;
        l = r - (r & -r) + 1;
        MAX_INIT;
        while (r <= n) {
            if (val >= bit1[r]) {
                bit1[r] = val;
            }
            else if (bit1[r] == arr[idx]) {
                MAX_UPDATE;
                bit1[r] = max(val, min(lmax, rmax));
            }
            r = r + (r & -r);
            l = r - (r & -r) + 1;
        }
        l = idx;
        r = l + (l & -l) - 1;
        MAX_INIT;
        while (l > 0) {
            if (val >= bit2[l]) {
                bit2[l] = val;
            }
            else if (bit2[l] == arr[idx]) {
                MAX_UPDATE
                    bit2[l] = max(val, min(lmax, rmax));
            }
            l = l - (l & -l);
            r = l + (l & -l) - 1;
        }
        arr[idx] = val;
    }
} fen;

// 2D Fenwick-Tree(2차원 펜윅트리)
struct Fenwick2D {
    ll n;
    v2l arr;
    v2l tree;

    Fenwick2D() { }
    Fenwick2D(int n) : n(n), arr(n + 1, vl(n + 1)), tree(n + 1, vl(n + 1)) { }

    void Update(int x, int y, ll diff) {
        while (x < n + 1) {
            int tmp_y = y;
            while (tmp_y < n + 1) {
                tree[x][tmp_y] = tree[x][tmp_y] + diff;
                tmp_y = tmp_y + (tmp_y & -tmp_y);
            }
            x = x + (x & -x);
        }
    }

    // default Query is Sum
    ll Query(int x, int y) {
        ll ret = 0;
        while (x > 0) {
            int tmp_y = y;
            while (tmp_y < n + 1) {
                ret = ret + tree[x][tmp_y];
                tmp_y = tmp_y - (tmp_y & -tmp_y);
            }
            x = x - (x & -x);
        }
        return ret;
    }

} fen;

// FFT(Fast-Fourier-Transform, 고속 푸리에 변환)
typedef complex<double> base;
void FFT(vector<base>& a, bool inv = false) {
    int size = a.size();
    for (int i = 1, j = 0; i < size; i++) {
        int bit = (size >> 1);
        while (j >= bit) {
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int i = 2; i <= size; i <<= 1) {
        double ang = 2 * acos(-1) / i * (inv ? -1 : 1);
        base wlen(cos(ang), sin(ang));
        for (int j = 0; j < size; j += i) {
            base w(1);
            for (int k = 0; k < i / 2; k++) {
                base u = a[j + k], v = a[j + k + i / 2] * w;
                a[j + k] = u + v;
                a[j + k + i / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (inv) for (int i = 0; i < size; i++) a[i] /= size;
}

vl Multiply(vl& v, vl& w) {
    vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
    int size = 2; while (size < v.size() + w.size()) size <<= 1;
    fv.resize(size); fw.resize(size);
    FFT(fv, 0); FFT(fw, 0);
    for (int i = 0; i < size; i++) fv[i] *= fw[i];
    FFT(fv, 1);
    vl ret(size);
    for (int i = 0; i < size; i++) ret[i] = (ll)round(fv[i].real());
    return ret;
}

vl Multiply(vl& v, vl& w, ll mod) {
    int size = 2;
    while (size < v.size() + w.size()) size <<= 1;
    vector<base> v1(size), v2(size), r1(size), r2(size);
    for (int i = 0; i < v.size(); i++) {
        v1[i] = base(v[i] >> 15, v[i] & 32767);
    }
    for (int i = 0; i < w.size(); i++) {
        v2[i] = base(w[i] >> 15, v[i] & 32767);
    }
    FFT(v1, 0); FFT(v2, 0);
    for (int i = 0; i < size; i++) {
        int j = (i ? size - 1 : i);
        base ans1 = (v1[i] + conj(v1[j])) * base(0.5, 0);
        base ans2 = (v1[i] + conj(v1[j])) * base(0, -0.5);
        base ans3 = (v2[i] + conj(v2[j])) * base(0.5, 0);
        base ans4 = (v2[i] + conj(v2[j])) * base(0, -0.5);
        r1[i] = (ans1 * ans3) + (ans1 * ans4) * base(0, 1);
        r2[i] = (ans2 * ans3) + (ans2 * ans4) * base(0, 1);
    }
    FFT(r1, 1); FFT(r2, 1);
    vl ret(size);
    for (int i = 0; i < size; i++) {
        ll av = (ll)round(r1[i].real());
        ll bv = (ll)round(r1[i].imag()) + (ll)round(r2[i].real());
        ll cv = (ll)round(r2[i].imag());
        av %= mod; bv %= mod; cv %= mod;
        ret[i] = (av << 30) + (bv << 15) + cv;
        ret[i] = (ret[i] % mod + mod) % mod;
    }
    return ret;
}

// Miller-Rabin(밀러 라빈 소수 판별법)
// int범위와 long long범위에 따라 base prime 다르게 사용
ull Pow(ull x, ull y, ull mod = 1) { // return (x ^ y) % mod
    ull ret = 1;
    x %= mod;
    while (y) {
        if (y & 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ret;
}

bool isPrime_MillerRabin(ull p) {
    ull a[] = { 2,3,61,LLONG_MAX,2,3,5,7,11,13,17,19,23,29,31,37,LLONG_MAX };	//LLONG_MAX is composite number
    ull i = p <= UINT_MAX ? 0 : 4;
    while (a[i] < p) {
        ull s = p - 1;
        while (true) {
            ull r = Pow(a[i], s, p);
            if (r == p - 1) break;	// p is probably a prime.
            if (s & 1) {	//if s is odd number
                if (r == 1) break;	// p is probably a prime.
                else return 0;	// s is composite
            }
            s >>= 1;
        }
        i++;
    }
    return p < 2 ? 0 : p != LLONG_MAX;
}

// Pollard's-rho(폴라드로)
// 곱셈연산중 ull 범위를 벗어날 경우 __int128 사용 
// return smallest divisor
ull FindDiv(ll n) {
    if (n % 2 == 0) return 2;
    if (isPrime_MillerRabin(n)) return n;

    ll x = rand() % (n - 2) + 2, y = x, c = rand() % 10 + 1, g = 1;
    while (g == 1) {
        x = (x * x % n + c) % n;
        y = (y * y % n + c) % n;
        y = (y * y % n + c) % n;
        g = __gcd(abs(ll(x - y)), n);
        if (g == n) return FindDiv(n);
    }
    if (isPrime_MillerRabin(g)) return g;
    else return FindDiv(g);
}

// EEA(Extended-Euclidean-Algorithm, 확장 유클리드 알고리즘)
// a * s + b * t = gcd(a, b)
// return multiplicative inverse of b (modulo a) if it exists, else 0
ll EEA(ll a, ll b) {
	ll r1 = a, r2 = b, s1 = 1, s2 = 0, t1 = 0, t2 = 1;
	ll r, s, t, q;
	while (r2) {
		q = r1 / r2;
		// gcd 계산
		r = r1 % r2;
		r1 = r2, r2 = r;

		// s 계산
		s = s1 - q * s2;
		s1 = s2, s2 = s;

		// t 계산
		t = t1 - q * t2;
		t1 = t2, t2 = t;
	}
	r = r1, s = s1, t = t1;

	if (r == 1) 
		return (t + a) % a;
	else 
        return 0;
}

// CRT(Chinese-Remainder-Theorem, 중국인 나머지 정리)
// return smallest solution
ll Inv(ll x, ll mod) {
    return Pow(x, mod-2);
}

ll MinCRT(vl& m, vl& a) {
    int size = a.size();
    ll M = 1;
    ll ret = 0;
    for(int i=0; i<size; i++)
        M *= m[i];
    for(int i=0; i<size; i++) {
        ll M_i = M / m[i];
        ret += a[i] * M_i * Inv(M_i, m[i]);
    }

    return ret & M;
}

// Gauss-Jordan Elimination(가우스 소거법)
// return inverse matrix
v2d GaussElimination(v2d mat) {
    int size = mat.size();
    v2d ret(size, vd(size));
    for (int i = 0; i < size; i++)
        ret[i][i] = 1;

    for (int i = 0; i < size; i++) {
        double tmp = mat[i][i];
        for (int j = 0; j < size; j++) {
            mat[i][j] /= tmp;
            ret[i][j] /= tmp;
        }

        for (int j = 1; j < size; j++) {
            double a = -mat[(i + j) % size][i] / mat[i][i];

            for (int k = 0; k < size; k++) {
                mat[(i + j) % size][k] += a * mat[i][k];
                ret[(i + j) % size][k] += a * ret[i][k];
            }
        }
    }

    return ret;
}

// Matrix Multiply(행렬 곱)
v2l Mul(v2l& a, v2l& b) {
    int size = a.size();
    v2l ret(size, vl(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                ret[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ret;
}

// Matrix Power(행렬 거듭제곱)
v2l Pow(v2l& a, int x) {
    if (x == 1) return a;
    v2l ret = Pow(a, x / 2);
    ret = Mul(ret, ret);
    if (x & 1) ret = Mul(ret, a);
    return ret;
}

// 금광 세그(Mine Segment tree)
struct Data {
    ll lmax;
    ll rmax;
    ll mmax;
    ll sum;
};

vector<pair<pll, ll>> arr;
vector<Data> tree;

void Update(int idx, ll val, int node, int start, int end) {
    if (idx < start || end < idx) return;
    if (start == end) {
        tree[node].sum += val;
        tree[node].lmax = tree[node].rmax = tree[node].mmax = tree[node].sum;
        return;
    }
    int mid = (start + end) / 2;
    Update(idx, val, node * 2, start, mid);
    Update(idx, val, node * 2 + 1, mid + 1, end);

    tree[node].lmax = max(tree[node * 2].lmax, tree[node * 2].sum + tree[node * 2 + 1].lmax);
    tree[node].rmax = max(tree[node * 2 + 1].rmax, tree[node * 2].rmax + tree[node * 2 + 1].sum);
    tree[node].mmax = max({ tree[node * 2].mmax,tree[node * 2 + 1].mmax, tree[node * 2].rmax + tree[node * 2 + 1].lmax });
    tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
}