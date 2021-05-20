#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

vector<vector<int>> w;
vector<vector<int>> cache;

int N;

int TSP(int src, int path) {
    if (cache[src][path])
        return cache[src][path];
    if (path == (1 << N) - 1)
        return w[src][0] ? w[src][0] : INF;
    int ret = 1e9;
    for (int i = 0; i < N; i++) {
        if (w[src][i] != 0 && !(path & 1 << i))
            ret = min(ret, TSP(i, path | 1 << i) + w[src][i]);
    }
    return cache[src][path] = ret;
}

void Solve() {
    cout << TSP(0, 1);
}

void Init() {
    cin >> N;
    w.resize(N, vector<int>(N));
    cache.resize(N, vector<int>(1 << N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> w[i][j];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Init();
    Solve();
    return 0;
}