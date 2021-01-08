#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N;
int cnt;
vector<int> v;
map<pair<int, int>, bool> m;

int main(void) {
    while (!cin.eof()) {
        cin >> N;
        v.push_back(N);
    }
    v.pop_back();
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] + v[j] == N && !m.count({v[i],v[j]})) {
                cout << v[i] << " " << v[j] << endl;
                m[{v[i], v[j]}] = true;
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}