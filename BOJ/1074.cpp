#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int answer;

void Quad(int N, int r, int c) {
    int ex = pow(2, N - 1);
    if (N == 0) {
        return;
    }
    if (r < ex && c < ex) {
        Quad(N - 1, r, c);
    }
    else if (r < ex && c >= ex) {
        Quad(N - 1, r, c - ex);
        answer += ex * ex;
    }
    else if (r >= ex && c < ex) {
        Quad(N - 1, r - ex, c);
        answer += 2 * ex * ex;
    }
    else {
        Quad(N - 1, r - ex, c - ex);
        answer += 3 * ex * ex;
    }
}

int main(void) {
    int N, r, c;
    cin >> N >> r >> c;

    Quad(N, r, c);

    cout << answer << endl;
}