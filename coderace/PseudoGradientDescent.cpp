#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> arr;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    arr.resize(n);
    for(int i=0; i<n; i++) {
        arr[i].resize(m);
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    
    return 0;
}