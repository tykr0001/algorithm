#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

typedef long long int LLI;

LLI N;

// 0:A 1:B 2:C 3:D 4:E 5:F
LLI dice[6];

LLI center = INT32_MAX;
LLI edge = INT32_MAX;
LLI corner = INT32_MAX;
LLI center_num;
LLI edge_num;
LLI corner_num;
LLI biggest = 0;
LLI sum = 0;

int main(void) {
    cin >> N;

    for (LLI i = 0; i < 6; ++i) {
        cin >> dice[i];
        biggest = max(biggest, dice[i]);
        sum += dice[i];
    }

    if (N == 1) {
        cout << sum - biggest << endl;
        return 0;
    }

    for (LLI i = 0; i < 6; i++) {
        center = min(center, dice[i]);
        for (LLI j = 0; j < 6; j++) {
            if (i != j && i + j != 5) {
                edge = min(edge, dice[i] + dice[j]);
            }
            for (LLI k = 0; k < 6; k++) {
                if (i != j && i != k && j != k && i + j != 5 && i + k != 5 && j + k != 5) {
                    corner = min(corner, dice[i] + dice[j] + dice[k]);
                }
            }
        }
    }
    center_num = 5 * (N - 2) * (N - 2) + 4 * (N - 2);
    edge_num = 8 * (N - 2) + 4;
    corner_num = 4;
    cout << center * center_num + edge * edge_num + corner * corner_num << endl;
    return 0;
}