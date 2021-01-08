#include <bits/stdc++.h>

using namespace std;

int N, K;
queue<int> q;
vector<int> breadth;
vector<bool> is_visited;
int answer = 0;

int main(void) {
    cin >> N >> K;
    if (N == K) {
        cout << 0 << endl;
        return 0;
    }
    q.emplace(N);
    is_visited.resize(100001,false);
    is_visited[N] = true;
    breadth.push_back(1); // 0-depth, 1-breadth
    int depth = 0;
    while (!q.empty()) {
        breadth.push_back(0);
        for (int i = 0; i < breadth[depth]; i++) {
            int front = q.front();
            q.pop();
            if (front - 1 >= 0 && !is_visited[front - 1]) {
                q.emplace(front - 1);
                is_visited[front - 1] = true;
                breadth[depth + 1]++;
                if (front - 1 == K) {
                    answer = depth + 1;
                    break;
                }
            }
            if (front + 1 <= 100000 && !is_visited[front + 1]) {
                q.emplace(front + 1);
                is_visited[front + 1] = true;
                breadth[depth + 1]++;
                if (front + 1 == K) {
                    answer = depth + 1;
                    break;
                }
            }
            if (front * 2 <= 100000 && !is_visited[front * 2]) {
                q.emplace(front * 2);
                is_visited[front * 2] = true;
                breadth[depth + 1]++;
                if (front * 2 == K) {
                    answer = depth + 1;
                    break;
                }
            }
        }
        if (answer != 0) {
            break;
        }
        depth++;
    }
    cout << answer << endl;
}