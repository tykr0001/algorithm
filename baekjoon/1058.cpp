#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int N;
int answer;
vector<string> relation;
vector<bool> is_visited;

// return : d-friend number of idx
int dfs(int idx, int depth) {
    if (depth == 0) {
        return 0;
    }
    int ret = 0;
    is_visited[idx] = true;
    for (int i = 0; i < N; i++) {
        if (relation[idx][i] == 'Y') {
            if (is_visited[i] == false) {
                ret++;
                is_visited[i] = true;
            }
            ret += dfs(i, depth - 1);
        }
    }

    return ret;
}

int main(void) {
    cin >> N;

    relation.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> relation[i];
    }

    for (int i = 0; i < N; i++) {
        is_visited.resize(N, false);
        int friend_num = dfs(i, 2);
        is_visited.clear();
        answer = max(answer, friend_num);
    }

    cout << answer << endl;

    return 0;
}