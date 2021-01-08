#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<pair<int, int>> x(N);
    vector<int> answer(N);
    for (int i = 0; i < N; ++i) {
        int inp;
        cin >> inp;
        x[i] = { inp, i };
    }
    sort(x.begin(), x.end());

    int cnt = 0;
    int same_num = 0;
    answer[x[0].second] = 0;
    for (int i = 1; i < N; ++i) {
        if (x[i - 1].first < x[i].first) {
            cnt = i - same_num;
        }
        if (x[i - 1].first == x[i].first) {
            same_num++;
        }
        answer[x[i].second] = cnt;
    }
    for (int i = 0; i < N; ++i) {
        cout << answer[i] << " ";
    }

    return 0;
}