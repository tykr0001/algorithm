#include <iostream>
#include <vector>

using namespace std;

int N;
int S, G, P, D;   // 0 < S < G < P < D <= 50000
int answer;
int max_money;

string grade;
vector<int> dp;   // dp[i] : i-1번째 달에서 과금할 수 있는 최대금액

int main(void) {
    cin >> N >> S >> G >> P >> D >> grade;
    dp.resize(N, 0);
    
    for (int i = 0; i < N; ++i) {
        int max_money = 0;
        if (grade[i] == 'B')
            max_money = S - 1;
        if (grade[i] == 'S')
            max_money = G - 1;
        if (grade[i] == 'G')
            max_money = P - 1;
        if (grade[i] == 'P')
            max_money = D - 1;
        if (grade[i] == 'D') {
            dp[i] = D;
            continue;
        }
        if (dp[i - 1] > max_money) {
            dp[i - 1] = max_money;
            dp[i] = 0;
        }
        else {
            dp[i] = max_money - dp[i - 1];
        }
    }
    for (int i = 0; i < N; ++i) {
        answer += dp[i];
    }

    cout << answer << endl;

    return 0;
}