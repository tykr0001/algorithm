#include <bits/stdc++.h>

using namespace std;

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

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V;
    cin >> V;
    vector<vector<pair<int,int>>> tree(V+1);
    for(int i=0; i<V-1; i++){
        int src,dst,weight;
        cin >> src >> dst >> weight;
        tree[src].emplace_back(dst, weight);
        tree[dst].emplace_back(src, weight);
    }
    int next_init = BFS(tree, V, 1).first;
    cout << BFS(tree, V, next_init).second;
    return 0;
}