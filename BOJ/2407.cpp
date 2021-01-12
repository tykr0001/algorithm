#include <bits/stdc++.h>

using namespace std;

string cache[101][101];

string AddString(const string& n_1, const string& n_2) {
    int tmp = 0;
    string ret = "";
    ret.reserve(n_2.size());
    int idx_1 = n_1.length() - 1;
    int idx_2 = n_2.length() - 1;
    while (idx_1 >= 0 || idx_2 >= 0 || tmp != 0) {
        if (idx_1 >= 0) {
            tmp += n_1[idx_1--] - '0';
        }
        if (idx_2 >= 0) {
            tmp += n_2[idx_2--] - '0';
        }
        ret.push_back((tmp % 10) + '0');
        tmp /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string C(int n, int r) {
    if (r == 0 || n == r) {
        return "1";
    }
    if (cache[n][r] != "") {
        return cache[n][r];
    }
    return cache[n][r] = AddString(C(n - 1, r - 1), C(n - 1, r));
}

int main(void) {
    int n, r;
    cin >> n >> r;
    cout << C(n, r) << endl;
    return 0;
}