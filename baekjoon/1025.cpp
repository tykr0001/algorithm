#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
int answer = -1;
vector<string> str;

bool IsSquareNumber(unsigned int num) {
    unsigned int tmp;
    switch (num & 0x0f) {
    case 0:
    case 1:
    case 4:
    case 9:
        tmp = (unsigned int)(sqrt(double(num) + 0.5));
        return tmp * tmp == num;
    default:
        return false;
    }
}

int main(void) {
    cin >> N >> M;
    str.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> str[i];
    }

    for (int a1 = 0; a1 < N; a1++) {
        for (int a2 = 0; a2 < M; a2++) {
            for (int d1 = -N; d1 < N; d1++) {
                for (int d2 = -M; d2 < M; d2++) {
                    if (d1 == 0 && d2 == 0) {
                        continue;
                    }
                    string tmp = "";
                    for (int i = 0; 0 <= a1 + d1 * i && a1 + d1 * i < N && 0 <= a2 + d2 * i && a2 + d2 * i < M; i++) {
                        tmp += str[a1 + d1 * i][a2 + d2 * i];
                        int num = stoi(tmp);
                        if (IsSquareNumber(num)) {
                            answer = max(answer, num);
                        }
                    }
                }
            }
        }
    }
    cout << answer << endl;
}