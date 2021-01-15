#include <bits/stdc++.h>

using namespace std;

// 0-1 Knapsack(0-1 ¹è³¶¹®Á¦)
// print a maximum value which will be stored in cache[N][K]
// @param N : the number of items
// @param K : maximum weight
// @return  : void
void Knapsack(int N, int K) {
    vector<int> cache(K + 1, 0); // cache[i] is max weight up to index i
    vector<vector<int>> item(N + 1, vector<int>(2, 0)); // {weight, value}
    for (int i = 1; i <= N; i++) {
        cin >> item[i][0] >> item[i][1];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = K; j >= 1; j--) {
            if (item[i][0] <= j) {
                cache[j] = max(cache[j], cache[j - item[i][0]] + item[i][1]);
            }
        }
    }
    cout << cache[K] << '\n';
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;

    Knapsack(N, K);

    return 0;
}