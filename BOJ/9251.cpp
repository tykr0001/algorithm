#include <bits/stdc++.h>

using namespace std;

int cache[1001][1001];

void LongestCommonSubsequence(const string& a, const string& b) {
    for (int i = 0; i < a.length(); i++) {
        for (int j = 0; j < b.length(); j++) {
            if (a[i] == b[j]) {
                cache[i + 1][j + 1] = cache[i][j] + 1;
            }
            else {
                cache[i + 1][j + 1] = max(cache[i + 1][j], cache[i][j + 1]);
            }
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    string b;
    cin >> a >> b;
    LongestCommonSubsequence(a, b);
    cout << cache[a.length()][b.length()] << endl;
    return 0;
}