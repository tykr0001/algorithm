#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T;

int main(void) {
    cin >> T;
    while (T--) {
        int N, M, cnt = 0;
        cin >> N >> M;
        queue<pair<int, int>> q; // <priority, idx>
        vector<int> n(11, 0);
        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            q.push({ tmp,i });
            n[tmp]++;
        }

        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            n[top.first]--;
            int i = top.first + 1;
            while (i <= 10) {
                if (n[i]) {
                    q.push(top);
                    n[top.first]++;
                    break;
                }
                i++;
            }
            if (!(i <= 10)) {
                cnt++;
                if (top.second == M) {
                    cout << cnt << endl;
                    break;
                }
            }
        }
    }
}