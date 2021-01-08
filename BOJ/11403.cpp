#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> v;

void FloydWarshall(void) {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (v[i][k] > 0 && v[k][j] > 0) {
                    v[i][j] = 1;
                }
            }
        }
    }
}

int main(void) {
    cin >> N;
    v.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }

    FloydWarshall();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
}