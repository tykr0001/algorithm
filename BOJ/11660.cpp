#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> table(N, vector<int>(N, 0));
    vector<vector<int>> sum(N, vector<int>(N, 0));
    vector<tuple<int, int, int, int>> partition(M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> table[i][j];
        }
    }
    
    sum[0][0] = table[0][0];
    for (int i = 1; i < N; i++) {
        sum[i][0] = sum[i-1][0] + table[i][0];
        sum[0][i] = sum[0][i-1] + table[0][i];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            sum[i][j] = sum[i-1][j];
            for(int k=0; k<=j; k++){
                sum[i][j] += table[i][k];
            }
        }
    }
    

    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        partition[i] = { x1 - 1, y1 - 1, x2 - 1, y2 - 1 };
    }

    for (int i = 0; i < partition.size(); i++) {
        int x1, y1, x2, y2;
        tie(x1, y1, x2, y2) = partition[i];
        if (x1 > 0 && y1 > 0) {
            cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << '\n';
        }
        else if (x1 > 0) {
            cout << sum[x2][y2] - sum[x1 - 1][y2] << '\n';
        }
        else if (y1 > 0) {
            cout << sum[x2][y2] - sum[x2][y1 - 1] << '\n';
        }
        else {
            cout << sum[x2][y2] << '\n';
        }
    }

    return 0;
}