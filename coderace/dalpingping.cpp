#include <bits/stdc++.h>
using namespace std;

int n, q;

int depth(int i, int j) {
    return min({i,j,n-1-i,n-1-j});
}

int val(int i, int j) {
    int d = depth(i, j);
    int prev = n * n - (n-2*d)*(n-2*d);
    if (i <= j)
        return i + j - 2 * d + prev;
    else
        return (n - 1 - 2 * d) * 4 - (i + j - 2 * d) + prev;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> q;

    while (q--) {
        int i, j;
        cin >> i >> j;
        cout << val(i, j) << endl;
    }

    return 0;
}