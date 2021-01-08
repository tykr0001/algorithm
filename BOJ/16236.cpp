#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
vector<vector<bool>> is_visited;
vector<int> fish(7, 0);
tuple<int, int, int> shark;

int N;
int state = 2; // shark size
int eat_cnt = 0;
int time_cnt = 0;
int target_idx = 1;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

bool CanGo(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < N && !is_visited[i][j] && v[i][j] <= state;
}

bool CanEat(int i, int j) {
    return 0 < v[i][j] && v[i][j] < state;
}

bool CanProceed(void) {
    bool ret = false;
    for (int j = 1; j <= 6 && j < state; j++) {
        ret = ret || fish[j];
    }
    return ret;
}

void Simulate(void) {
    queue<tuple<int, int, int>> q; // i,j,depth
    vector<tuple<int, int, int>> same_distance;
    if (CanProceed()) {
        q.emplace(shark);
        is_visited[get<0>(shark)][get<1>(shark)] = true;
    }
    else {
        return;
    }

    while (!q.empty()) {
        int break_flag = 0;
        int x, y, t;
        tie(x, y, t) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (CanGo(x + dx[i], y + dy[i])) {
                // find next target
                is_visited[x + dx[i]][y + dy[i]] = true;
                q.emplace(x + dx[i], y + dy[i], t + 1);
                // move shark
                if (CanEat(x + dx[i], y + dy[i])) {
                    if (same_distance.empty() || (get<2>(same_distance[0]) == t + 1)) {
                        same_distance.emplace_back(x + dx[i], y + dy[i], t + 1);
                    }
                    else {
                        break_flag = 1;
                        break;
                    }
                }
            }
        }
        if (q.empty() || break_flag) {
            if (same_distance.empty()) {
                return;
            }
            sort(same_distance.begin(), same_distance.end());
            int ni, nj, nt;
            tie(ni, nj, nt) = same_distance.front();
            same_distance.clear();
            fish[v[ni][nj]]--;
            v[ni][nj] = 0;
            time_cnt = nt;
            eat_cnt++;
            if (eat_cnt == state) {
                eat_cnt = 0;
                state++;
            }
            if (CanProceed()) {
                queue<tuple<int, int, int>> empty;
                swap(q, empty);
                q.emplace(ni, nj, nt);
                is_visited.clear();
                is_visited.resize(N, vector<bool>(N, false));
                is_visited[ni][nj] = true;
            }
            else {
                return;
            }
        }
    }
    return;
}

int main(void) {
    cin >> N;
    v.resize(N, vector<int>(N, 0));
    is_visited.resize(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
            if (0 < v[i][j] && v[i][j] < 7) {
                fish[v[i][j]]++;
            }
            if (v[i][j] == 9) {
                v[i][j] = 0;
                shark = { i,j,0 };
            }
        }
    }
    Simulate();

    cout << time_cnt << endl;

    return 0;
}