#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <cmath>
#include <functional>

using namespace std;

vector<list<int>> tech; // dp[i] : i번 건물 건설 후에 지을 수 있는 건물 리스트
vector<int> build_need; // dp[i] : i번 건물을 짓기 위해 먼저 지어야하는 건물 갯수
vector<int> dp; // dp[i] : i번 건물까지 짓기 위한 시간
vector<int> D; // D[i] : i번 건물 건설에 걸리는 시간
queue<int> build_queue;

int main(void) {
    int T;
    cin >> T;
    while (T--) {
        int N, K, goal;
        cin >> N >> K;

        tech.resize(N + 1, list<int>());
        build_need.resize(N + 1, 0);
        dp.resize(N + 1, 0);
        D.resize(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            cin >> D[i];
        }

        while (K--) {
            int b1, b2;
            cin >> b1 >> b2;
            tech[b1].push_back(b2);
            build_need[b2] += 1;
        }

        for (int i = 1; i <= N; ++i) {
            if(build_need[i]==0){
                build_queue.push(i);
                dp[i] = D[i];
            }
        }

        while (!build_queue.empty()) {
            int prev = build_queue.front();
            build_queue.pop();
            while(!tech[prev].empty()){
                int next = tech[prev].back();
                tech[prev].pop_back();
                if(--build_need[next]==0){
                    build_queue.push(next);
                }
                dp[next] = max(dp[next], dp[prev] + D[next]);
            }
            
        }

        cin >> goal;
        cout << dp[goal] << endl;

        tech.clear();
        build_need.clear();
        dp.clear();
        D.clear();
    }
}