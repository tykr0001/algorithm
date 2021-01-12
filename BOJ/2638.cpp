#include <bits/stdc++.h>

using namespace std;

int N, M;
int flag = 0;
int answer = 0;
vector<vector<int>> graph;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool BFS(vector<vector<int>>& graph) {
    answer++;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<vector<int>> cnt(N, vector<int>(M, 0));
    queue<pair<int, int>> search_queue;
    search_queue.emplace(0, 0);
    visited[0][0] = true;
    while (!search_queue.empty()) {
        int src_i, src_j;
        tie(src_i, src_j) = search_queue.front();
        search_queue.pop();
        for (int i = 0; i < 4; i++) {
            int dst_i = src_i + dx[i];
            int dst_j = src_j + dy[i];
            if (0 <= dst_i && dst_i < N && 0 <= dst_j && dst_j < M) {
                if (!visited[dst_i][dst_j] && !graph[dst_i][dst_j]) {
                    visited[dst_i][dst_j] = true;
                    search_queue.emplace(dst_i, dst_j);
                }
                if (graph[dst_i][dst_j]) {
                    cnt[dst_i][dst_j]++;
                    visited[dst_i][dst_j] = true;
                    if (cnt[dst_i][dst_j] == 2) {
                        graph[dst_i][dst_j] = 0;
                    }
                }
            }
        }
    }
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {
            if (graph[i][j]) {
                return true;
            }
        }
    }
    return false;
}

int main(void) {
    cin >> N >> M;
    graph.resize(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {
            if (graph[i][j]) {
                flag |= graph[i][j];
            }
        }
    }
    if (!flag) {
        cout << 0 << '\n';
    }
    else {
        while(BFS(graph)){}
        cout << answer << '\n';
    }

    return 0;
}