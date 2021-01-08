#include <bits/stdc++.h>

using namespace std;

int V;
int answer;
vector<vector<pair<int,int>>> tree;
vector<bool> is_visited;
stack<pair<int, int>> s; // idx, length
int root_node;

void DFS(int i) {
    is_visited.clear();
    is_visited.resize(V + 1, false);
    s.emplace(i, 0);
    is_visited[i] = true;
    while (!s.empty()) {
        int idx, len;
        tie(idx, len) = s.top();
        s.pop();
        if(answer < len){
            answer = len;
            root_node = idx;
        }
        answer = max(answer, len);
        for (vector<pair<int,int>>::iterator iter = tree[idx].begin(); iter != tree[idx].end(); iter++) {
            if (is_visited[iter->first] == false) {
                s.emplace(iter->first, len + iter->second);
                is_visited[iter->first] = true;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V;
    tree.resize(V + 1);
    for (int i = 0; i < V; i++) {
        int src;
        cin >> src;
        while (1) {
            int dst, d;
            cin >> dst;
            if (dst == -1) {
                break;
            }
            cin >> d;
            tree[src].emplace_back(dst,d);
        }
    }
    DFS(1);
    DFS(root_node);
    cout << answer << '\n';
    return 0;
}