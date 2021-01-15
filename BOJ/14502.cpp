#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int N, M;
vector<vector<int>> graph;
vector<vector<bool>> searched;
vector<pair<int, int>> virus;
vector<pair<int, int>> wall;
vector<pair<int, int>> blank;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int answer = 0;
void BFS(vector<vector<int>>& graph, const pair<int, int>& init) {
    queue<pair<int, int>> q;
    q.emplace(init);
    if(searched[init.first][init.second]){
        return;
    }
    searched[init.first][init.second] = true;
    while (!q.empty()) {
        auto src = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dst_i = src.first + dx[i];
            int dst_j = src.second + dy[i];
            if (0 <= dst_i && dst_i < N && 0 <= dst_j && dst_j < M && !searched[dst_i][dst_j]){
                if(graph[dst_i][dst_j] != 1){
                    q.emplace(dst_i, dst_j);
                    searched[dst_i][dst_j] = true;
                    graph[dst_i][dst_j] = 2;
                }
            }
        }
    }
}

void solve(vector<vector<int>> graph) {
    searched.resize(N, vector<bool>(M, false));
    for (int i = 0; i < virus.size(); i++) {
        BFS(graph, virus[i]);
    }
    int cnt=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == 0) {
                cnt++;
            }
        }
    }
    answer = max(answer,cnt);
    searched.clear();
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    graph.resize(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 2) {
                virus.emplace_back(i, j);
            }
            if (graph[i][j] == 1) {
                wall.emplace_back(i, j);
            }
            if (graph[i][j] == 0) {
                blank.emplace_back(i, j);
            }
        }
    }

    for (int i = 0; i < blank.size() - 2; i++) {
        for (int j = i + 1; j < blank.size() - 1; j++) {
            for (int k = j + 1; k < blank.size(); k++) {
                graph[blank[i].first][blank[i].second] = 1;
                graph[blank[j].first][blank[j].second] = 1;
                graph[blank[k].first][blank[k].second] = 1;
                solve(graph);
                graph[blank[i].first][blank[i].second] = 0;
                graph[blank[j].first][blank[j].second] = 0;
                graph[blank[k].first][blank[k].second] = 0;
            }
        }
    }

    cout << answer;
    return 0;
}