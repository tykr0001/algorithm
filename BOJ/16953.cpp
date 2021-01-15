#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main(void) {
    LL A, B;
    cin >> A >> B;
    queue<pair<LL, LL>> q;
    q.emplace(A, 1);
    while (!q.empty()) {
        LL front, depth;
        tie(front, depth) = q.front();
        q.pop();
        if (front <= B) {
            if (front * 2 == B) {
                cout << depth + 1 << endl;
                return 0;
            }
            else {
                q.emplace(front * 2, depth + 1);
            }
            if (front * 10 + 1 == B) {
                cout << depth + 1 << endl;
                return 0;
            }
            else {
                q.emplace(front * 10 + 1, depth + 1);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}