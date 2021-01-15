#include <bits/stdc++.h>

using namespace std;

vector<int> parent;

void BFS(const vector<list<int>>& graph, int V, int init){
    vector<bool> visited(V+1, false);
    queue<int> search_queue;
    search_queue.emplace(init);
    visited[init] = true;
    while(!search_queue.empty()){
        int src = search_queue.front();
        search_queue.pop();
        for(auto child : graph[src]){
            if(!visited[child]){
                parent[child] = src;
                visited[child] = true;
                search_queue.emplace(child);
            }
        }
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<list<int>> graph(N+1);
    parent.resize(N+1);
    for(int i=0; i<N-1; i++){
        int src,dst;
        cin >> src >> dst;
        graph[src].emplace_back(dst);
        graph[dst].emplace_back(src);
    }

    BFS(graph,N,1);

    for(int i=2; i<parent.size();i++){
        cout << parent[i] << '\n';
    }

    return 0;
}