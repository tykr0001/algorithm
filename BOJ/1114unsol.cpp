#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int l, k, c;
vector<int> cut;

void BinarySearch(int )

void Solve(void) {
    int lo = 0;
    int hi = k-1;
    while(lo<=hi){
        int longest = cut[hi] - cut[lo];
        if(cut.begin() + lo !=
            lower_bound(cut.begin(), cut.begin()+lo, cut[lo]-longest)){

            }

    }
}

void Init(void) {
    cin >> l >> k >> c;
    cut.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> cut[i];
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Init();
    Solve();
    return 0;
}