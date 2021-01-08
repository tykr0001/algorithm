#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> square;
int N, M;
int answer;

int main(void) {
    cin >> N >> M;
    square.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> square[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int d = 0; i + d < N && j + d < M; d++) {
                if (square[i][j] == square[i][j + d] && square[i][j] == square[i + d][j]
                    && square[i][j] == square[i + d][j + d]) {
                    answer = max(answer, d);
                }
            }
        }
    }


    cout << (answer + 1) * (answer + 1) << endl;

    return 0;
}