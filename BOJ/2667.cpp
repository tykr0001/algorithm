#include <bits/stdc++.h>

using namespace std;

int N;
int answer;
vector<string> v;
vector<vector<bool>> is_visited;
vector<int> house_num;
queue<pair<int, int>> q;

int x[4] = { -1,1,0,0 };
int y[4] = { 0,0,-1,1 };

bool BorderCheck(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < N;
}

int main(void) {
    cin >> N;
    v.resize(N);
    is_visited.resize(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (v[i][j] == '1' && !is_visited[i][j]) {
                answer++;
                house_num.push_back(1);
                q.emplace(i, j);
                is_visited[i][j] = true;
                while (!q.empty()) {
                    pair<int, int> front = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int l = front.first + x[k];
                        int m = front.second + y[k];
                        if (BorderCheck(l, m) && v[l][m] == '1' && !is_visited[l][m]) {
                            house_num[answer - 1]++;
                            q.emplace(l, m);
                            is_visited[l][m] = true;
                        }
                    }
                }
            }
        }
    }
    sort(house_num.begin(), house_num.end());
    cout << answer << endl;
    for (int i = 0; i < house_num.size(); i++) {
        cout << house_num[i] << endl;
    }
}