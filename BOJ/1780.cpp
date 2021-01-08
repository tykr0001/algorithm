#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v;

vector<int> answer(3, 0);

void Conquer(int i, int j, int sz) {
    if (sz == 1) {
        answer[v[i][j] + 1]++;
        return;
    }
    int tmp = v[i][j];
    for (int k = i; k < i + sz; k++) {
        for (int l = j; l < j + sz; l++) {
            if (tmp != v[k][l]) {
                for (int m = 0; m < 3; m++) {
                    for (int n = 0; n < 3; n++) {
                        Conquer(i + m * sz / 3, j + n * sz / 3, sz / 3);
                    }
                }
                return;
            }
        }
    }
    answer[v[i][j] + 1]++;
    return;
}

int main(void) {
    int N;
    cin >> N;
    v.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }
    Conquer(0, 0, N);
    cout << answer[0] << '\n' << answer[1] << '\n' << answer[2] << '\n';
    return 0;
}