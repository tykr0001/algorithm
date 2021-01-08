#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N, M, B;
    int max_floor = 0;
    int floor = 0;
    int sec = INT32_MAX; // 시간
    cin >> N >> M >> B;
    vector<vector<int>> v(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
            floor += v[i][j];
        }
    }
    max_floor = (floor + B) / (N * M);
    for (int k = 0; k <= max_floor; k++) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (v[i][j] > k) {
                    cnt += (v[i][j] - k) * 2;
                }
                else {
                    cnt += k - v[i][j];
                }
            }
        }
        
        if(sec >= cnt){
            sec = cnt;
            floor = k;
        }
    }

    cout << sec << " " << floor << endl;

}