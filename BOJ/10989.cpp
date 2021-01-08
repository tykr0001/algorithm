#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<short> a(10001, 0);
    for (int i = 0; i < N; i++) {
        int inp;
        cin >> inp;
        a[inp]++;
    }

    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < a[i]; j++) {
            cout << i << " ";
        }
    }
    return 0;
}