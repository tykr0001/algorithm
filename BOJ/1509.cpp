#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

vector<vector<int>> cache_pld;
vector<int> cache_partition;
string S;

//  if s[b:e] is palindrome return true;
bool IsPalindrome(int b, int e) {
    if (cache_pld[b][e] != -1) {
        return cache_pld[b][e];
    }
    if (b >= e) {
        return true;
    }
    if (S[b] != S[e]) {
        return false;
    }
    return cache_pld[b][e] = IsPalindrome(b + 1, e - 1);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> S;
    S = "#" + S;
    cache_pld.resize(S.size(), vector<int>(S.size(), -1));
    cache_partition.resize(S.size(), INF);
    cache_partition[0] = 0;
    
    for (int i = 1; i < S.size(); i++) {
        for (int j = 1; j <= i; j++) {
            if (IsPalindrome(j, i)) {
                cache_partition[i] = min(cache_partition[i], cache_partition[j - 1] + 1);
            }
        }
    }

    cout << cache_partition[S.size() - 1] << endl;
    return 0;
}