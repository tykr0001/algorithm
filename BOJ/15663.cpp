#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;
vector<bool> selected;
void BackTrack(vector<int> sequence) {
    if (sequence.size() == M) {
        for (auto i : sequence) {
            cout << i << " ";
        }
        cout << '\n';
        return;
    }
    int prev = 0;
    for (int i = 0; i < N; i++) {
        if (!selected[i] && prev != v[i]) {
            prev = v[i];
            selected[i] = true;
            sequence.push_back(v[i]);
            BackTrack(sequence);
            sequence.pop_back();
            selected[i] = false;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    v.resize(N);
    selected.resize(N, false);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    BackTrack(vector<int>());
    return 0;
}