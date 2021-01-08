#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL N, M;


int main(void) {
    cin >> N >> M;
    vector<LL> tree(N);
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
    }

    LL low = 0;
    LL high = 1000000000;
    LL mid;
    LL answer = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        LL tmp = 0;
        for (int i = 0; i < N; i++) {
            if (tree[i] > mid) {
                tmp += tree[i] - mid;
            }
        }
        if (tmp >= M) {
            answer = max(answer, mid);
        }
        if (tmp > M) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }

    }
    cout << answer << endl;
}