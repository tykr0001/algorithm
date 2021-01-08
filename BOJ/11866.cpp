#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N, K;
    queue<int> q;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    int cnt = 1;
    cout << "<";
    while (q.size() != 1) {
        int front = q.front();
        q.pop();
        if (cnt % K == 0) {
            cout << front << ", ";
        }
        else {
            q.push(front);
        }
        cnt++;
    }
    cout << q.front() << ">" << endl;
    return 0;
}