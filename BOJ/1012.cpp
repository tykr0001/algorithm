#include <iostream>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;

int T, M, N, K, answer;
vector<vector<bool>> map;
vector<vector<bool>> visited;
stack<tuple<int, int>> search;

bool CanGo(int i, int j) {
    return 0 <= i && i < M && 0 <= j && j < N && map[i][j] && !visited[i][j];
}

void DFS(void) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (map[i][j] && !visited[i][j]) {
                answer++;
                search.emplace(i, j);
                visited[i][j] = true;
                while (!search.empty()) {
                    int top_i, top_j;
                    tie(top_i, top_j) = search.top();
                    
                    search.pop();
                    if (CanGo(top_i - 1, top_j)) {
                        visited[top_i - 1][top_j] = true;
                        search.emplace(top_i - 1, top_j);
                    }
                    if (CanGo(top_i, top_j - 1)) {
                        visited[top_i][top_j - 1] = true;
                        search.emplace(top_i, top_j - 1);
                    }
                    if (CanGo(top_i + 1, top_j)) {
                        visited[top_i + 1][top_j] = true;
                        search.emplace(top_i + 1, top_j);
                    }
                    if (CanGo(top_i, top_j + 1)) {
                        visited[top_i][top_j + 1] = true;
                        search.emplace(top_i, top_j + 1);
                    }
                }
            }
        }
    }
}

int main(void) {
    cin >> T;
    while (T--) {
        cin >> M >> N >> K;
        map.resize(M, vector<bool>(N, false));
        visited.resize(M, vector<bool>(N, false));
        while (K--) {
            int x, y;
            cin >> x >> y;
            map[x][y] = true;
        }
        answer = 0;
        DFS();
        cout << answer << endl;
        
        map.clear();
        visited.clear();
    }
}