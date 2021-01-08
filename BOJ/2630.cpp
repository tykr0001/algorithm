#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> v;
vector<int> color(2, 0); // 0:white, 1:blue
void Conquer(int i, int j, int sz) {
    if (sz == 1) {
        color[v[i][j]]++;
        return;
    }
    int tmp = v[i][j];
    for (int k = i; k < i + sz; k++) {
        for (int l = j; l < j + sz; l++) {
            if (v[i][j] != v[k][l]) {
                for (int m = 0; m < 2; m++) {
                    for (int n = 0; n < 2; n++) {
                        Conquer(i + m * sz / 2, j + n * sz / 2, sz / 2);
                    }
                }
                return;
            }
        }
    }
    color[v[i][j]]++;
    return;
}

int main(void) {
    cin >> N;
    v.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }

    Conquer(0, 0, N);
    cout << color[0] << '\n' << color[1] << endl;

    return 0;
}