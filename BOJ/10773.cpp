#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int K;
    cin >> K;
    stack<int> s;
    for (int i = 0; i < K; i++) {
        int tmp;
        cin >> tmp;
        if (tmp != 0) {
            s.push(tmp);
        }
        else {
            s.pop();
        }
    }

    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }

    cout << sum << endl;

    return 0;
}