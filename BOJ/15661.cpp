#include <iostream>
#include <vector>

using namespace std;

int N, gap = INT32_MAX;
vector<vector<int>> S;
vector<bool> selected;

void CalculateGap() {
    vector<int> start;
    vector<int> link;
    int ret = 0;

    for (int i = 0; i < N; i++) {
        if (selected[i]) {
            start.push_back(i);
        }
        else {
            link.push_back(i);
        }
    }

    for (int i = 0; i < start.size(); i++) {
        for (int j = 0; j < start.size(); j++) {
            ret += S[start[i]][start[j]];
        }
    }

    for (int i = 0; i < link.size(); i++) {
        for (int j = 0; j < link.size(); j++) {
            ret -= S[link[i]][link[j]];
        }
    }

    gap = min(gap, abs(ret));
}

void BruteForce(int idx, int size) {
    if (size == N / 2) {
        CalculateGap();
        return;
    }
    for (int i = idx; i < N; i++) {
        if (!selected[i]) {
            selected[i] = true;
            BruteForce(i, size + 1);
            selected[i] = false;
        }
    }
}

int main(void) {
    cin >> N;
    S.resize(N, vector<int>(N));
    selected.resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

    BruteForce(0, 0);

    cout << gap << endl;
}