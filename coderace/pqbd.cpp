#include <bits/stdc++.h>
using namespace std;

string inp, str;
unordered_map<char, char> mirror;
unordered_map<char, char> point;

string Mirror() {
    string ret = "";
    vector<int> dp(str.size());
    int l = 0, r = -1;
    for (int i = 0; i < str.size(); i++) {
        int size = (i > r) ? 1 : min(r - i + 1, dp[l + r - i]);
        while (i - size >= 0 && i + size < str.size() && str[i - size] == mirror[str[i + size]]) {
            size++;
        }
        dp[i] = size--;
        if (i + size > r) {
            l = i - size;
            r = i + size;
        }
    }
    int c = 0;
    int prev_max = 0;
    for (int i = 0; i < str.size(); i++) {
        if (prev_max < dp[i]) {
            c = i;
            prev_max = dp[i];
        }
    }
    ret = str.substr(c - prev_max + 1, prev_max * 2 - 1);
    return ret;
}

string Point() {
    string ret = "";
    vector<int> dp(str.size());
    int l = 0, r = -1;
    for (int i = 0; i < str.size(); i++) {
        int size = (i > r) ? 1 : min(r - i + 1, dp[l + r - i]);
        while (i - size >= 0 && i + size < str.size() && str[i - size] == point[str[i + size]]) {
            size++;
        }
        dp[i] = size--;
        if (i + size > r) {
            l = i - size;
            r = i + size;
        }
    }
    int c = 0;
    int prev_max = 0;
    for (int i = 0; i < str.size(); i++) {
        if (prev_max < dp[i]) {
            c = i;
            prev_max = dp[i];
        }
    }
    ret = str.substr(c - prev_max + 1, prev_max * 2 - 1);
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> inp;
    for (auto c : inp) {
        str += c;
        str += '#';
    }
    cout << str << '\n';

    mirror['b'] = 'd';
    mirror['d'] = 'b';
    mirror['p'] = 'q';
    mirror['q'] = 'p';
    mirror['i'] = 'i';
    mirror['l'] = 'l';
    mirror['m'] = 'm';
    mirror['n'] = 'n';
    mirror['o'] = 'o';
    mirror['v'] = 'v';
    mirror['w'] = 'w';
    mirror['x'] = 'x';
    mirror['#'] = '#';

    point['b'] = 'q';
    point['q'] = 'b';
    point['p'] = 'd';
    point['d'] = 'p';
    point['l'] = 'l';
    point['o'] = 'o';
    point['s'] = 's';
    point['x'] = 'x';
    point['z'] = 'z';
    point['#'] = '#';

    string ret1 = Mirror();
    string ret2 = Point();
    cout << "ret1 :" << ret1 << '\n';
    cout << "ret2 :" << ret2 << '\n';
    if (ret1.size() > ret2.size()) {
        for (auto c : ret1) {
            if (c != '#') cout << c;
        }
    }
    else {
        for (auto c : ret2) {
            if (c != '#') cout << c;
        }
    }

    return 0;
}