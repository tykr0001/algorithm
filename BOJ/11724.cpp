#include <bits/stdc++.h>

using namespace std;

vector<list<int>> v;
vector<bool> is_visited;
queue<int> search_queue;
int answer = 0;

void BFS(int i) {
    if (!is_visited[i]) {
        answer++;
        is_visited[i] = true;
        search_queue.push(i);
        while (!search_queue.empty()) {
            int front = search_queue.front();
            search_queue.pop();
            for (list<int>::iterator iter = v[front].begin(); iter != v[front].end(); iter++) {
                if (!is_visited[*iter]) {
                    is_visited[*iter] = true;
                    search_queue.push(*iter);
                }
            }
        }
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;
    v.resize(N + 1);
    is_visited.resize(N, false);
    for (int i = 0; i < M; i++) {
        int src, dst;
        cin >> src >> dst;
        v[src].push_back(dst);
        v[dst].push_back(src);
    }
    for (int i = 1; i <= N; i++) {
        BFS(i);
    }

    cout << answer << endl;
    
    return 0;
}