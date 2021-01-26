#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> cache;

void DFS(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << cache[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++) {
        cache.push_back(i);
        DFS(depth + 1);
        cache.pop_back();
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    DFS(0);
    return 0;
}