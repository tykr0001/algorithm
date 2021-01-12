#include <bits/stdc++.h>

using namespace std;

vector<int> pi;

vector<int> GetPi(const string& p);
vector<int> KMP(const string& s, const string& p);

int main(void) {
    string s, p;
    getline(cin, s);
    getline(cin, p);
    vector<int> matched_idx = KMP(s, p);
    cout << matched_idx.size() << endl;
    for (int i = 0; i < matched_idx.size(); i++) {
        cout << matched_idx[i] + 1 << " ";
    }
    return 0;
}

vector<int> GetPi(const string& p) {
    vector<int> pi(p.size(), 0);
    int j = 0;
    for (int i = 1; i < p.size(); i++) {
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            pi[i] = ++j;
        }
    }
    return pi;
}

vector<int> KMP(const string& s, const string& p) {
    vector<int> ret;
    vector<int> pi = GetPi(p);
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        while (j > 0 && s[i] != p[j]) {
            j = pi[j - 1];
        }
        if (s[i] == p[j]) {
            if (j == p.size() - 1) {
                ret.push_back(i - j);
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }
    return ret;
}