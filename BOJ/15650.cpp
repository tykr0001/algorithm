#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v;
vector<bool> selected;

void BackTrack(int idx, int depth) {
    if (depth == M) {
        for (int i = 1; i <= N; i++) {
            if (selected[i]) {
                cout << i << " ";
            }
        }
        cout << '\n';
        return;
    }
    for (int i = idx + 1; i <= N; i++) {
        selected[i] = true;
        BackTrack(i, depth + 1);
        selected[i] = false;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    v.resize(N + 1);
    selected.resize(N + 1, false);
    BackTrack(0, 0);
    return 0;
}