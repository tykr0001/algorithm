#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

int main(void) {
    int N;
    ll sum = 0;
    cin >> N;
    vector<int> v(N);
    vector<int> n_1(10000, 0);
    vector<int> n_2;

    for (int i = 0; i < N; i++) {
        cin >> v[i];
        sum += v[i];
        n_1[v[i] + 4000]++;
    }

    // 산술평균
    cout << round(double(sum) / double(N)) << endl;

    // 중앙값    
    sort(v.begin(), v.end());
    if (N % 2) {
        cout << v[N / 2] << endl;
    }
    else {
        cout << (v[N / 2] + v[N / 2 - 1]) / 2 << endl;
    }

    // 최빈값
    n_2 = n_1;
    sort(n_1.begin(), n_1.end(), greater<int>());
    int state = 0;
    if (N > 1 && n_1[0] == n_1[1]) {
        for (int i = 0; i < 8001; i++) {
            if (n_2[i] == n_1[0]) {
                if (state == 0) {
                    state = 1;
                }
                else {
                    cout << i - 4000 << endl;
                    break;
                }
            }
        }
    }
    else {
        for (int i = 0; i < 8001; i++){
            if (n_2[i] == n_1[0]) {
                cout << i - 4000 << endl;
                break;
            }
        }
    }

    // 범위
    int max_n, min_n;
    for (int i = 0; i < 8001; i++) {
        if (n_2[i]) {
            min_n = i;
            break;
        }
    }
    for (int i = 8000; i >= 0; i--) {
        if (n_2[i]) {
            max_n = i;
            break;
        }
    }

    cout << max_n - min_n << endl;
    return 0;
}