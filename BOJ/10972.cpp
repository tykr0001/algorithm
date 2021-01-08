#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    if (N == 1) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int i = N - 1;
    while (v[i - 1] >= v[i]) {
        i--;
        if (i == 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    int idx = i;
    for (int j = i; j < N; j++) {
        if (v[i - 1] < v[j] && v[j] < v[idx]) {
            idx = j;
        }
    }
    swap(v[i - 1], v[idx]);
    sort(v.begin() + i, v.end());
    for (int i = 0; i < N; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}