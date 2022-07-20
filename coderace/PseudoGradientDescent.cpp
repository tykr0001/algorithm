#include <bits/stdc++.h>
using namespace std;

int n, m;
int x, y;
vector<vector<int>> arr;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool OutOfBound(int i, int j) {
    return !(0 <= i && i < n && 0 <= j && j < m);
}

int main(void) {
    // Init
    // ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        arr[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // Solve
    cin >> x >> y;
    int prev_x = x;
    int prev_y = y;
    int prev_dir = -1;
    int cnt = 0; // for early stop
    int min_val = INT_MAX;
    while (true) {
        int gap = -1;
        int next_x;
        int next_y;
        int next_dir = 0;

        if(min_val > arr[prev_y][prev_x]) {
            min_val = arr[prev_y][prev_x];
            cnt = 0;
        }
        else {
            cnt++;
        }
        if(cnt==10) return 0;
        cout << arr[prev_y][prev_x] << '\n';

        for (int i = 0; i < 4; i++) {

            int tmp_x = prev_x + dx[i];
            int tmp_y = prev_y + dy[i];
            if (!OutOfBound(tmp_y, tmp_x) && arr[prev_y][prev_x] > arr[tmp_y][tmp_x]) {
                if (gap < arr[prev_y][prev_x] - arr[tmp_y][tmp_x]) {
                    gap = arr[prev_y][prev_x] - arr[tmp_y][tmp_x];
                    next_x = tmp_x;
                    next_y = tmp_y;
                    next_dir = i;
                }
            }
        }

        // local optimum
        if (gap == -1) {
            // momentum
            if (!OutOfBound(prev_y + dy[prev_dir], prev_x + dx[prev_dir])) {
                // init position
                if (prev_dir == -1) {
                    return 0;
                }
                next_x = prev_x + dx[prev_dir];
                next_y = prev_y + dy[prev_dir];
            }
            // out of bound
            else {
                return 0;
            }
        }
        
        prev_x = next_x;
        prev_y = next_y;
        prev_dir = next_dir;
    }

    return 0;
}