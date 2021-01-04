#include <iostream>
#include <vector>

using namespace std;

int N;
int S, G, P, D;
int sum;
int money;
string grade;

// 0 < S < G < P < D <= 500
int main(void) {
    cin >> N >> S >> G >> P >> D >> grade;
    for (int i = 0; i < N; ++i) {
        if (grade[i] == 'B') {
            sum += S - 1 - money;
            money = S - 1 - money;
        }
        else if (grade[i] == 'S') {
            sum += G - 1 - money;
            money = G - 1 - money;
        }
        else if (grade[i] == 'G') {
            sum += P - 1 - money;
            money = P - 1 - money;
        }
        else if (grade[i] == 'P') {
            sum += D - 1 - money;
            money = D - 1 - money;
        }
        else {
            sum += D;
            money = D;
        }
    }
    cout << sum << endl;
}