#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int N, K;
void BFS() {
    queue<pair<int, int>> q; // {position, depth}
    vector<bool> searched(100001, false);
    q.emplace(N, 0);
    int cnt = 0;
    int fastest = INF;

    while (!q.empty()) {
        int front, depth;
        tie(front, depth) = q.front();
        q.pop();

        if (front == K) {
            if (!searched[front]) {
                fastest = depth;
            }
            fastest=min(fastest,depth);
        }
        searched[front] = true;
        if (depth < fastest) {
            if (!searched[front]) {
                searched[front] = true;
            }
            if (front - 1 >= 0 && !searched[front - 1]) {
                q.emplace(front - 1, depth + 1);
            }
            if (front + 1 <= 100000 && !searched[front + 1]) {
                q.emplace(front + 1, depth + 1);
            }
            if (front * 2 <= 100000 && !searched[front * 2]) {
                q.emplace(front * 2, depth);
            }
        }
    }

    cout << fastest << '\n';
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    BFS();
    return 0;
}