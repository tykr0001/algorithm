#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> min_dp_prev(3, 0);
    vector<int> min_dp_next(3, 0);
    vector<int> max_dp_prev(3, 0);
    vector<int> max_dp_next(3, 0);
    vector<int> v(3, INF);

    for (int i = 0; i < N; i++) {
        cin >> v[0] >> v[1] >> v[2];
        min_dp_next[0] = min(min_dp_prev[0], min_dp_prev[1]) + v[0];
        min_dp_next[1] = min(min(min_dp_prev[0], min_dp_prev[1]), min_dp_prev[2]) + v[1];
        min_dp_next[2] = min(min_dp_prev[1], min_dp_prev[2]) + v[2];

        max_dp_next[0] = max(max_dp_prev[0], max_dp_prev[1]) + v[0];
        max_dp_next[1] = max(max(max_dp_prev[0], max_dp_prev[1]), max_dp_prev[2]) + v[1];
        max_dp_next[2] = max(max_dp_prev[1], max_dp_prev[2]) + v[2];

        min_dp_prev = min_dp_next;
        max_dp_prev = max_dp_next;
    }

    cout << max(max(max_dp_next[0], max_dp_next[1]), max_dp_next[2]) <<
        " " << min(min(min_dp_next[0], min_dp_next[1]), min_dp_next[2]);

    return 0;
}