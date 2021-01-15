#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v;
vector<int> selected;

void BackTrack(int idx, int depth) {
    if (depth == M) {
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < selected[i]; j++) {
                cout << i << " ";
            }
        }
        cout << '\n';
        return;
    }
    for (int i = idx; i <= N; i++) {
        selected[i]++;
        BackTrack(i, depth + 1);
        selected[i]--;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    v.resize(N + 1);
    selected.resize(N + 1, 0);
    BackTrack(1, 0);
    return 0;
}