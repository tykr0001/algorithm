#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, n;
int lower, upper;
vector<int> S;

// int dp[1000][1000];

// int c(int n, int r) {
//     if (n == r) {
//         return 1;
//     }
//     if (r == 1) {
//         return n;
//     }
//     if (r == 0) {
//         return 1;
//     }
//     if (dp[n][r])
//         return dp[n][r];
//     return dp[n][r] = c(n - 1, r - 1) + c(n - 1, r);
// }

int main(void) {
    cin >> L;
    S.resize(L);
    for (int i = 0; i < L; i++) {
        cin >> S[i];
    }
    cin >> n;
    if (S.end() != find(S.begin(), S.end(), n)) {
        cout << 0 << endl;
        return 0;
    }
    sort(S.begin(), S.end());

    for (int i = 0; i < L; i++) {
        if (S[i] > n) {
            lower = S[i - 1] + 1;
            upper = S[i] - 1;
            break;
        }
    }

    if (lower >= upper) {
        cout << 0 << endl;
        return 0;
    }

    cout << (n - lower) * (upper - n) + (upper - lower) << endl;
    
    return 0;
}