#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    vector<int> grade(N, 1);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                if (v[i].first < v[j].first && v[i].second < v[j].second) {
                    grade[i]++;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << grade[i] << " ";
    }

    return 0;
}