#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> graph;
vector<bool> is_visited;
queue<int> search_queue;
stack<int> search_stack;
int N, M;
int answer = 0;

void BFS(int init) {
    if (!is_visited[init]) {
        answer++;
        is_visited[init] = true;
        search_queue.push(init);
        while (!search_queue.empty()) {
            int front = search_queue.front();
            search_queue.pop();
            for (int i = 0; i <= N; i++) {
                if (graph[front][i] && !is_visited[i]) {
                    is_visited[i] = true;
                    search_queue.push(i);
                }
            }
        }
    }
}

void DFS(int init) {
    if (!is_visited[init]) {
        answer++;
        is_visited[init] = true;
        search_stack.push(init);
        while (!search_stack.empty()) {
            int top = search_stack.top();
            search_stack.pop();
            for (int i = 0; i <= N; i++) {
                if (graph[top][i] && !is_visited[i]) {
                    is_visited[i] = true;
                    search_stack.push(top);
                    search_stack.push(i);
                }
            }
        }
    }
}



int main(void) {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> N >> M;
    graph.resize(N + 1, vector<bool>(N + 1, false));
    is_visited.resize(N, false);
    for (int i = 0; i < M; i++) {
        int src, dst;
        cin >> src >> dst;
        graph[src][dst] = true;
        graph[dst][src] = true;
    }
    for (int i = 1; i <= N; i++) {
        //BFS(i);
        DFS(i);
    }

    cout << answer;

    return 0;
}