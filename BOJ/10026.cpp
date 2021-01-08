#include <bits/stdc++.h>

using namespace std;

vector<string> v;
vector<vector<bool>> is_visited;
queue<pair<int, int>> q;

int N;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int R;
int G;
int B;
int RG;

map<int, int> sector;

bool CanVisit(int i, int j, char color) {
    if (color == 'Y') {
        return 0 <= i && i < N && 0 <= j && j < N && !is_visited[i][j] && (v[i][j] == 'R' || v[i][j] == 'G');
    }
    else {
        return 0 <= i && i < N && 0 <= j && j < N && !is_visited[i][j] && v[i][j] == color;
    }
}

void BFS(int i, int j, char color) {
    if (CanVisit(i, j, color)) {
        sector[color]++;
        is_visited[i][j] = true;
        q.emplace(i, j);
        while (!q.empty()) {
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                if (CanVisit(x + dx[k], y + dy[k], color)) {
                    q.emplace(x + dx[k], y + dy[k]);
                    is_visited[x + dx[k]][y + dy[k]] = true;
                }
            }
        }
    }
}

int main(void) {
    cin >> N;
    v.resize(N);
    is_visited.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sector['R'] = 0;
    sector['G'] = 0;
    sector['B'] = 0;
    sector['Y'] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            BFS(i, j, 'R');
            BFS(i, j, 'G');
            BFS(i, j, 'B');
        }
    }

    is_visited.clear();
    is_visited.resize(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            BFS(i, j, 'Y');
        }
    }

    cout << sector['R'] + sector['G'] + sector['B'] << " ";
    cout << sector['Y'] + sector['B'] << endl;

    return 0;
}