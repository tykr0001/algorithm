#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <limits>

using namespace std;

int N;
int S, G, P, D;   // 0 < S < G < P < D <= 50000
int answer;
int max_money;
int min_money;

string grade;
vector<vector<tuple<int, int>>> dp;   // dp[i][j] => i-1번째 달까지, <당월 j원 과금, 누적 과금액>

// @return : tuple<min_money, max_money>
tuple<int, int> SetBorder(char grade) {
    if (grade == 'B') {
        return make_tuple(0, S - 1);
    }
    else if (grade == 'S') {
        return make_tuple(S, G - 1);
    }
    else if (grade == 'G') {
        return make_tuple(G, P - 1);
    }
    else if (grade == 'P') {
        return make_tuple(P, D - 1);
    }
    else {
        return make_tuple(D, D);
    }
}

int main(void) {
    cin >> N >> S >> G >> P >> D >> grade;
    dp.resize(N);
    tie(min_money, max_money) = SetBorder(grade[0]);
    dp[0].resize(max_money + 1, make_tuple(0, 0));
    for (int i = 0; i <= max_money; ++i) {
        get<0>(dp[0][i]) = i;
        get<1>(dp[0][i]) = i;
    }
    for (int i = 1; i < N; ++i) {
        tie(min_money, max_money) = SetBorder(grade[i]);
        dp[i].resize(max_money + 1, make_tuple(0, 0));
        for (int j = 0; j <= max_money; ++j) {
            for (int k = 0; k < dp[i - 1].size(); ++k) {
                if (min_money <= get<0>(dp[i - 1][k]) + j && get<0>(dp[i - 1][k]) + j <= (max_money == D ? INT32_MAX : max_money)) {
                    dp[i][j] = make_tuple(j, max(get<1>(dp[i][j]), j + get<1>(dp[i - 1][k])));
                }
            }
        }
    }

    for (int i = 0; i < dp[N - 1].size(); ++i) {
        answer = max(answer, get<1>(dp[N - 1][i]));
    }

    // debug
    for(int i=0; i < dp.size(); ++i){
        for(int j=0; j < dp[i].size(); ++j){
            cout << get<0>(dp[i][j]) << " " << get<1>(dp[i][j]) << endl;
        }
        cout << endl;
    }

    cout << answer << endl;
    return 0;
}