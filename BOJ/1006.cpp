#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int T, N, W;
vector<vector<vector<int>>> table;  // DP 테이블
vector<vector<int>> cost;           // [i][j] 항에 배치된 적 수

// index => [0:N-1] 번째 열
// prev => 이전 열의 상태 : 0 => not used, 1 => inner used, 2 => outer used, 3 => both used
// last => 해당 열의 상태 : 0 => not used, 1 => inner used, 2 => outer used, 3 => both used
int DP(int index, int prev, int last) {
    int& ret = table[index][prev][last];
    if (ret) return ret;
    bool inner, outer, both;
    // 해당 index 열의 각 행에서 이전 행의 블록 (index - 1)과 묶을 수 있는지 판별
    inner = (cost[0][index] + cost[0][index ? index - 1 : N - 1]) <= W;
    outer = (cost[1][index] + cost[1][index ? index - 1 : N - 1]) <= W;
    // 안과 밖이 묶일 수 있는지 확인
    both = (cost[0][index] + cost[1][index]) <= W;
    // 종료조건 : index가 끝에 도달했을 때
    if (index == N - 1) {
        if (index == 0) return both ? 1 : 2;
        ret = 2;
        if (last == 0) {
            if (inner && !(prev % 2))
                ret = 1;
            if (outer && prev < 2)
                ret = 1;
            if (both)
                ret = 1;
            if (inner && outer && prev == 0)
                ret = 0;
        }
        else if (last == 1) {
            if (outer && prev < 2) ret = 1;
        }
        else if (last == 2) {
            if (inner && !(prev & 1)) ret = 1;
        }
        return ret;
    }
    // 재귀
    // 블록을 안 묶을 때
    ret = 2 + DP(index + 1, 0, index ? last : 0);
    // 안쪽 블록끼리 묶을 때
    if (inner && !(prev % 2))
        ret = min(ret, 1 + DP(index + 1, 1, index ? last : 1));
    // 바깥 블록끼리 묶을 때
    if (outer && prev < 2)
        ret = min(ret, 1 + DP(index + 1, 2, index ? last : 2));
    // 안쪽과 바깥 블록을 이전 열의 블록과 각각 묶을 때
    if (inner && outer && prev == 0)
        ret = min(ret, DP(index + 1, 3, index ? last : 3));
    // 안쪽과 바깥 블록을 하나로 묶을 때
    if (both)
        ret = min(ret, 1 + DP(index + 1, 3, index ? last : 0));
    return ret;
}

int main(void) {
    cin >> T;
    while (T--) {
        int answer = INT32_MAX;
        cin >> N >> W;

        cost.resize(2, vector<int>(N, 0));
        table.resize(N, vector<vector<int>>(4, vector<int>(4, 0)));

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> cost[i][j];
            }
        }
        cout << DP(0, 0, 0) << endl;

        cost.clear();
        table.clear();
    }
    return 0;
}