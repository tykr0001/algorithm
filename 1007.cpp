#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int T, N;
double answer;
typedef struct dot {
    int x;
    int y;
} dot;

vector<dot> dots;
vector<int> selected;

void BruteForce(int cnt, int idx) {
    if (cnt == 0) {
        double x = 0, y = 0;
        for (int i = 0; i < N; i++) {
            if (selected[i]) {
                x += dots[i].x;
                y += dots[i].y;
            }
            else {
                x -= dots[i].x;
                y -= dots[i].y;
            }
        }
        answer = min(answer, sqrt(pow(x, 2) + pow(y, 2)));
        return;
    }
    if (idx == N)
        return;
    BruteForce(cnt, idx + 1);
    selected[idx] = true;
    BruteForce(cnt - 1, idx + 1);
    selected[idx] = false;
}

int main(void) {
    cin >> T;
    while (T--) {
        cin >> N;
        dots.resize(N);
        selected.resize(N, false);
        for (int i = 0; i < N; ++i) {
            cin >> dots[i].x >> dots[i].y;
        }
        answer = numeric_limits<double>::max();
        BruteForce(N / 2, 0);
        printf("%.6lf\n", answer);
    }
    return 0;
}