#include <bits/stdc++.h>

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int BFS(const vector<string>& graph, int init_i, int init_j, int goal_i, int goal_j) {
    int ret = -1;
    vector<vector<int>> visited(goal_i + 1, vector<int>(goal_j + 1, 0));

    // {i,j,depth,broken}
    // if wall has been broken during search -> broken = 1, else -> broken = 0
    queue<tuple<int, int, int, int>> search_queue;
    search_queue.emplace(init_i, init_j, 1, 0);
    visited[init_i][init_j] = 2;
    while (!search_queue.empty()) {
        int src_i, src_j, depth, broken;
        tie(src_i, src_j, depth, broken) = search_queue.front();
        search_queue.pop();
        if (goal_i == src_i && goal_j == src_j) {
            ret = depth;
            break;
        }
        if (visited[src_i][src_j] == 2 && broken == 1) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int dst_i = src_i + dx[i];
            int dst_j = src_j + dy[i];
            if (init_i <= dst_i && dst_i <= goal_i && init_j <= dst_j && dst_j <= goal_j) {
                if (graph[dst_i][dst_j] == '0') {
                    if (visited[dst_i][dst_j] == 0) {
                        if (broken == 1) {
                            visited[dst_i][dst_j] = 1;
                        }
                        else {
                            visited[dst_i][dst_j] = 2;
                        }
                        search_queue.emplace(dst_i, dst_j, depth + 1, broken);
                    }
                    else if (visited[dst_i][dst_j] == 1) {
                        if (broken == 0) {
                            visited[dst_i][dst_j] = 2;
                            search_queue.emplace(dst_i, dst_j, depth + 1, broken);
                        }
                    }
                }
                else {
                    if (visited[dst_i][dst_j] == 0) {
                        if (broken == 0) {
                            visited[dst_i][dst_j] = 1;
                            search_queue.emplace(dst_i, dst_j, depth + 1, 1);
                        }
                    }
                }
            }
        }
    }
    return ret;
}

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<string> graph(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> graph[i];
    }

    cout << BFS(graph, 0, 0, N - 1, M - 1);
}