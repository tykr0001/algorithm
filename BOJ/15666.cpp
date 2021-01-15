#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v;
vector<int> selected;

void BackTrack(int idx, int depth) {
    if (depth == M) {
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < selected[i]; j++) {
                cout << v[i] << " ";
            }
        }
        cout << '\n';
        return;
    }
    for (int i = idx; i < v.size(); i++) {
        selected[i]++;
        BackTrack(i, depth + 1);
        selected[i]--;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    v.resize(N);
    selected.resize(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    BackTrack(0, 0);
    return 0;
}